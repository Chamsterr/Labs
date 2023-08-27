-------------------------------------1----------------------------------------
SELECT *
FROM Loans, Clients
WHERE Loans.���_������� = Clients.id and Loans.���_���� in (SELECT Loan_type.id
						    FROM Loan_type)
------------------------------------------------------------------------------

-------------------------------------2----------------------------------------
SELECT *
FROM Loans 
INNER JOIN Clients ON Loans.���_������� = Clients.id
WHERE Loans.���_���� in (SELECT Loan_type.id FROM Loan_type)
------------------------------------------------------------------------------

-------------------------------------3----------------------------------------
SELECT *
FROM Loans 
INNER JOIN Clients ON Loans.���_������� = Clients.id
INNER JOIN Loan_type ON Loans.���_���� = Loan_type.id
------------------------------------------------------------------------------

-------------------------------------4----------------------------------------
SELECT Loans.�����, Loans.���_����
FROM Loans
WHERE ���_������� = (SELECT TOP(1) ���_�������
							FROM Loans Lloans 
							WHERE Loans.���_���� = Lloans.���_����
							ORDER BY ����� DESC)

------------------------------------------------------------------------------

-------------------------------------5----------------------------------------

SELECT Clients.id
FROM Clients
WHERE not exists (SELECT *
				  FROM Loans 
				  WHERE Loans.���_������� = Clients.id)

------------------------------------------------------------------------------

-------------------------------------6----------------------------------------
SELECT top 1
	(SELECT AVG(Loans.�����) 
	 FROM Loans
	 WHERE Loans.���_���� = 1),
	(SELECT AVG(Loans.�����) 
	 FROM Loans
	 WHERE Loans.���_���� = 2),
	 (SELECT AVG(Loans.�����) 
	 FROM Loans
	 WHERE Loans.���_���� = 3)
FROM Loans
------------------------------------------------------------------------------

-------------------------------------7----------------------------------------
SELECT Loans.�����, Loans.���_����
FROM Loans
WHERE Loans.����� >= all(SELECT Loans.�����
						 FROM Loans 
						 WHERE Loans.���_���� = 2)
------------------------------------------------------------------------------

-------------------------------------8----------------------------------------
SELECT Loans.�����, Loans.���_����
FROM Loans
WHERE Loans.����� <= any(SELECT Loans.�����
						 FROM Loans 
						 WHERE Loans.���_���� = 2)
------------------------------------------------------------------------------