-----------------1------------------
create function COUNT_STUDENTS (@FACULTY varchar(20)) returns int
as
begin
		declare @COUNT int = (select count(*)
						  from STUDENT s
						  join GROUPS g on s.IDGROUP = g.IDGROUP
						  join FACULTY f on f.FACULTY = g.FACULTY
						  where g.FACULTY = @FACULTY)
	return @COUNT
end

go
select * from STUDENT s	join GROUPS g on s.IDGROUP = g.IDGROUP
						join FACULTY f on f.FACULTY = g.FACULTY
						where g.FACULTY = 'ТОВ'
						
go
declare @RES int = dbo.COUNT_STUDENTS('ТОВ')
print 'Количество студентов: ' + cast(@RES as varchar)

------------------------------------

-----------------1-2------------------
alter function COUNT_STUDENTS (@FACULTY varchar(20) = null, @PROFFESION varchar(20) = null) returns int
as 
begin
	declare @COUNT int = (select count(*)
						  from   STUDENT s
						  join   GROUPS g on s.IDGROUP = g.IDGROUP
						  join   FACULTY f on f.FACULTY = g.FACULTY
						  where  g.FACULTY = isnull(@FACULTY, g.FACULTY)
						  and    g.PROFESSION = isnull(@PROFFESION, g.PROFESSION))
	return @COUNT
end

go
declare @RES int = dbo.COUNT_STUDENTS('ТОВ', '1-48 01 02')
print 'Количество студентов: ' + cast(@RES as varchar)
------------------------------------

-----------------2------------------
create function FSUBJECTS (@PULPIT varchar(20)) returns varchar(300)
as 
begin
	declare @OUT varchar(300) = 'Дисциплины: '
	declare @SUBJ varchar(100) = ''
	declare cur cursor local static for
		(select s.SUBJECT 
		 from   SUBJECT s 
		 where  s.PULPIT = @PULPIT)
	open cur
	fetch cur into @SUBJ
	while @@FETCH_STATUS = 0
	begin
		set @OUT += rtrim(ltrim(@SUBJ)) + ', '
		fetch cur into @SUBJ
	end
	return @OUT
end

--drop function FSUBJECTS

go
select PULPIT Кафедра, dbo.FSUBJECTS(PULPIT) Дисциплины
from   PULPIT
------------------------------------

-----------------3------------------
﻿use UNIVER;

go
create function FFACPUL (@FACULTY varchar(20), @PULPIT varchar(20)) returns table
as return
	select f.FACULTY Факультет, p.PULPIT Кафедра
	from   FACULTY f left join PULPIT p 
	on	   p.FACULTY = f.FACULTY
	where  f.FACULTY = isnull(@FACULTY, f.FACULTY)
	and	   p.PULPIT = isnull (@PULPIT, p.PULPIT)

--drop function FFACPUL

go
select * from FFACPUL(null, null)
select * from FFACPUL('ИЭФ', null)
select * from FFACPUL(null, 'ОХ')
select * from FFACPUL('ТТЛП', 'ТЛ')
------------------------------------

-----------------4------------------
create function FCTEACHER (@PULPIT varchar(20)) returns int
as begin
	declare @COUNT int = (select count(*)
						  from   TEACHER t
						  where  t.PULPIT = isnull(@PULPIT, t.PULPIT))
	return @COUNT
end

-- drop function FCTEACHER

go
print 'Кол-во преподавателей всего: ' + cast(dbo.FCTEACHER(null) as varchar)
print 'Кол-во преподавателей ИСиТ:  ' + cast(dbo.FCTEACHER('ИСиТ') as varchar)
select PULPIT Кафедра, dbo.FCTEACHER(PULPIT) [Кол-во преподавателей]
from   PULPIT
------------------------------------


-----------------6------------------
create function COUNT_PULPITS (@FACULTY varchar(20)) returns int
as begin
	declare @COUNT int = (select count(PULPIT) from PULPIT where FACULTY = isnull(@FACULTY, FACULTY))
	return @COUNT
end

go
create function COUNT_GROUPS (@FACULTY varchar(20)) returns int
as begin
	declare @COUNT int = (select count(IDGROUP) from GROUPS where FACULTY = isnull(@FACULTY, FACULTY))
	return @COUNT
end

go
create function COUNT_PROFESSIONS (@FACULTY varchar(20)) returns int
as begin
	declare @COUNT int =  (select count(PROFESSION) from PROFESSION where FACULTY = isnull(@FACULTY, FACULTY))
	return @COUNT
end


--drop function COUNT_PULPITS
--drop function COUNT_GROUPS
--drop function COUNT_PROFESSIONS
--drop function FACULTY_REPORT


go
create function FACULTY_REPORT(@c int) returns @fr table
([Факультет] varchar(50), [Кол-во кафедр] int, [Кол-во групп] int, [Кол-во студентов] int, [Кол-во специальностей] int)
as 
begin 
	declare @f varchar(30);
	declare cc CURSOR static for 
	select FACULTY from FACULTY 
	where  dbo.COUNT_STUDENTS(FACULTY, default) > @c; 

	open cc;  
		fetch cc into @f;
	    while @@fetch_status = 0
			begin
	            insert @fr values(@f,  dbo.COUNT_PULPITS(@f),
	            dbo.COUNT_GROUPS(@f),   dbo.COUNT_STUDENTS(@f, default),
	            dbo.COUNT_PROFESSIONS(@f)); 
	            fetch cc into @f;  
	       end;   
	return; 
end;

select * from dbo.FACULTY_REPORT(40)
------------------------------------
