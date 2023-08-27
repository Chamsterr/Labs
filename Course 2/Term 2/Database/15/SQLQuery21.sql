-----------------1-------------------
create table TR_AUDIT
(
	ID int identity(1, 1),										-- номер
	STMT varchar(20) check (STMT in ('INS', 'DEL', 'UPD')),		-- DML название оператора
	TRNAME varchar(50),											-- имя триггера
	CC varchar(300)												-- комментарий
)

create trigger TR_TEACHER_INS on TEACHER after insert
as
begin
	declare @TEACHER char(10), @TEACHER_NAME varchar(100),
			   @GENDER char(1), @PULPIT char(20), @IN varchar(300)
	print 'Выполнена операция INSERT'
	set @TEACHER = (select TEACHER from INSERTED)
	set @TEACHER_NAME = (select TEACHER_NAME from INSERTED)
	set @GENDER = (select GENDER from INSERTED)
	set @PULPIT = (select PULPIT from INSERTED)
	set @IN = ltrim(rtrim(@TEACHER)) + ' ' + ltrim(rtrim(@TEACHER_NAME)) + 
			  ' ' + ltrim(rtrim(@GENDER)) + ' ' + ltrim(rtrim(@PULPIT))
	insert into TR_AUDIT (STMT, TRNAME, CC) values ('INS', 'TR_TEACHER_INS', @IN)
end


insert into TEACHER values ('ИВНВ', 'Иванов Иван Иванович', 'м', 'ИСиТ')
select * from TEACHER
select * from TR_AUDIT order by ID
-------------------------------------

-----------------2-------------------

use UNIVER2
go
create trigger TR_TEACHER_DEL on TEACHER after delete
as
begin
	declare @TEACHER char(10), @TEACHER_NAME varchar(100),
			   @GENDER char(1), @PULPIT char(20), @IN varchar(300)
	print 'Выполнена операция DELETE'
	set @TEACHER = (select TEACHER from DELETED)
	set @TEACHER_NAME = (select TEACHER_NAME from DELETED)
	set @GENDER = (select GENDER from DELETED)
	set @PULPIT = (select PULPIT from DELETED)
	set @IN = ltrim(rtrim(@TEACHER)) + ' ' + ltrim(rtrim(@TEACHER_NAME)) + 
			  ' ' + ltrim(rtrim(@GENDER)) + ' ' + ltrim(rtrim(@PULPIT))
	insert into TR_AUDIT (STMT, TRNAME, CC) values ('DEL', 'TR_TEACHER_DEL', @IN)
end

go
delete from TEACHER where TEACHER = 'ИВНВ'
select * from TEACHER
select * from TR_AUDIT order by ID
-------------------------------------

------------------3------------------
use UNIVER2
go
alter trigger TR_TEACHER_UPD on TEACHER after update
as
begin
declare @TEACHER char(10), @TEACHER_NAME varchar(100),
		   @GENDER char(1), @PULPIT char(20), @IN varchar(300)
	print 'Выполнена операция UPDATE'

	set @TEACHER = (select TEACHER from DELETED where TEACHER is not null)
	set @TEACHER_NAME = (select TEACHER_NAME from DELETED where TEACHER_NAME is not null)
	set @GENDER = (select GENDER from DELETED where GENDER is not null)
	set @PULPIT = (select PULPIT from DELETED where PULPIT is not null)
	set @IN = ltrim(rtrim(@TEACHER)) + ' ' + ltrim(rtrim(@TEACHER_NAME)) + 
			  ' ' + ltrim(rtrim(@GENDER)) + ' ' + ltrim(rtrim(@PULPIT)) + ' -> '

	set @TEACHER = (select TEACHER from INSERTED where TEACHER is not null)
	set @TEACHER_NAME = (select TEACHER_NAME from INSERTED where TEACHER_NAME is not null)
	set @GENDER = (select GENDER from INSERTED where GENDER is not null)
	set @PULPIT = (select PULPIT from INSERTED where PULPIT is not null)
	set @IN = @IN + ltrim(rtrim(@TEACHER)) + ' ' + ltrim(rtrim(@TEACHER_NAME)) + 
			  ' ' + ltrim(rtrim(@GENDER)) + ' ' + ltrim(rtrim(@PULPIT))
	insert into TR_AUDIT (STMT, TRNAME, CC) values ('UPD', 'TR_TEACHER_UPD', @IN)
