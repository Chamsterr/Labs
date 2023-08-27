-------------------------------------(1-2)--------------------------------------
--AUDITORIUM
--AUDITORIUM_TYPE

SELECT MAX(AUDITORIUM.AUDITORIUM_CAPACITY)[������������ �����������], 
	   AVG(AUDITORIUM.AUDITORIUM_CAPACITY)[������� �����������], 
	   MIN(AUDITORIUM.AUDITORIUM_CAPACITY)[����������� �����������], 
	   SUM(AUDITORIUM.AUDITORIUM_CAPACITY)[��������� �����������],
	   COUNT(AUDITORIUM.AUDITORIUM_TYPE)[����� ���-�� ���������],
	   AUDITORIUM_TYPE.AUDITORIUM_TYPENAME
FROM AUDITORIUM
INNER JOIN AUDITORIUM_TYPE ON AUDITORIUM.AUDITORIUM_TYPE = AUDITORIUM_TYPE.AUDITORIUM_TYPE
GROUP BY AUDITORIUM_TYPE.AUDITORIUM_TYPENAME

------------------------------------------------------------------------------

-------------------------------------(1-2)--------------------------------------
--PROGRESS

SELECT MAX(AUDITORIUM.AUDITORIUM_CAPACITY)[������������ �����������], 
	   AVG(AUDITORIUM.AUDITORIUM_CAPACITY)[������� �����������], 
	   MIN(AUDITORIUM.AUDITORIUM_CAPACITY)[����������� �����������], 
	   SUM(AUDITORIUM.AUDITORIUM_CAPACITY)[��������� �����������],
	   COUNT(AUDITORIUM.AUDITORIUM_TYPE)[����� ���-�� ���������],
	   AUDITORIUM_TYPE.AUDITORIUM_TYPENAME
FROM AUDITORIUM
INNER JOIN AUDITORIUM_TYPE ON AUDITORIUM.AUDITORIUM_TYPE = AUDITORIUM_TYPE.AUDITORIUM_TYPE
GROUP BY AUDITORIUM_TYPE.AUDITORIUM_TYPENAME

--------------------------------------------------------------------------------

---------------------------------------3----------------------------------------
SELECT *
FROM (SELECT CASE 
				WHEN PROGRESS.NOTE between 4 and 5 THEN '4-5'
				WHEN PROGRESS.NOTE between 6 and 7 THEN '6-7'
				WHEN PROGRESS.NOTE between 8 and 9 THEN '8-9'
			 ELSE '10'
			 END [������], count(*)[���-��]

	  FROM PROGRESS GROUP BY CASE 
						WHEN PROGRESS.NOTE between 4 and 5 THEN '4-5'
						WHEN PROGRESS.NOTE between 6 and 7 THEN '6-7'
						WHEN PROGRESS.NOTE between 8 and 9 THEN '8-9'
					  ELSE '10'
					  END) AS T

ORDER BY CASE[������]
				WHEN '4-5' THEN 3
				WHEN '6-7' THEN 2 
				WHEN '8-9' THEN 1
		 ELSE 0
		 END
--------------------------------------------------------------------------------

---------------------------------------4----------------------------------------
--FACULTY
--GROUPS
--STUDENT
--PROGRESS
--������� ��������������� ������ ��� ������� ����� ������ ������������� � ����������. 

SELECT ROUND(AVG(CAST(NOTE AS float(4))), 2) AS [������� ������], FACULTY_NAME, GROUPS.PROFESSION, GROUPS.YEAR_FIRST
FROM FACULTY
	INNER JOIN GROUPS ON GROUPS.FACULTY = FACULTY.FACULTY
	INNER JOIN STUDENT ON GROUPS.IDGROUP = STUDENT.IDGROUP
	INNER JOIN PROGRESS ON PROGRESS.IDSTUDENT = STUDENT.IDSTUDENT
GROUP BY FACULTY_NAME, GROUPS.PROFESSION, GROUPS.YEAR_FIRST

--------------------------------------------------------------------------------

---------------------------------------5----------------------------------------
--FACULTY
--GROUPS
--STUDENT
--PROGRESS

SELECT ROUND(AVG(CAST(NOTE AS float(4))), 2) AS [������� ������], FACULTY_NAME, GROUPS.PROFESSION, GROUPS.YEAR_FIRST
FROM FACULTY
	INNER JOIN GROUPS ON GROUPS.FACULTY = FACULTY.FACULTY
	INNER JOIN STUDENT ON GROUPS.IDGROUP = STUDENT.IDGROUP
	INNER JOIN PROGRESS ON PROGRESS.IDSTUDENT = STUDENT.IDSTUDENT
WHERE PROGRESS.SUBJECT IN ('����', '����')
GROUP BY FACULTY_NAME, GROUPS.PROFESSION, GROUPS.YEAR_FIRST
--------------------------------------------------------------------------------

---------------------------------------6----------------------------------------
--FACULTY
--GROUPS
--STUDENT
--PROGRESS
--��������� �������������, ���������� � ������� ������ ��� ����� ��������� �� ���������� ���.

SELECT GROUPS.PROFESSION, PROGRESS.SUBJECT, AVG(NOTE) AS [������� ������], FACULTY.FACULTY
FROM FACULTY
	INNER JOIN GROUPS ON FACULTY.FACULTY = GROUPS.FACULTY
	INNER JOIN STUDENT ON GROUPS.IDGROUP = STUDENT.IDGROUP
	INNER JOIN PROGRESS ON STUDENT.IDSTUDENT = PROGRESS.IDSTUDENT
WHERE FACULTY.FACULTY = '���'
GROUP BY GROUPS.PROFESSION, 
		 PROGRESS.SUBJECT,
		 FACULTY.FACULTY
--------------------------------------------------------------------------------

----------------------------------------7---------------------------------------
--PROGRESS

SELECT *
FROM PROGRESS
ORDER BY NOTE DESC

SELECT NOTE, SUBJECT, COUNT(*)
FROM PROGRESS
GROUP BY NOTE, SUBJECT
HAVING NOTE IN (8, 9)
ORDER BY NOTE
--------------------------------------------------------------------------------