----------------------1----------------------
DECLARE @Char char(1) = 'c',
		@Varchar varchar(4) = 'БГТУ',
		@Datetime datetime = getdate(),
		@Time time,
		@Int int,
		@Smallint smallint,
		@Numeric numeric(12, 5);

SELECT @Char c, @Varchar v

SET @Char = 'b';
SET @Varchar = 'ПГТУ';

SELECT @Char = 'd', @Varchar = 'ВГТУ', @Int = 5, @Smallint = 1, @Numeric = 1234567.12345
SELECT @Char c, @Varchar v

PRINT 'Int = ' + cast(@Int as varchar(5)); 
-------------------------------------------

----------------------2----------------------
DECLARE @Общая_вместимость int = (SELECT SUM(AUDITORIUM.AUDITORIUM_CAPACITY)
								  FROM AUDITORIUM),
		@Кол_во_аудиторий_меньше_ср int ,
		@Средняя_вместимость int
IF @Общая_вместимость > 200
BEGIN
	SELECT @Средняя_вместимость = AVG(AUDITORIUM_CAPACITY) FROM AUDITORIUM;
    SELECT @Кол_во_аудиторий_меньше_ср = COUNT(*) FROM AUDITORIUM WHERE AUDITORIUM_CAPACITY < @Средняя_вместимость;
END

SELECT @Средняя_вместимость, @Кол_во_аудиторий_меньше_ср
---------------------------------------------

----------------------3----------------------
PRINT @@ROWCOUNT
PRINT @@VERSION
PRINT @@SPID
PRINT @@ERROR
PRINT @@SERVERNAME
PRINT @@TRANCOUNT
PRINT @@FETCH_STATUS
PRINT @@NESTLEVEL
---------------------------------------------

----------------------4----------------------
	------------------1-------------------
	DECLARE @Z INT, @T INT = 5, @X INT = 7;
	IF @T > @X
	BEGIN
		SET @Z = POWER(SIN(@T), 2);
	END
	ELSE IF @T < @x
	BEGIN
		SET @Z = 4*(@T + @X)
	END
	ELSE IF @T = @x
	BEGIN
		SET @Z = 1 - EXP(@X-2)
	END

	PRINT @Z
	---------------------------------------	

	-------------------2-------------------
	DECLARE @FIO VARCHAR(50) = (SELECT TOP(1) NAME FROM STUDENT),
	        @Family_IO VARCHAR(50);
	SELECT value FROM STRING_SPLIT(@FIO, ' ')
	SET @Family_IO = CONVERT(VARCHAR(25), (SELECT top(1) value FROM STRING_SPLIT(@FIO, ' '))) + ' ' + SUBSTRING((SELECT TOP(2) value FROM STRING_SPLIT(@FIO, ' ') EXCEPT SELECT TOP(1) value FROM STRING_SPLIT(@FIO, ' ') ), 1, 1) + ' ' + SUBSTRING((SELECT TOP(3) value FROM STRING_SPLIT(@FIO, ' ') EXCEPT SELECT TOP(2) value FROM STRING_SPLIT(@FIO, ' ') ), 1, 1)

	PRINT @Family_IO
	---------------------------------------

	-------------------3-------------------
	DECLARE @next_month int = MONTH(GETDATE()) + 1;
	select * from STUDENT where MONTH(STUDENT.BDAY) = @next_month;

	---------------------------------------

	-------------------4-------------------
	select CASE
		when DATEPART(weekday, PDATE) = 1 then 'Понедельник'
		when DATEPART(weekday, PDATE) = 2 then 'Вторник'
		when DATEPART(weekday, PDATE) = 3 then 'Среда'
		when DATEPART(weekday, PDATE) = 4 then 'Четверг'
		when DATEPART(weekday, PDATE) = 5 then 'Пятница'
		when DATEPART(weekday, PDATE) = 6 then 'Суббота'
		when DATEPART(weekday, PDATE) = 7 then 'Воскресенье'
	end
	from PROGRESS where SUBJECT = 'СУБД'
	select * from PROGRESS
	---------------------------------------
		
---------------------------------------------

----------------------5----------------------
DECLARE @averageMark float(4), @coun int;
set @averageMark = (select avg(NOTE) from PROGRESS);
set @coun = (select count(NOTE) from PROGRESS);

print 'Средняя оценка: ' + cast(@averageMark as varchar);

if @averageMark < 7
begin
	print 'Средние оценки меньше 7'
end
else if @averageMark > 7
begin
	print 'Средние оценки больше 7'
end

print 'Количество оценок: '+ cast(@coun as varchar);
select * from PROGRESS
select sum(NOTE) from PROGRESS
---------------------------------------------

----------------------6----------------------
select PROGRESS.IDSTUDENT, PROGRESS.SUBJECT, 
case
	when AVG(PROGRESS.NOTE) = 4 then 'Оценка 4'
	when AVG(PROGRESS.NOTE) between 5 and 6 then 'Оценка удовлетворительно'
	when AVG(PROGRESS.NOTE) between 7 and 8 then 'Оценка хорошо'
	when AVG(PROGRESS.NOTE) between 9 and 10 then 'Оценка отлично'
	else 'Оценка ниже 4'
end

from PROGRESS
group by IDSTUDENT, SUBJECT

select * from PROGRESS
---------------------------------------------

----------------------7----------------------
DROP TABLE #TEMP1;
CREATE TABLE #TEMP1
(
	ID int identity(1,1),
	RANDOM_NUMBER_1 int,
	RANDOM_NUMBER_2 int,
);

DECLARE  @iter int = 0;
WHILE @iter < 10
	begin
	INSERT #TEMP1(RANDOM_NUMBER_1, RANDOM_NUMBER_2)
			values(rand() * 1000, rand() * 1000);
	SET @iter = @iter + 1;
	end
SELECT * from #TEMP1;
---------------------------------------------

----------------------8----------------------
DECLARE @parm int = 1
print @parm + 1
print @parm + 2
RETURN
print @parm + 3
---------------------------------------------

----------------------9----------------------
begin try
	UPDATE STUDENT SET IDGROUP = 'string' WHERE IDGROUP = 18
end try
begin catch
	print  ERROR_NUMBER()
	print  ERROR_MESSAGE()
	print  ERROR_LINE()
	print  ERROR_PROCEDURE()
	print  ERROR_SEVERITY()
	print  ERROR_STATE()
end catch
select * from STUDENT
---------------------------------------------

---------------------------------------------
DECLARE @i int = 0;
WHILE @i <= 10
	BEGIN
		IF @i % 2 = 0
			BEGIN
				PRINT @i
			END
		SET @i = @i + 1
	END
---------------------------------------------