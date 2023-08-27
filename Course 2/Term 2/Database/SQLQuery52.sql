------------------1--------------------
SET NOCOUNT ON

DROP TABLE IF EXISTS X;

DECLARE @c int, @flag char = 'c';

SET IMPLICIT_TRANSACTIONS ON
	CREATE TABLE X(K INT)
	INSERT X VALUES (1), (2), (3);
	SET @c = (SELECT COUNT(*)
			  FROM X)
	PRINT 'Кол-во строк в таблицу X:' + cast(@c as varchar(2));
	if @flag = 'c'
		commit
	else
		rollback;
SET IMPLICIT_TRANSACTIONS OFF

IF EXISTS (SELECT *
		   FROM SYS.OBJECTS
		   WHERE OBJECT_ID = object_id(N'DBO.X'))
	PRINT 'Таблица X есть'
else
	PRINT 'Таблица X нет'

---------------------------------------

------------------2--------------------
--Способ как найти колонки с автоинкрементированием
SELECT 
    t.name AS table_name, 
    c.name AS column_name
FROM 
    sys.tables AS t
    JOIN sys.columns c ON t.object_id = c.object_id
WHERE 
    c.is_identity = 1 AND
    t.name = 'STUDENT';
--


SELECT *
FROM STUDENT

BEGIN TRY
	BEGIN TRAN
		INSERT INTO STUDENT (IDSTUDENT, IDGROUP, NAME, BDAY, INFO, FOTO)
		VALUES (9999, 2, 'Сергей Галина Иосифовна',  '1988-12-03', null, null)
	COMMIT TRAN;
END TRY
BEGIN CATCH
	PRINT 'ОШИБКА'
	IF @@TRANCOUNT > 0 ROLLBACK TRAN;
END CATCH

BEGIN TRY
	BEGIN TRAN
		UPDATE STUDENT
		SET IDGROUP = 'DADA'
		WHERE IDSTUDENT = 1000
	COMMIT TRAN;
END TRY
BEGIN CATCH
	PRINT 'ОШИБКА'
	IF @@TRANCOUNT > 0 ROLLBACK TRAN;
END CATCH

---------------------------------------

------------------3--------------------
declare @savepoint varchar(30);
begin try
	begin tran
		delete AUDITORIUM where AUDITORIUM_NAME = '301-1';									
		set @savepoint = 'save1'; save transaction @savepoint;

		insert into AUDITORIUM values('301-1','ЛБ-К', '10', '301-1');							
		set @savepoint = 'save2'; save transaction @savepoint;

		--insert into AUDITORIUM values('301-1','ЛБ-К', '10', '301-1');							
		--set @savepoint = 'save3'; save transaction @savepoint;

		update AUDITORIUM set AUDITORIUM_CAPACITY = '15' where AUDITORIUM_NAME='301-1';		
		set @savepoint = 'save3'; save transaction @savepoint;
	commit tran;
end try

begin catch
	print 'Ошибка: ' + cast(error_number() as varchar(5)) + ' ' + error_message()
	if @@TRANCOUNT > 0
		begin
			print 'Контрольная точка: ' + @savepoint;
			rollback tran @savepoint;
			commit tran;
		end;
end catch;

insert into AUDITORIUM values('301-1','ЛБ-К', '15', '301-1');
---------------------------------------

------------------4--------------------
-- Таблица A
	set transaction isolation level READ UNCOMMITTED --допускает неподтвержденное, неповторяющееся и фантомное чтение
	begin transaction 
	-------------------------- t1 ------------------
	select @@SPID 'SID', 'insert AUDITORIUM' 'результат', * from SUBJECT where SUBJECT = 'ДПИ';
																	             
	select @@SPID 'SID', 'update AUDITORIUM'  'результат',  AUDITORIUM_NAME, 
                      AUDITORIUM_TYPE,AUDITORIUM_CAPACITY from AUDITORIUM   where  AUDITORIUM_NAME='301-1';
	commit; 
	-------------------------- t2 -----------------

--- Таблица B	
	begin transaction 
	select @@SPID 'SID'; -- SPID - возвращает системный идентификатор процесса, назначенный сервером текущему подключению
	INSERT into SUBJECT values('ДПИ','Дизайн пользовательских интерфейсов','ИСиТ');   
	update AUDITORIUM set AUDITORIUM_CAPACITY = '25' where AUDITORIUM_NAME = '301-1';	
	-------------------------- t1 --------------------
	-------------------------- t2 --------------------
	rollback;

	delete SUBJECT where SUBJECT = 'ДПИ';
---------------------------------------

------------------5--------------------
SELECT *
FROM AUDITORIUM

