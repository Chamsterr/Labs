CREATE PROCEDURE PSUBJECT
	AS
	BEGIN
		DECLARE @K INT = (SELECT COUNT(*) FROM SUBJECT)
		SELECT * FROM SUBJECT
		RETURN @K;
	END

DECLARE @K2 INT = 0;
EXEC @K2 = PSUBJECT;
PRINT @K2

-----------------2-----------------
SELECT *
FROM PULPIT

DECLARE @K3 INT = 0;
EXEC PSUBJECT @p = 'ИСиТ', @K = @K3 OUTPUT;
PRINT @K3
-----------------------------------

-----------------3-----------------
CREATE PROCEDURE PSUBJECT_FOR_3
	AS
	BEGIN
		SELECT * 
		FROM SUBJECT
	END

CREATE TABLE #COPY_SUBJECT (КОД CHAR(10) NOT NULL,
							НАЗВАНИЕ_ПРЕДМЕТА  VARCHAR(100) NULL,
							КАФЕДРА CHAR(20) NULL)

INSERT #COPY_SUBJECT EXEC PSUBJECT_FOR_3 @p = 'ИСиТ'

select * from #COPY_SUBJECT
-----------------------------------


-----------------4-----------------
SELECT *
FROM AUDITORIUM

ALTER PROCEDURE PAUDITORIUM_INSERT
	@a CHAR(20),
	@n VARCHAR(50),
	@c INT = 0,
	@t CHAR(10)
	AS
	BEGIN
		BEGIN TRY
			INSERT INTO AUDITORIUM (AUDITORIUM, AUDITORIUM_NAME, AUDITORIUM_CAPACITY, AUDITORIUM_TYPE) VALUES(@a, @n, @c, @t)
			return 1
		END TRY
		BEGIN CATCH
			PRINT 'Номер ошибки' + cast(error_number() as varchar(6))
			PRINT 'Сообщение' + error_message();
			PRINT 'Уровень ' + cast(error_severity() as varchar(6));
			PRINT 'Метка' + cast(error_state() as varchar(8));
			PRINT 'Номер строки ' + cast(error_line() as varchar(8));
			IF ERROR_PROCEDURE() is not null
			PRINT 'Имя процедуры' + error_procedure();
			return -1;
		END CATCH
	END

declare @rc int;
exec @rc = PAUDITORIUM_INSERT @a = '205-1', @n='205-1', @c=90, @t = 'ЛР-КK     '
PRINT @RC
-----------------------------------

-----------------5-----------------
ALTER PROCEDURE SUBJECT_REPORT
	@p varchar(20)
	AS
	BEGIN
		BEGIN TRY
			IF CURSOR_STATUS('global','subjectCursor') >= 0
			BEGIN
				CLOSE subjectCursor
				DEALLOCATE subjectCursor
			END

			DECLARE subjectCursor CURSOR LOCAL  FOR 
										 SELECT SUBJECT
										 FROM SUBJECT
										 WHERE PULPIT = @p
			IF NOT EXISTS (SELECT SUBJECT
								  FROM SUBJECT
								  WHERE PULPIT = @p)
				RAISERROR ('ошибка в параметрах', 11, 1)
			else
				begin
					open subjectCursor
								DECLARE @SUBJECT VARCHAR(30)
			DECLARE @RESULT_TEXT VARCHAR(500) = 'Отчет:' + char(10)
						fetch subjectCursor into @SUBJECT
						SET @RESULT_TEXT = @RESULT_TEXT + RTRIM(@SUBJECT) + CHAR(10)
						WHILE @@FETCH_STATUS = 0
						BEGIN
							fetch subjectCursor into @SUBJECT
							SET @RESULT_TEXT = @RESULT_TEXT + RTRIM(@SUBJECT) + CHAR(10)
						END
						PRINT @RESULT_TEXT
					CLOSE subjectCursor
										DEALLOCATE subjectCursor
				end
		END TRY
		BEGIN CATCH
			    SELECT 
        ERROR_NUMBER() AS ErrorNumber,
        ERROR_SEVERITY() AS ErrorSeverity,
        ERROR_STATE() as ErrorState,
        ERROR_PROCEDURE() as ErrorProcedure,
        ERROR_LINE() as ErrorLine,
        ERROR_MESSAGE() as ErrorMessage;
		END CATCH
	END

DECLARE @pP varchar(20) = 'ИСиТ'

SELECT SUBJECT
FROM SUBJECT
WHERE PULPIT = 'ИСиТ'

exec SUBJECT_REPORT @p = 'ИСиТ'
-----------------------------------

-----------------6-----------------
CREATE PROCEDURE PAUDITORIUM_INSERTX
	@a CHAR(20),
	@n VARCHAR(50),
	@c INT = 0,
	@t CHAR(10),
	@tn VARCHAR(50)
	AS
	BEGIN
		BEGIN TRY
			SET TRANSACTION ISOLATION LEVEL SERIALIZABLE
			BEGIN TRAN
				INSERT INTO AUDITORIUM_TYPE(AUDITORIUM_TYPE, AUDITORIUM_TYPENAME)
				VALUES (@t, @tn)
				EXEC PAUDITORIUM_INSERT @a = @a, @n=@n, @c=@c, @t = @t
			commit TRAN
		END TRY
		begin catch
			print 'Код ошибки:  ' + cast(ERROR_NUMBER() as varchar)
			print 'Серьёзность: ' + cast(ERROR_SEVERITY() as varchar)
			print 'Сообщение:   ' + cast(ERROR_MESSAGE() as varchar)
			if @@TRANCOUNT > 0 
				rollback tran
			return -1
		end catch
	END

	select * from AUDITORIUM
	select * from AUDITORIUM_TYPE

	--delete AUDITORIUM where AUDITORIUM = '325-1'
	--delete AUDITORIUM_TYPE where AUDITORIUM_TYPE = 'ЛР-К'


exec PAUDITORIUM_INSERTX @a = '325-1', @n = '325-1', @c = 50, @t = 'ЛР-КKK', @tn = 'Лабораторный кабинет'
drop proc PAUDITORIUM_INSERTX 
-----------------------------------