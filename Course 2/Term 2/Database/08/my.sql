-----------------------1-------------------------
CREATE VIEW [����_�������] AS 
	 SELECT id [���],
			  ��������_����_������� [���_�������],
			  ������ [������]
	   FROM Loan_type

SELECT *
FROM [����_�������]
-------------------------------------------------

-----------------------2-------------------------

CREATE VIEW [�������_������_�����_��������_����_������_������] 
AS SELECT Loans.���_������� [���_�������], COUNT(���_����) [���-��]
	FROM Loans
		INNER JOIN Loan_type ON Loan_type.id = Loans.���_����
	GROUP BY Loans.���_�������

SELECT *
FROM �������_������_�����_��������_����_������_������

-------------------------------------------------

-----------------------3-------------------------
ALTER VIEW [��������_���_�������](id, ��������_����_�������, ������)
	AS SELECT Loan_type.id [id],
			  Loan_type.��������_����_������� [��������_����_�������],
			  Loan_type.������ [������]
	FROM Loan_type
	WHERE Loan_type.������ > 250;


SELECT *
FROM ��������_���_�������

INSERT ��������_���_������� VALUES('4', '�������', 500)
DELETE ��������_���_������� WHERE id = '4'
-------------------------------------------------

-----------------------4-------------------------
ALTER VIEW [��������_���_�������](id, ��������_����_�������, ������)
	AS SELECT Loan_type.id [id],
			  Loan_type.��������_����_������� [��������_����_�������],
			  Loan_type.������ [������]
	FROM Loan_type
	WHERE Loan_type.������ > 250 WITH CHECK OPTION


SELECT *
FROM ��������_���_�������

INSERT ��������_���_������� VALUES('5', '�������', 249)
UPDATE ��������_���_������� SET id = 5 WHERE ������ = 255
DELETE ��������_���_������� WHERE id = '5'
-------------------------------------------------

-----------------------5-------------------------
CREATE VIEW [������_�������]
	AS SELECT TOP(2) Clients.��������_����� [��������_�����], Clients.id [id]
	   FROM Clients
	   ORDER BY ��������_�����

SELECT * FROM ������_�������
-------------------------------------------------

-----------------------6-------------------------
CREATE VIEW [�������_������_�����_��������_����_������_������_2] WITH  SCHEMABINDING
AS SELECT Loans.���_������� [���_�������], COUNT(Loans.���_����) [���-��]
	FROM dbo.Loans
		INNER JOIN dbo.Loan_type ON Loan_type.id = Loans.���_����
	GROUP BY Loans.���_�������

SELECT * FROM �������_������_�����_��������_����_������_������_2
-------------------------------------------------