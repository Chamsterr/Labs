---------------------------------------1-----------------------------------------
--Loans_type
--Loans

SELECT Loan_type.��������_����_�������, MAX(Loans.�����) AS [������������ �����], MIN(Loans.�����) AS [����������� �����], 
	   AVG(Loans.�����) AS [������� ����], COUNT(Loans.id) AS [���-�� �������� ������� ����]
FROM Loans
	INNER JOIN Loan_type ON Loan_type.id = Loans.���_����
GROUP BY Loan_type.��������_����_�������
---------------------------------------------------------------------------------

---------------------------------------3-----------------------------------------

SELECT *
FROM (SELECT CASE
				WHEN Loans.����� between 1000 and 3000 then '1000-3000'
				ELSE '������ ����'
			 END [������� ���], COUNT(*) as [���-��]
	  FROM Loans GROUP BY CASE
							  WHEN Loans.����� between 1000 and 3000 THEN '1000-3000'
							  ELSE '������ ����'
						   END) as T

---------------------------------------------------------------------------------

---------------------------------------4-----------------------------------------

SELECT Loan_type.��������_����_�������, ROUND(AVG(CAST(Loans.����� AS float(4))), 2)
FROM Loan_type
	JOIN Loans ON Loans.���_���� = Loan_type.id
GROUP BY Loan_type.��������_����_�������
	

---------------------------------------------------------------------------------


---------------------------------------5-----------------------------------------

SELECT Loan_type.��������_����_�������, ROUND(AVG(CAST(Loans.����� AS float(4))), 2)
FROM Loan_type
	JOIN Loans ON Loans.���_���� = Loan_type.id
WHERE Loan_type.��������_����_������� in ('�������', '������')
GROUP BY Loan_type.��������_����_�������
	
---------------------------------------------------------------------------------

---------------------------------------6-----------------------------------------

SELECT Clients.��������_�����, ROUND(AVG(CAST(Loans.����� AS float(4))), 2)
FROM Loan_type
	JOIN Loans ON Loans.���_���� = Loan_type.id
	JOIN Clients ON Loans.���_������� = Clients.id
WHERE Clients.id = 3
GROUP BY Clients.��������_�����
	
---------------------------------------------------------------------------------

---------------------------------------7-----------------------------------------

SELECT Loans.���_����, Loans.�����,
	   (SELECT DISTINCT COUNT(*)
		FROM Loans AS L2
		WHERE Loans.���_���� = L2.���_���� AND Loans.����� = L2.�����) [���-��]
FROM Loans
GROUP BY Loans.���_����, Loans.�����
HAVING Loans.����� > 9999 AND Loans.����� < 50000

---------------------------------------------------------------------------------