end
go
update TEACHER set GENDER = 'м' where TEACHER='РЖК'
select * from TEACHER
select * from TR_AUDIT;
-------------------------------------

------------------4------------------
go
create trigger TR_TEACHER on TEACHER after insert, update, delete
as
begin
	declare @TEACHER char(10), @TEACHER_NAME varchar(100),
		    @GENDER char(1), @PULPIT char(20), @IN varchar(300)

	if (select count(*) from INSERTED) > 0 and (select count(*) from DELETED) > 0
	begin
		print 'Выполнена операция UPDATE'
		set @TEACHER = (select TEACHER from DELETED where TEACHER is not null)
		set @TEACHER_NAME = (select TEACHER_NAME from DELETED where TEACHER_NAME is not null)
		set @GENDER = (select GENDER from DELETED where GENDER is not null)
		set @PULPIT = (select PULPIT from DELETED where PULPIT is not null)
		set @IN = ltrim(rtrim(@TEACHER)) + ' ' + ltrim(rtrim(@TEACHER_NAME)) + 
				  ' ' + ltrim(rtrim(@GENDER)) + ' ' + ltrim(rtrim(@PULPIT)) + ' -> '

		set @TEACHER = (select TEACHER from INSERTED where TEACHER is not null)
		set @TEACHER_NAME = (select TEACHER_NAME from INSERTED where TEACHER_NAME is not null)
		set @GENDER = (select GENDER from INSERTED where GENDER is not null)
		set @PULPIT = (select PULPIT from INSERTED where PULPIT is not null)
		set @IN = @IN + ltrim(rtrim(@TEACHER)) + ' ' + ltrim(rtrim(@TEACHER_NAME)) + 
				  ' ' + ltrim(rtrim(@GENDER)) + ' ' + ltrim(rtrim(@PULPIT))

		insert into TR_AUDIT (STMT, TRNAME, CC) values ('UPD', 'TR_TEACHER', @IN)
	end

	if (select count(*) from INSERTED) > 0 and (select count(*) from DELETED) = 0
	begin
		print 'Выполнена операция INSERT'
		set @TEACHER = (select TEACHER from INSERTED)
		set @TEACHER_NAME = (select TEACHER_NAME from INSERTED)
		set @GENDER = (select GENDER from INSERTED)
		set @PULPIT = (select PULPIT from INSERTED)
		set @IN = ltrim(rtrim(@TEACHER)) + ' ' + ltrim(rtrim(@TEACHER_NAME)) + 
				  ' ' + ltrim(rtrim(@GENDER)) + ' ' + ltrim(rtrim(@PULPIT))
		insert into TR_AUDIT (STMT, TRNAME, CC) values ('INS', 'TR_TEACHER', @IN)
	end

	if (select count(*) from INSERTED) = 0 and (select count(*) from DELETED) > 0
	begin
		print 'Выполнена операция DELETE'
		set @TEACHER = (select TEACHER from DELETED)
		set @TEACHER_NAME = (select TEACHER_NAME from DELETED)
		set @GENDER = (select GENDER from DELETED)
		set @PULPIT = (select PULPIT from DELETED)
		set @IN = ltrim(rtrim(@TEACHER)) + ' ' + ltrim(rtrim(@TEACHER_NAME)) + 
				  ' ' + ltrim(rtrim(@GENDER)) + ' ' + ltrim(rtrim(@PULPIT))
		insert into TR_AUDIT (STMT, TRNAME, CC) values ('DEL', 'TR_TEACHER', @IN)
	end
end
go
update TEACHER set GENDER = 'м' where TEACHER='РЖК'
delete from TEACHER where TEACHER = 'ТБДВ'
insert into TEACHER values ('ТБДВ', 'Тубач Денис Викторович', 'м', 'ИСиТ')

select * from TEACHER
select * from TR_AUDIT;
-------------------------------------

----------------5-------------------
insert into TEACHER values ('Для теста', 'Для теста', 'н', 'ИСиТ')
select * from TR_AUDIT order by ID
------------------------------------