update AUDITORIUM set AUDITORIUM_CAPACITY = '60' where AUDITORIUM_NAME='301-1';	
-- Таблица A
    set transaction isolation level READ COMMITTED	-- не допускает неподтвержденного чтения, 
													-- но при этом возможно неповторяющееся и фантом-ное чтение
	begin transaction 
	select count(*) from AUDITORIUM where AUDITORIUM_CAPACITY = '30';
	-------------------------- t1 ------------------ 
	-------------------------- t2 -----------------
	select @@SPID 'SID', 'update AUDITORIUM'  'результат',  AUDITORIUM_NAME, 
                      AUDITORIUM_TYPE,AUDITORIUM_CAPACITY from AUDITORIUM   where  AUDITORIUM_NAME='301-1';
	commit; 

	--- Таблица B	
	begin transaction 	

	-------------------------- t1 --------------------
    select @@SPID 'SID' update AUDITORIUM set AUDITORIUM_CAPACITY = '30' where AUDITORIUM_NAME='301-1';	

      commit; 
	-------------------------- t2 --------------------	
---------------------------------------

------------------6--------------------
SELECT *
FROM SUBJECT

-- Таблица А
    set transaction isolation level  REPEATABLE READ	-- не допускает неподтвержденного чтения и неповторяющегося чтения, 
														-- но при этом возможно фантомное чтение
	begin transaction 
	select SUBJECT_NAME from SUBJECT where PULPIT = 'ТЛ';
	-------------------------- t1 ------------------ 
	-------------------------- t2 -----------------
	select  case
          when SUBJECT = 'ДПИ' then 'insert  SUBJECT'  else ' ' 
end 'результат', SUBJECT_NAME from SUBJECT  where PULPIT = 'ТЛ';
	commit; 

	--- Таблица B	
	begin transaction 	  
	-------------------------- t1 --------------------
          	INSERT into SUBJECT values('ДПИ','Дизайн пользовательских интерфейсов','ИСиТ')
			update SUBJECT set SUBJECT_NAME = 'Водный транспорт леса и поля' where  PULPIT = 'ТЛ';   
          commit; 
	-------------------------- t2 --------------------

delete SUBJECT where SUBJECT = 'ДПИ';
---------------------------------------

------------------7--------------------
set transaction isolation level SERIALIZABLE	-- отсутствие фантомного, неподтвержденного и неповторяющегося чтения
	begin transaction 
		delete SUBJECT where SUBJECT = 'ДПИ';
		INSERT into SUBJECT values('ДПИ', 'Дизайн пользовательских интерфейсов', 'ИСиТ');
        update SUBJECT set SUBJECT_NAME = 'Дизайн пользовательских interface' where  SUBJECT = 'ДПИ';
	    select SUBJECT_NAME,PULPIT from SUBJECT where PULPIT = 'ИСиТ';
	-------------------------- t1 -----------------
	 select SUBJECT_NAME,PULPIT from SUBJECT where PULPIT = 'ИСиТ';
	-------------------------- t2 ------------------ 
	commit; 	

--- Таблица B	
	begin transaction 	  
		delete SUBJECT where SUBJECT = 'ДПИ';
		INSERT into SUBJECT values('ДПИ', 'Дизайн пользовательских интерфейсов','ИСиТ');
        update SUBJECT set SUBJECT_NAME = 'Дизайн пользовательских interface' where  SUBJECT = 'ДПИ';
	    select SUBJECT_NAME from SUBJECT where PULPIT = 'ИСиТ';
     -------------------------- t1 --------------------
     commit; 
     select SUBJECT_NAME,PULPIT from SUBJECT where PULPIT = 'ИСиТ';
     -------------------------- t2 --------------------
	 		
	delete SUBJECT where SUBJECT = 'ДПИ';
---------------------------------------

------------------8--------------------
SELECT *
FROM GROUPS

SELECT *
FROM STUDENT

DECLARE @LASTGROUPID INT;

BEGIN TRAN AddGroupWithStudent
    INSERT INTO GROUPS VALUES('ИТ', '1-40 01 02', '2013')
    SET @LASTGROUPID = (SELECT COUNT(*) FROM GROUPS)

    BEGIN TRAN AddStudent
        INSERT INTO STUDENT (IDGROUP, NAME, BDAY, INFO, FOTO)
        VALUES (@LASTGROUPID, 'Север Анна Алексеевна',  '1988-12-03', null, null)
    COMMIT TRAN AddStudent

ROLLBACK TRAN AddGroupWithStudent


DECLARE @LASTGROUPID INT;

BEGIN TRAN AddGroupWithStudent
    INSERT INTO GROUPS VALUES('ИТ', '1-40 01 02', '2013')
    SET @LASTGROUPID = (SELECT COUNT(*) FROM GROUPS)

    BEGIN TRAN AddStudent
        INSERT INTO STUDENT (IDGROUP, NAME, BDAY, INFO, FOTO)
        VALUES (@LASTGROUPID, 'Север Анна Алексеевна',  '1988-12-03', null, null)
    ROLLBACK TRAN AddGroupWithStudent
---------------------------------------

SELECT local_net_address, local_tcp_port
FROM sys.dm_exec_connections
WHERE session_id = @@SPID;