CREATE INDEX idx_Clients_id
ON Clients (id);

CREATE INDEX idx_Loan_type_id
ON Loan_type (id);

CREATE INDEX idx_Loans_Kod_vida_Kod_klienta
ON Loans (���_����, ���_�������);

SELECT *
FROM Clients
WHERE id = 10;

SELECT *
FROM Loan_type
WHERE id = 5;


SELECT *
FROM Loans
WHERE ���_���� = 3 AND ���_������� = 10;


SELECT *
FROM Loans
INNER JOIN Loan_type ON Loans.���_���� = Loan_type.id
INNER JOIN Clients ON Loans.���_������� = Clients.id;

CREATE CLUSTERED INDEX IDX_Clients_��������_����� 
ON dbo.Clients(��������_�����);

CREATE INDEX IDX_Loan_type_������ 
ON dbo.Loan_type(������);

CREATE INDEX IDX_Loans_���_����_INCLUDE 
ON dbo.Loans(���_����) 
INCLUDE (����_��������, ����_������, �����);

CREATE INDEX IDX_Loans_�����_Filter 
ON dbo.Loans(�����) 
WHERE ����� > 10000;

CREATE INDEX IDX_Loan_type_������_FillFactor 
ON dbo.Loan_type(������) 
WITH (FILLFACTOR = 65);

CREATE INDEX IDX_Clients_����� 
ON dbo.Clients(�����);

ALTER INDEX IDX_Clients_����� ON dbo.Clients REORGANIZE;
