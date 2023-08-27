BEGIN TRY
    BEGIN TRANSACTION AddClient

        DECLARE @PhoneNumber nvarchar(50) = 'Телефон 102';

        IF NOT EXISTS (SELECT * FROM Clients WHERE Телефон = @PhoneNumber)
        BEGIN
            INSERT INTO Clients (id, Название_фирмы, Вид_собственности, Адрес, Телефон, Контактноe_лицо)
            VALUES (102, 'Название_фирмы 102', 'Вид_собственности 102', 'Адрес 102', @PhoneNumber, 'Контактное лицо 102')
        END
        ELSE
        BEGIN
            THROW 51000, 'Клиент с таким номером телефона уже существует.', 1
        END

    COMMIT TRANSACTION AddClient
END TRY
BEGIN CATCH
    IF @@TRANCOUNT > 0
        ROLLBACK TRANSACTION AddClient

    PRINT 'Ошибка: ' + ERROR_MESSAGE()
END CATCH

----------------------------------------

BEGIN TRY
    BEGIN TRANSACTION UpdateLoanType

        DECLARE @NewRate real = 5.0;
        DECLARE @LoanTypeID int = 2;

        IF (SELECT Ставка FROM Loan_type WHERE id = @LoanTypeID) < @NewRate
        BEGIN
            UPDATE Loan_type
            SET Ставка = @NewRate
            WHERE id = @LoanTypeID
        END
        ELSE
        BEGIN
            THROW 51000, 'Текущая ставка выше или равна новой ставке.', 1
        END

    COMMIT TRANSACTION UpdateLoanType
END TRY
BEGIN CATCH
    IF @@TRANCOUNT > 0
        ROLLBACK TRANSACTION UpdateLoanType

    PRINT 'Ошибка: ' + ERROR_MESSAGE()
END CATCH

--------------------------------------------

BEGIN TRY
    BEGIN TRANSACTION DeleteLoan

        DECLARE @LoanID int = 3;
        DECLARE @MinAmount real = 5000.0;

        IF (SELECT Сумма FROM Loans WHERE id = @LoanID) > @MinAmount
        BEGIN
            DELETE FROM Loans
            WHERE id = @LoanID
        END
        ELSE
        BEGIN
            THROW 51000, 'Сумма кредита меньше минимального значения.', 1
        END

    COMMIT TRANSACTION DeleteLoan
END TRY
BEGIN CATCH
    IF @@TRANCOUNT > 0
        ROLLBACK TRANSACTION DeleteLoan

    PRINT 'Ошибка: ' + ERROR_MESSAGE()
END CATCH
