BEGIN TRY
    BEGIN TRANSACTION AddClient

        DECLARE @PhoneNumber nvarchar(50) = '������� 102';

        IF NOT EXISTS (SELECT * FROM Clients WHERE ������� = @PhoneNumber)
        BEGIN
            INSERT INTO Clients (id, ��������_�����, ���_�������������, �����, �������, ���������e_����)
            VALUES (102, '��������_����� 102', '���_������������� 102', '����� 102', @PhoneNumber, '���������� ���� 102')
        END
        ELSE
        BEGIN
            THROW 51000, '������ � ����� ������� �������� ��� ����������.', 1
        END

    COMMIT TRANSACTION AddClient
END TRY
BEGIN CATCH
    IF @@TRANCOUNT > 0
        ROLLBACK TRANSACTION AddClient

    PRINT '������: ' + ERROR_MESSAGE()
END CATCH

----------------------------------------

BEGIN TRY
    BEGIN TRANSACTION UpdateLoanType

        DECLARE @NewRate real = 5.0;
        DECLARE @LoanTypeID int = 2;

        IF (SELECT ������ FROM Loan_type WHERE id = @LoanTypeID) < @NewRate
        BEGIN
            UPDATE Loan_type
            SET ������ = @NewRate
            WHERE id = @LoanTypeID
        END
        ELSE
        BEGIN
            THROW 51000, '������� ������ ���� ��� ����� ����� ������.', 1
        END

    COMMIT TRANSACTION UpdateLoanType
END TRY
BEGIN CATCH
    IF @@TRANCOUNT > 0
        ROLLBACK TRANSACTION UpdateLoanType

    PRINT '������: ' + ERROR_MESSAGE()
END CATCH

--------------------------------------------

BEGIN TRY
    BEGIN TRANSACTION DeleteLoan

        DECLARE @LoanID int = 3;
        DECLARE @MinAmount real = 5000.0;

        IF (SELECT ����� FROM Loans WHERE id = @LoanID) > @MinAmount
        BEGIN
            DELETE FROM Loans
            WHERE id = @LoanID
        END
        ELSE
        BEGIN
            THROW 51000, '����� ������� ������ ������������ ��������.', 1
        END

    COMMIT TRANSACTION DeleteLoan
END TRY
BEGIN CATCH
    IF @@TRANCOUNT > 0
        ROLLBACK TRANSACTION DeleteLoan

    PRINT '������: ' + ERROR_MESSAGE()
END CATCH
