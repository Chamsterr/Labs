-----------------------------1--------------------------
SELECT Loans.���_����, SUM(Loans.�����)
FROM Loans
WHERE Loans.���_���� IN (1, 2)
GROUP BY ROLLUP (Loans.���_����, Loans.�����)
--------------------------------------------------------

-----------------------------2--------------------------
SELECT Loans.���_����, SUM(Loans.�����)
FROM Loans
WHERE Loans.���_���� IN (1, 2)
GROUP BY CUBE(Loans.���_����)

--------------------------------------------------------

-----------------------------3--------------------------
SELECT Clients.��������_�����, ROUND(AVG(CAST(Loans.����� AS float(4))), 2)
FROM Loan_type
	JOIN Loans ON Loans.���_���� = Loan_type.id
	JOIN Clients ON Loans.���_������� = Clients.id
WHERE Clients.id = 3
GROUP BY Clients.��������_�����
UNION
SELECT Clients.��������_�����, ROUND(AVG(CAST(Loans.����� AS float(4))), 2)
FROM Loan_type
	JOIN Loans ON Loans.���_���� = Loan_type.id
	JOIN Clients ON Loans.���_������� = Clients.id
WHERE Clients.id = 1
GROUP BY Clients.��������_�����

SELECT Clients.��������_�����, ROUND(AVG(CAST(Loans.����� AS float(4))), 2)
FROM Loan_type
	JOIN Loans ON Loans.���_���� = Loan_type.id
	JOIN Clients ON Loans.���_������� = Clients.id
WHERE Clients.id = 3
GROUP BY Clients.��������_�����
UNION ALL
SELECT Clients.��������_�����, ROUND(AVG(CAST(Loans.����� AS float(4))), 2)
FROM Loan_type
	JOIN Loans ON Loans.���_���� = Loan_type.id
	JOIN Clients ON Loans.���_������� = Clients.id
WHERE Clients.id = 1
GROUP BY Clients.��������_�����
-------------------------------------------------------

-----------------------------4-5--------------------------
SELECT Clients.��������_�����, ROUND(AVG(CAST(Loans.����� AS float(4))), 2)
FROM Loan_type
	JOIN Loans ON Loans.���_���� = Loan_type.id
	JOIN Clients ON Loans.���_������� = Clients.id
WHERE Clients.id = 3
GROUP BY Clients.��������_�����
INTERSECT
SELECT Clients.��������_�����, ROUND(AVG(CAST(Loans.����� AS float(4))), 2)
FROM Loan_type
	JOIN Loans ON Loans.���_���� = Loan_type.id
	JOIN Clients ON Loans.���_������� = Clients.id
WHERE Clients.id = 1
GROUP BY Clients.��������_�����

SELECT Clients.��������_�����, ROUND(AVG(CAST(Loans.����� AS float(4))), 2)
FROM Loan_type
	JOIN Loans ON Loans.���_���� = Loan_type.id
	JOIN Clients ON Loans.���_������� = Clients.id
WHERE Clients.id = 3
GROUP BY Clients.��������_�����
EXCEPT
SELECT Clients.��������_�����, ROUND(AVG(CAST(Loans.����� AS float(4))), 2)
FROM Loan_type
	JOIN Loans ON Loans.���_���� = Loan_type.id
	JOIN Clients ON Loans.���_������� = Clients.id
WHERE Clients.id = 1
GROUP BY Clients.��������_�����
--------------------------------------------------------	