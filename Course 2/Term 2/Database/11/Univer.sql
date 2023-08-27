--------------------1---------------------
DECLARE disciplineCursor CURSOR FOR
SELECT SUBJECT_NAME 
FROM SUBJECT
WHERE SUBJECT.PULPIT LIKE 'ИСиТ'

DECLARE @discipline VARCHAR(35)
DECLARE @N VARCHAR(2) = CHAR(13) + CHAR(10);
DECLARE @ResultText VARCHAR(1000) = 'Cписок дисциплин накафедре ИСиТ:' + @N;

OPEN disciplineCursor;
	FETCH disciplineCursor INTO @discipline;
	SET @ResultText = @ResultText + @discipline + @N;
	WHILE @@FETCH_STATUS = 0
		BEGIN
			SET @ResultText = RTRIM(@ResultText) + @discipline + @N;
			FETCH disciplineCursor INTO @discipline;
		END;
CLOSE disciplineCursor;
DEALLOCATE disciplineCursor;

PRINT @ResultText
------------------------------------------

--------------------2---------------------
------------------- Курсор локальный -------------------------------
declare StudentsL CURSOR LOCAL for SELECT NAME, IDGROUP from STUDENT;
declare @name nvarchar(50), @group int;      
	OPEN StudentsL;	  
	fetch StudentsL into @name, @group; 	
    print '1. '+ @name + ', группа: ' + cast(@group as varchar(6));   
go
declare @name nvarchar(50), @group int;     	
	fetch StudentsL into @name, @group; 	
    print '2. '+ @name+ ', группа: '  + cast(@group as varchar(6));  
go 
------------------- Курсор глобальный -------------------------------
declare StudentsG CURSOR GLOBAL for select NAME, IDGROUP from STUDENT;
declare @name nvarchar(50), @group int;      
	OPEN StudentsG;	  
	fetch StudentsG into @name, @group; 	
      print '1. '+ @name + ', группа: ' + cast(@group as varchar(6));   
      go
declare @name nvarchar(50), @group int;     	
	fetch StudentsG into @name, @group; 	
    print '2. '+ @name + ', группа: '+ cast(@group as varchar(6));  
CLOSE StudentsG;
DEALLOCATE StudentsG;
------------------------------------------

--------------------3---------------------
------------------- Курсор статический -------------------------------
declare progStatic cursor local static for SELECT SUBJECT, PDATE, NOTE FROM PROGRESS where SUBJECT = 'КГ';
declare @tid char(10), @tnm char(40), @tgn char(1);

open progStatic
print   'Количество строк : ' + cast(@@CURSOR_ROWS as varchar(5)); 
UPDATE PROGRESS set NOTE = 5 where IDSTUDENT = '1020';
delete PROGRESS where IDSTUDENT = '1079';
insert PROGRESS (SUBJECT, IDSTUDENT, PDATE, NOTE) 
                 values ('КГ', 1079, '2013-01-10', 10); 
FETCH progStatic into @tid, @tnm, @tgn;     
while @@fetch_status = 0                                    
     begin 
         print @tid + ' '+ @tnm + ' '+ @tgn;      
         fetch progStatic into @tid, @tnm, @tgn; 
      end;          
CLOSE progStatic;
select * from PROGRESS


------------------- Курсор динамический -------------------------------
go
declare progDynamic cursor local dynamic for SELECT SUBJECT, PDATE, NOTE FROM PROGRESS where SUBJECT = 'КГ';
declare @tid char(10), @tnm char(40), @tgn char(1);

open progDynamic
print   'Количество строк : ' + cast(@@CURSOR_ROWS as varchar(5)); 
UPDATE PROGRESS set NOTE = 5 where IDSTUDENT = '1020';
delete PROGRESS where IDSTUDENT = '1079';
insert PROGRESS (SUBJECT, IDSTUDENT, PDATE, NOTE) 
                 values ('КГ', 1079, '2013-01-10', 10); 
FETCH progDynamic into @tid, @tnm, @tgn;     
while @@fetch_status = 0                                    
     begin 
         print @tid + ' '+ @tnm + ' '+ @tgn;      
         fetch progDynamic into @tid, @tnm, @tgn; 
      end;          
CLOSE progDynamic;
select * from PROGRESS
------------------------------------------
------------------------------------------

----------------------4-------------------
declare progScroll cursor local dynamic scroll
	for select ROW_NUMBER() over (order by IDSTUDENT) Номер,
	* from PROGRESS;
declare @number varchar(100), @sub varchar(10), @idstudent varchar(6), @pdate varchar (11), @note varchar (2)

OPEN progScroll
FETCH progScroll into @number, @sub ,@idstudent ,@pdate,@note;
print 'Первая выбранная строка: ' + CHAR(10) +
'Номер записи: '+ rtrim(@number)  +
'. Дисциплина: '+ rtrim(@sub) +
'. ID студента: ' + rtrim(@idstudent) +
'. Дата экзамена: '  + rtrim(@pdate) + 
'. Оценка: ' + rtrim(@note);

