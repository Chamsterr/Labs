SELECT *
FROM Loans
JOIN Loan_type ON Loans.���_���� = Loan_type.id
---------------------------------------------------

SELECT *
FROM Loans
JOIN Loan_type ON Loan_type.id = Loans.���_���� and ��������_����_������� LIKE ('���%')
---------------------------------------------------

SELECT ���������e_����, �������,
case
	when ���_������������� like ('���%') then '�������'
	else '...'
end as [�����������]
FROM Loans
JOIN Loan_type ON Loan_type.id = Loans.���_����
JOIN Clients ON Clients.id = Loans.���_�������

---------------------------------------------------
SELECT *
FROM Loans
FULL JOIN Loan_type ON Loans.id = Loan_type.id

SELECT *
FROM Loan_type
FULL JOIN Loans ON Loans.id = Loan_type.id


SELECT *
FROM Loan_type
FULL OUTER JOIN Loans ON Loans.id = Loan_type.id
WHERE Loan_type.id  is  null

SELECT *
FROM Loan_type
FULL OUTER JOIN Loans ON Loans.id = Loan_type.id
WHERE Loans.id is NOT null

---------------------------------------------------

INSERT INTO Loans(ID, ���_����, ���_�������, �����, ����_��������, ����_������, test2) VALUES (6, 2, 3, 321313, '2023-03-18', '2023-05-05', NULL)

SELECT ISNULL(test2, 'pp') AS [������_�����], Loans.�����
FROM Loans
---------------------------------------------------

SELECT *
FROM Loans CROSS JOIN Loan_type
WHERE Loans.���_���� = Loan_type.id