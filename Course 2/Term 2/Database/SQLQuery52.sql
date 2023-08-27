------------------1--------------------
SET NOCOUNT ON

DROP TABLE IF EXISTS X;

DECLARE @c int, @flag char = 'c';

SET IMPLICIT_TRANSACTIONS ON
	CREATE TABLE X(K INT)
	INSERT X VALUES (1), (2), (3);
	SET @c = (SELECT COUNT(*)
			  FROM X)
	PRINT '���-�� ����� � ������� X:' + cast(@c as varchar(2));
	if @flag = 'c'
		commit
	else
		rollback;
SET IMPLICIT_TRANSACTIONS OFF

IF EXISTS (SELECT *
		   FROM SYS.OBJECTS
		   WHERE OBJECT_ID = object_id(N'DBO.X'))
	PRINT '������� X ����'
else
	PRINT '������� X ���'

---------------------------------------

------------------2--------------------
--������ ��� ����� ������� � ����������������������
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
		VALUES (9999, 2, '������ ������ ���������',  '1988-12-03', null, null)
	COMMIT TRAN;
END TRY
BEGIN CATCH
	PRINT '������'
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
	PRINT '������'
	IF @@TRANCOUNT > 0 ROLLBACK TRAN;
END CATCH

---------------------------------------

------------------3--------------------
declare @savepoint varchar(30);
begin try
	begin tran
		delete AUDITORIUM where AUDITORIUM_NAME = '301-1';									
		set @savepoint = 'save1'; save transaction @savepoint;

		insert into AUDITORIUM values('301-1','��-�', '10', '301-1');							
		set @savepoint = 'save2'; save transaction @savepoint;

		--insert into AUDITORIUM values('301-1','��-�', '10', '301-1');							
		--set @savepoint = 'save3'; save transaction @savepoint;

		update AUDITORIUM set AUDITORIUM_CAPACITY = '15' where AUDITORIUM_NAME='301-1';		
		set @savepoint = 'save3'; save transaction @savepoint;
	commit tran;
end try

begin catch
	print '������: ' + cast(error_number() as varchar(5)) + ' ' + error_message()
	if @@TRANCOUNT > 0
		begin
			print '����������� �����: ' + @savepoint;
			rollback tran @savepoint;
			commit tran;
		end;
end catch;

insert into AUDITORIUM values('301-1','��-�', '15', '301-1');
---------------------------------------

------------------4--------------------
-- ������� A
	set transaction isolation level READ UNCOMMITTED --��������� ����������������, ��������������� � ��������� ������
	begin transaction 
	-------------------------- t1 ------------------
	select @@SPID 'SID', 'insert AUDITORIUM' '���������', * from SUBJECT where SUBJECT = '���';
																	             
	select @@SPID 'SID', 'update AUDITORIUM'  '���������',  AUDITORIUM_NAME, 
                      AUDITORIUM_TYPE,AUDITORIUM_CAPACITY from AUDITORIUM   where  AUDITORIUM_NAME='301-1';
	commit; 
	-------------------------- t2 -----------------

--- ������� B	
	begin transaction 
	select @@SPID 'SID'; -- SPID - ���������� ��������� ������������� ��������, ����������� �������� �������� �����������
	INSERT into SUBJECT values('���','������ ���������������� �����������','����');   
	update AUDITORIUM set AUDITORIUM_CAPACITY = '25' where AUDITORIUM_NAME = '301-1';	
	-------------------------- t1 --------------------
	-------------------------- t2 --------------------
	rollback;

	delete SUBJECT where SUBJECT = '���';
---------------------------------------

------------------5--------------------
SELECT *
FROM AUDITORIUM

update AUDITORIUM set AUDITORIUM_CAPACITY = '60' where AUDITORIUM_NAME='301-1';	
-- ������� A
    set transaction isolation level READ COMMITTED	-- �� ��������� ����������������� ������, 
													-- �� ��� ���� �������� ��������������� � ������-��� ������
	begin transaction 
	select count(*) from AUDITORIUM where AUDITORIUM_CAPACITY = '30';
	-------------------------- t1 ------------------ 
	-------------------------- t2 -----------------
	select @@SPID 'SID', 'update AUDITORIUM'  '���������',  AUDITORIUM_NAME, 
                      AUDITORIUM_TYPE,AUDITORIUM_CAPACITY from AUDITORIUM   where  AUDITORIUM_NAME='301-1';
	commit; 

	--- ������� B	
	begin transaction 	

	-------------------------- t1 --------------------
    select @@SPID 'SID' update AUDITORIUM set AUDITORIUM_CAPACITY = '30' where AUDITORIUM_NAME='301-1';	

      commit; 
	-------------------------- t2 --------------------	