----------------6-------------------
go
create trigger TR_TEACHER_DEL1 on TEACHER after delete
as 
	declare @TEACHER char(10), @TEACHER_NAME varchar(100),
			@GENDER char(1), @PULPIT char(20), @IN varchar(300)
	print 'DELETE Trigger 1'
	set @IN = 'Trigger Normal Priority'
	insert into TR_AUDIT (STMT, TRNAME, CC) values ('DEL', 'TR_TEACHER_DEL1', @IN)
go
create trigger TR_TEACHER_DEL2 on TEACHER after delete
as declare @TEACHER char(10), @TEACHER_NAME varchar(100),
		   @GENDER char(1), @PULPIT char(20), @IN varchar(300)
print 'DELETE Trigger 2'
set @IN = 'Trigger Low Priority'
insert into TR_AUDIT (STMT, TRNAME, CC) values ('DEL', 'TR_TEACHER_DEL2', @IN)

go
create trigger TR_TEACHER_DEL3 on TEACHER after delete
as declare @TEACHER char(10), @TEACHER_NAME varchar(100),
		   @GENDER char(1), @PULPIT char(20), @IN varchar(300)
print 'DELETE Trigger 3'
set @IN = 'Trigger Highest Priority'
insert into TR_AUDIT (STMT, TRNAME, CC) values ('DEL', 'TR_TEACHER_DEL3', @IN)

go
select t.name, e.type_desc 
from sys.triggers t join  sys.trigger_events e  
on t.object_id = e.object_id  
where OBJECT_NAME(t.parent_id) = 'TEACHER' and e.type_desc = 'DELETE'

go
exec SP_SETTRIGGERORDER @triggername = 'TR_TEACHER_DEL3', @order = 'First', @stmttype = 'DELETE'
exec SP_SETTRIGGERORDER @triggername = 'TR_TEACHER_DEL2', @order = 'Last',  @stmttype = 'DELETE'

go
insert into TEACHER values ('ТБДВ', 'Тубач Денис Викторович', 'м', 'ИСиТ')
delete from TEACHER where TEACHER = 'ТБДВ'
select * from TEACHER
select * from TR_AUDIT order by ID
------------------------------------

----------------7-------------------
go
create trigger TEACH_TRAN on TEACHER after insert, delete, update
as
declare @c int = (select COUNT(TEACHER) from TEACHER);
		if(@c > 10)
			begin
				raiserror('Учителей не может быть больше 10', 10, 1);
				rollback;
			end;
		return;


go
insert into TEACHER values ('ТЕСТ', 'Просто для теста', 'м', 'ИСиТ')
select * from TEACHER
select * from TR_AUDIT order by ID
------------------------------------

----------------8-------------------
go
create trigger TR_TEACHER_INSTEAD_OF on TEACHER instead of delete
as raiserror('Удаление запрещено', 10, 1)
return;

go
set nocount on
delete from TEACHER where TEACHER = 'РЖК'
select * from TR_AUDIT order by ID


drop table TR_AUDIT
drop trigger TR_TEACHER_INS
drop trigger TR_TEACHER_DEL
drop trigger TR_TEACHER_UPD
drop trigger TR_TEACHER
drop trigger TR_TEACHER_DEL1
drop trigger TR_TEACHER_DEL2
drop trigger TR_TEACHER_DEL3
drop trigger TEACH_TRAN
drop trigger TR_TEACHER_INSTEAD_OF
drop trigger TR_TEACHER_DDL
------------------------------------

----------------9-------------------
go
create trigger TR_TEACHER_DDL on database 
for DDL_DATABASE_LEVEL_EVENTS  as   
declare @EVENT_TYPE varchar(50) = EVENTDATA().value('(/EVENT_INSTANCE/EventType)[1]', 'varchar(50)')
declare @OBJ_NAME varchar(50) = EVENTDATA().value('(/EVENT_INSTANCE/ObjectName)[1]', 'varchar(50)')
declare @OBJ_TYPE varchar(50) = EVENTDATA().value('(/EVENT_INSTANCE/ObjectType)[1]', 'varchar(50)')
if @OBJ_NAME = 'TEACHER' 
begin
	print 'Тип события: ' + cast(@EVENT_TYPE as varchar)
	print 'Имя объекта: ' + cast(@OBJ_NAME as varchar)
	print 'Тип объекта: ' + cast(@OBJ_TYPE as varchar)
	raiserror('Операции с таблицей TEACHER запрещены.', 16, 1)
	rollback  
end

go
alter table TEACHER drop column TEACHER_NAME
------------------------------------