CREATE PROCEDURE GET_STUDENT_AND_NOTE_BY_SUBJECT
	@subject VARCHAR(30)
	as
		SELECT *
		FROM PROGRESS
		WHERE SUBJECT = @subject
EXEC GET_STUDENT_AND_NOTE_BY_SUBJECT @SUBJECT = 'КГ'

CREATE PROCEDURE AVG_NOTE_BY_SUB
	@SUBJECT VARCHAR(30)
	AS
	DECLARE @RES INT =	(SELECT AVG(NOTE)
		FROM PROGRESS
		WHERE SUBJECT = @SUBJECT
		GROUP BY SUBJECT)
		RETURN @RES

DECLARE @RESS INT
EXEC @RESS = AVG_NOTE_BY_SUB @SUBJECT = 'КГ'

CREATE FUNCTION AVG_NOTE_BY_SUB_FUNC (@SUBJECT VARCHAR(30)) RETURNS INT
AS
BEGIN
	DECLARE @ADAD INT = (SELECT AVG(NOTE)
		FROM PROGRESS
		WHERE SUBJECT = @SUBJECT
		GROUP BY SUBJECT)
	RETURN @ADAD
END
DECLARE @CCCC INT = DBO.AVG_NOTE_BY_SUB_FUNC('КГ')
PRINT @CCCC

ALTER FUNCTION GET_STUDENT_AND_NOTE_BY_SUBJECT_FUNC (@subject VARCHAR(30)) RETURNS TABLE
	as
	RETURN SELECT *
		   FROM PROGRESS
		   WHERE SUBJECT = @subject

CREATE FUNCTION GET_HOW_MANY_NOTE_BY_SUBJECT_GET_CORRECT_NOTE_FUNC (@subject VARCHAR(30)) RETURNS INT
	as
	begin
		declare @C int = (SELECT COUNT(*) FROM PROGRESS WHERE SUBJECT = @subject)
		RETURN @C
	end

DECLARE @CCC INT = DBO.GET_HOW_MANY_NOTE_BY_SUBJECT_GET_CORRECT_NOTE_FUNC('КГ');
PRINT @CCC
SELECT * FROM GET_STUDENT_AND_NOTE_BY_SUBJECT_FUNC ('КГ')
--студент и оценка по предмету

CREATE procedure MAXES 
  @subj varchar(10) 
  as 
  select 
  p.SUBJECT, p.NOTE, s.NAME from PROGRESS p 
  inner join STUDENT s on p.IDSTUDENT = s.IDSTUDENT where p.SUBJECT = @subj

exec MAXES 'КГ'


create function MAXES_FUNC(@subj varchar(10)) returns table 
as return
  select 
  p.SUBJECT, p.NOTE, s.NAME from PROGRESS p 
  inner join STUDENT s on p.IDSTUDENT = s.IDSTUDENT where p.SUBJECT = @subj

select * from  MAXES_FUNC('СУБД')

--триггер запрещает удалять факультет 

CREATE TRIGGER TEST2 ON STUDENT AFTER DELETE
AS
PRINT 'ПОШЛО'
delete STUDENT from STUDENT where IDSTUDENT = 9999



alter trigger DENY_DEL on FACULTY instead of delete
as raiserror('удаление запрещено', 10, 1)
drop trigger DENY_DEL

delete FACULTY from FACULTY where FACULTY = 'ХТиТ'

select * from FACULTY

--соличество кафедр на факультете, факультет параметр

create procedure COUPUL @p varchar(20)
as begin
declare @i int = (select count(*) from PULPIT where FACULTY = @p)

return @i;
end;


declare @t int = 0;
exec @t = COUPUL 'ЛХФ';
print 'кол-во кафедр на факультете ' + convert(varchar, @t);

drop procedure COUPUL;


create function FCOUNT (@p varchar(20)) returns int
as begin
declare @i int = 0;
set @i = (select count(*) from PULPIT where FACULTY = @p);
return @i;
end;
go

declare @t int = dbo.FCOUNT('ЛХФ');
print convert(varchar, @t);
select PULPIT [кафедра], dbo.FCOUNT(FACULTY) [факультет]  from PULPIT

drop function FCOUNT;