---------------------------------------

------------------6--------------------
SELECT *
FROM SUBJECT

-- ������� �
    set transaction isolation level  REPEATABLE READ	-- �� ��������� ����������������� ������ � ���������������� ������, 
														-- �� ��� ���� �������� ��������� ������
	begin transaction 
	select SUBJECT_NAME from SUBJECT where PULPIT = '��';
	-------------------------- t1 ------------------ 
	-------------------------- t2 -----------------
	select  case
          when SUBJECT = '���' then 'insert  SUBJECT'  else ' ' 
end '���������', SUBJECT_NAME from SUBJECT  where PULPIT = '��';
	commit; 

	--- ������� B	
	begin transaction 	  
	-------------------------- t1 --------------------
          	INSERT into SUBJECT values('���','������ ���������������� �����������','����')
			update SUBJECT set SUBJECT_NAME = '������ ��������� ���� � ����' where  PULPIT = '��';   
          commit; 
	-------------------------- t2 --------------------

delete SUBJECT where SUBJECT = '���';
---------------------------------------

------------------7--------------------
set transaction isolation level SERIALIZABLE	-- ���������� ����������, ����������������� � ���������������� ������
	begin transaction 
		delete SUBJECT where SUBJECT = '���';
		INSERT into SUBJECT values('���', '������ ���������������� �����������', '����');
        update SUBJECT set SUBJECT_NAME = '������ ���������������� interface' where  SUBJECT = '���';
	    select SUBJECT_NAME,PULPIT from SUBJECT where PULPIT = '����';
	-------------------------- t1 -----------------
	 select SUBJECT_NAME,PULPIT from SUBJECT where PULPIT = '����';
	-------------------------- t2 ------------------ 
	commit; 	

--- ������� B	
	begin transaction 	  
		delete SUBJECT where SUBJECT = '���';
		INSERT into SUBJECT values('���', '������ ���������������� �����������','����');
        update SUBJECT set SUBJECT_NAME = '������ ���������������� interface' where  SUBJECT = '���';
	    select SUBJECT_NAME from SUBJECT where PULPIT = '����';
     -------------------------- t1 --------------------
     commit; 
     select SUBJECT_NAME,PULPIT from SUBJECT where PULPIT = '����';
     -------------------------- t2 --------------------
	 		
	delete SUBJECT where SUBJECT = '���';
---------------------------------------

------------------8--------------------
SELECT *
FROM GROUPS

SELECT *
FROM STUDENT

DECLARE @LASTGROUPID INT;

BEGIN TRAN AddGroupWithStudent
    INSERT INTO GROUPS VALUES('��', '1-40 01 02', '2013')
    SET @LASTGROUPID = (SELECT COUNT(*) FROM GROUPS)

    BEGIN TRAN AddStudent
        INSERT INTO STUDENT (IDGROUP, NAME, BDAY, INFO, FOTO)
        VALUES (@LASTGROUPID, '����� ���� ����������',  '1988-12-03', null, null)
    COMMIT TRAN AddStudent

ROLLBACK TRAN AddGroupWithStudent


DECLARE @LASTGROUPID INT;

BEGIN TRAN AddGroupWithStudent
    INSERT INTO GROUPS VALUES('��', '1-40 01 02', '2013')
    SET @LASTGROUPID = (SELECT COUNT(*) FROM GROUPS)

    BEGIN TRAN AddStudent
        INSERT INTO STUDENT (IDGROUP, NAME, BDAY, INFO, FOTO)
        VALUES (@LASTGROUPID, '����� ���� ����������',  '1988-12-03', null, null)
    ROLLBACK TRAN AddGroupWithStudent
---------------------------------------

SELECT local_net_address, local_tcp_port
FROM sys.dm_exec_connections
WHERE session_id = @@SPID;