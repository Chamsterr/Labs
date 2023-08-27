DECLARE loanTypeCursor CURSOR FOR
SELECT Название_вида_кредита 
FROM Loan_type

DECLARE @loanType NVARCHAR(50)
DECLARE @N NVARCHAR(2) = CHAR(13) + CHAR(10);
DECLARE @ResultText NVARCHAR(1000) = 'Список видов кредита:' + @N;

OPEN loanTypeCursor;
	FETCH NEXT FROM loanTypeCursor INTO @loanType;
	SET @ResultText = @ResultText + @loanType + @N;
	WHILE @@FETCH_STATUS = 0
		BEGIN
			SET @ResultText = @ResultText + @loanType + @N;
			FETCH NEXT FROM loanTypeCursor INTO @loanType;
		END;
CLOSE loanTypeCursor;
DEALLOCATE loanTypeCursor;

PRINT @ResultText

-----------------------------------------------------------------------

DECLARE loanCursor CURSOR LOCAL FOR SELECT id, Сумма FROM Loans;
DECLARE @id INT, @sum REAL;

OPEN loanCursor;
FETCH NEXT FROM loanCursor INTO @id, @sum;
PRINT '1. ID: ' + CAST(@id AS NVARCHAR(50)) + ', Сумма: ' + CAST(@sum AS NVARCHAR(50));

FETCH NEXT FROM loanCursor INTO @id, @sum;
PRINT '2. ID: ' + CAST(@id AS NVARCHAR(50)) + ', Сумма: ' + CAST(@sum AS NVARCHAR(50));

CLOSE loanCursor;

-----------------------------------------------------------------------
--Динамический курсор 
DECLARE loanDynamicCursor CURSOR LOCAL DYNAMIC FOR SELECT id, Сумма FROM Loans;
DECLARE @id INT, @sum REAL;

OPEN loanDynamicCursor;
FETCH NEXT FROM loanDynamicCursor INTO @id, @sum;
PRINT 'ID: ' + CAST(@id AS NVARCHAR(50)) + ', Сумма: ' + CAST(@sum AS NVARCHAR(50));

UPDATE Loans SET Сумма = Сумма + 1000 WHERE id = @id;

FETCH NEXT FROM loanDynamicCursor INTO @id, @sum;
PRINT 'ID: ' + CAST(@id AS NVARCHAR(50)) + ', Сумма: ' + CAST(@sum AS NVARCHAR(50));

CLOSE loanDynamicCursor;
-------------------------------------------------------------------------

-------------------------------------------------------------------------
--Scroll
DECLARE loanScrollCursor CURSOR LOCAL DYNAMIC SCROLL FOR SELECT id, Сумма FROM Loans;
DECLARE @id INT, @sum REAL;

OPEN loanScrollCursor;
FETCH NEXT FROM loanScrollCursor INTO @id, @sum;
PRINT 'Первая выбранная строка: ID: ' + CAST(@id AS NVARCHAR(50)) + ', Сумма: ' + CAST(@sum AS NVARCHAR(50));

FETCH LAST FROM loanScrollCursor INTO @id, @sum;
PRINT 'Последняя строка: ID: ' + CAST(@id AS NVARCHAR(50)) + ', Сумма: ' + CAST(@sum AS NVARCHAR(50));

CLOSE loanScrollCursor;

-------------------------------------------------------------------------

------------------------------------------------------------------------
CREATE TABLE #Clients (
    id INT PRIMARY KEY,
    Название_фирмы NVARCHAR(50),
    Вид_собственности NVARCHAR(50) NOT NULL,
    Адрес NVARCHAR(50) NOT NULL,
    Телефон NVARCHAR(50),
    Контактноe_лицо NVARCHAR(50)
);

INSERT INTO #Clients (id, Название_фирмы, Вид_собственности, Адрес, Телефон, Контактноe_лицо)
VALUES (1, 'Firma 1', 'OOO', 'Adress 1', '123456789', 'Person 1'),
       (2, 'Firma 2', 'AO', 'Adress 2', '234567890', 'Person 2');

DECLARE @ClientID INT;
DECLARE @ClientName NVARCHAR(50);

DECLARE ClientCursor CURSOR FOR
SELECT id, Название_фирмы
FROM #Clients
WHERE Вид_собственности = 'OOO';

-- Открытие курсора
OPEN ClientCursor;

FETCH NEXT FROM ClientCursor INTO @ClientID, @ClientName;
WHILE @@FETCH_STATUS = 0
BEGIN
    PRINT @ClientName;
    FETCH NEXT FROM ClientCursor INTO @ClientID, @ClientName;
END;

CLOSE ClientCursor;
DEALLOCATE ClientCursor;

SELECT *
FROM #Clients;

------------------------------------------------------------------------

--6-1
DECLARE LoanCursor CURSOR FOR
SELECT Loans.id
FROM Loans
JOIN  Loan_type ON Loans.Код_вида = Loan_type.id
WHERE Сумма < 50000;

DECLARE @LoanID int; 

OPEN LoanCursor
    FETCH NEXT FROM LoanCursor INTO @LoanID
    PRINT @LoanID
    WHILE @@FETCH_STATUS = 0
    BEGIN
        FETCH NEXT FROM LoanCursor INTO @LoanID
        PRINT @LoanID
        DELETE FROM Loans
        WHERE CURRENT OF LoanCursor;
    END
    SELECT *
    FROM Loans
    JOIN  Loan_type ON Loans.Код_вида = Loan_type.id
CLOSE LoanCursor

--6-2

go

DECLARE @loan_id INT;

DECLARE Loan CURSOR LOCAL DYNAMIC FOR
    SELECT Loans.id
    FROM Loans
    JOIN Clients ON Clients.id = Loans.Код_клиента
    WHERE Loans.Код_клиента = 1;

OPEN Loan;

FETCH NEXT FROM Loan INTO @loan_id;
    WHILE @@FETCH_STATUS = 0
    BEGIN
        UPDATE Loans SET Сумма = Сумма + 1000 WHERE CURRENT OF Loan;
        PRINT 'Loan sum updated';
        FETCH NEXT FROM Loan INTO @loan_id;
    END
CLOSE Loan;

DEALLOCATE Loan;
