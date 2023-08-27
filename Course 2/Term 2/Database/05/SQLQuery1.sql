-------------------------------------1----------------------------------------
--FACULITY
--PULPIT
--PROFESSION

SELECT PULPIT.PULPIT_NAME
FROM PULPIT
WHERE PULPIT.FACULTY IN (SELECT PROFESSION.FACULTY
						 FROM PROFESSION
						 WHERE PROFESSION.PROFESSION_NAME LIKE('%���������%'))

------------------------------------------------------------------------------

-------------------------------------2----------------------------------------

SELECT PULPIT.PULPIT_NAME
FROM PULPIT
INNER JOIN (
	SELECT DISTINCT FACULTY
    FROM PROFESSION
    WHERE PROFESSION_NAME LIKE '%���������%'
) AS PROFESSION_SUB
ON PULPIT.FACULTY = PROFESSION_SUB.FACULTY

------------------------------------------------------------------------------

-------------------------------------3----------------------------------------

SELECT DISTINCT PULPIT.PULPIT_NAME
FROM PULPIT
INNER JOIN FACULTY ON PULPIT.FACULTY = FACULTY.FACULTY
INNER JOIN PROFESSION ON PROFESSION.FACULTY = PULPIT.FACULTY
WHERE PROFESSION_NAME LIKE '%���������%'

------------------------------------------------------------------------------

-------------------------------------4----------------------------------------

SELECT AUDITORIUM_NAME, AUDITORIUM_TYPE, AUDITORIUM_CAPACITY
FROM AUDITORIUM aud1
WHERE AUDITORIUM_CAPACITY = (SELECT TOP(1) AUDITORIUM_CAPACITY FROM AUDITORIUM aud2
							 WHERE aud2.AUDITORIUM_TYPE = aud1.AUDITORIUM_TYPE
						     ORDER BY AUDITORIUM_CAPACITY DESC)



SELECT AUDITORIUM_NAME, AUDITORIUM_TYPE, AUDITORIUM_CAPACITY
FROM AUDITORIUM aud1

------------------------------------------------------------------------------

-------------------------------------5----------------------------------------
--FACULTY
--PULPIT

SELECT FACULTY.FACULTY_NAME
FROM FACULTY
WHERE NOT EXISTS (SELECT * 
				  FROM PULPIT
				  WHERE PULPIT.FACULTY = FACULTY.FACULTY) 

------------------------------------------------------------------------------

-------------------------------------6----------------------------------------
--PROGRESS

SELECT
(SELECT avg(NOTE) FROM PROGRESS WHERE PROGRESS.SUBJECT like '����') as '����',
(SELECT avg(NOTE) FROM PROGRESS WHERE PROGRESS.SUBJECT like '��') as '��',
(SELECT avg(NOTE) FROM PROGRESS WHERE PROGRESS.SUBJECT like '����') as '����'

------------------------------------------------------------------------------

-------------------------------------7----------------------------------------

--PROGRESS

SELECT STUDENT.NAME, PROGRESS.NOTE
FROM PROGRESS 
	INNER JOIN STUDENT ON PROGRESS.IDSTUDENT = STUDENT.IDSTUDENT 
WHERE PROGRESS.NOTE >= ALL(SELECT NOTE FROM PROGRESS WHERE PROGRESS.SUBJECT IN ('����', '��', 'C���'))

------------------------------------------------------------------------------

-------------------------------------8----------------------------------------

--PROGRESS

SELECT STUDENT.NAME, PROGRESS.NOTE
FROM PROGRESS 
	INNER JOIN STUDENT ON PROGRESS.IDSTUDENT = STUDENT.IDSTUDENT 
WHERE PROGRESS.NOTE < ANY(SELECT NOTE FROM PROGRESS WHERE PROGRESS.SUBJECT IN ('����', '��', 'C���') )

------------------------------------------------------------------------------