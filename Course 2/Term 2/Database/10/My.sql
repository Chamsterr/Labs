CREATE INDEX idx_Clients_id
ON Clients (id);

CREATE INDEX idx_Loan_type_id
ON Loan_type (id);

CREATE INDEX idx_Loans_Kod_vida_Kod_klienta
ON Loans (Код_вида, Код_клиента);

SELECT *
FROM Clients
WHERE id = 10;

SELECT *
FROM Loan_type
WHERE id = 5;


SELECT *
FROM Loans
WHERE Код_вида = 3 AND Код_клиента = 10;


SELECT *
FROM Loans
INNER JOIN Loan_type ON Loans.Код_вида = Loan_type.id
INNER JOIN Clients ON Loans.Код_клиента = Clients.id;

CREATE CLUSTERED INDEX IDX_Clients_Название_фирмы 
ON dbo.Clients(Название_фирмы);

CREATE INDEX IDX_Loan_type_Ставка 
ON dbo.Loan_type(Ставка);

CREATE INDEX IDX_Loans_Код_вида_INCLUDE 
ON dbo.Loans(Код_вида) 
INCLUDE (Дата_возврата, Дата_выдачи, Сумма);

CREATE INDEX IDX_Loans_Сумма_Filter 
ON dbo.Loans(Сумма) 
WHERE Сумма > 10000;

CREATE INDEX IDX_Loan_type_Ставка_FillFactor 
ON dbo.Loan_type(Ставка) 
WITH (FILLFACTOR = 65);

CREATE INDEX IDX_Clients_Адрес 
ON dbo.Clients(Адрес);

ALTER INDEX IDX_Clients_Адрес ON dbo.Clients REORGANIZE;