FETCH LAST from progScroll into @number, @sub ,@idstudent ,@pdate,@note;
print 'Последняя строка: ' + CHAR(10) +
'Номер записи: '+ rtrim(@number)  +
'. Дисциплина: '+ rtrim(@sub) +
'. ID студента: ' + rtrim(@idstudent) +
'. Дата экзамена: '  + rtrim(@pdate) + 
'. Оценка: ' + rtrim(@note);

FETCH RELATIVE -1  from progScroll into @number, @sub ,@idstudent ,@pdate,@note;
print 'Первая до предыдущей строка: ' + CHAR(10) +
'Номер записи: '+ rtrim(@number)  +
'. Дисциплина: '+ rtrim(@sub) +
'. ID студента: ' + rtrim(@idstudent) +
'. Дата экзамена: '  + rtrim(@pdate) + 
'. Оценка: ' + rtrim(@note);

FETCH ABSOLUTE 2  from progScroll into @number, @sub ,@idstudent ,@pdate,@note;
print 'Вторая с начала строка: ' + CHAR(10) +
'Номер записи: '+ rtrim(@number)  +
'. Дисциплина: '+ rtrim(@sub) +
'. ID студента: ' + rtrim(@idstudent) +
'. Дата экзамена: '  + rtrim(@pdate) + 
'. Оценка: ' + rtrim(@note);

FETCH RELATIVE 1  from progScroll into @number, @sub ,@idstudent ,@pdate,@note;
print 'Первая после предыдущей строка: ' + CHAR(10) +
'Номер записи: '+ rtrim(@number)  +
'. Дисциплина: '+ rtrim(@sub) +
'. ID студента: ' + rtrim(@idstudent) +
'. Дата экзамена: '  + rtrim(@pdate) + 
'. Оценка: ' + rtrim(@note);

FETCH ABSOLUTE -2  from progScroll into @number, @sub ,@idstudent ,@pdate,@note;
print 'Вторая с конца строка: ' + CHAR(10) +
'Номер записи: '+ rtrim(@number)  +
'. Дисциплина: '+ rtrim(@sub) +
'. ID студента: ' + rtrim(@idstudent) +
'. Дата экзамена: '  + rtrim(@pdate) + 
'. Оценка: ' + rtrim(@note);
close progScroll

------------------------------------------

--------------------5---------------------
CREATE TABLE #Customers (
    CustomerID INT PRIMARY KEY,
    Name NVARCHAR(50),
    Country NVARCHAR(50)
);

INSERT INTO #Customers (CustomerID, Name, Country)
VALUES (1, 'John Doe', 'USA'),
       (2, 'Jane Smith', 'USA'),
       (3, 'John Brown', 'UK'),
       (101, 'Jane Johnson', 'USA'),
       (102, 'John Jackson', 'USA');

DECLARE @CustomerID INT;

DECLARE CustomerCursor CURSOR FOR
SELECT CustomerID
FROM #Customers
WHERE Country = 'USA';

-- Открытие курсора
OPEN CustomerCursor;

FETCH NEXT FROM CustomerCursor INTO @CustomerID;
WHILE @@FETCH_STATUS = 0
BEGIN
    IF @CustomerID < 100 
    BEGIN
        UPDATE #Customers
        SET Country = 'Canada'
        WHERE CURRENT OF CustomerCursor;
    END
    ELSE
    BEGIN
        DELETE FROM #Customers
        WHERE CURRENT OF CustomerCursor;
    END
    
    FETCH NEXT FROM CustomerCursor INTO @CustomerID;
END;

CLOSE CustomerCursor;
DEALLOCATE CustomerCursor;

SELECT *
FROM #Customers
------------------------------------------

--------------------6---------------------
--6-1
DECLARE StudentCursor CURSOR FOR
SELECT STUDENT.IDSTUDENT
FROM STUDENT
JOIN  PROGRESS ON STUDENT.IDSTUDENT = PROGRESS.IDSTUDENT
WHERE NOTE < 4;

DECLARE @StudentID int; 


OPEN StudentCursor
	FETCH NEXT FROM StudentCursor INTO @StudentID
	PRINT @StudentID
	WHILE @@FETCH_STATUS = 0
	BEGIN
		FETCH NEXT FROM StudentCursor INTO @StudentID
		PRINT @StudentID
		DELETE FROM PROGRESS
        WHERE CURRENT OF StudentCursor;
	END
	SELECT *
	FROM STUDENT
	JOIN  PROGRESS ON STUDENT.IDSTUDENT = PROGRESS.IDSTUDENT
CLOSE StudentCursor

--6-2

go

DECLARE @id INT;

DECLARE Prog CURSOR LOCAL DYNAMIC FOR
    SELECT PROGRESS.IDSTUDENT
    FROM PROGRESS
    JOIN STUDENT ON STUDENT.IDSTUDENT = PROGRESS.IDSTUDENT
    WHERE PROGRESS.IDSTUDENT = 1041;

OPEN Prog;

FETCH NEXT FROM Prog INTO @id;
	WHILE @@FETCH_STATUS = 0
	BEGIN
		UPDATE PROGRESS SET NOTE = NOTE + 1 WHERE CURRENT OF Prog;
		PRINT 'Пошло';
		FETCH NEXT FROM Prog INTO @id;
	END
CLOSE Prog;

DEALLOCATE Prog;


------------------------------------------
