-----------------------1-------------------------
CREATE VIEW [Преподаватель]
	AS SELECT TEACHER [Код],
			  TEACHER_NAME [Имя_преподавателя],
			  GENDER [Пол],
			  PULPIT [Код кафедры]
	   FROM TEACHER

SELECT *
FROM [Преподаватель]
-------------------------------------------------

-----------------------2-------------------------
CREATE VIEW [Количество_кафедр]
	AS SELECT FACULTY.FACULTY [Факультет], (SELECT COUNT(*)
			            FROM PULPIT
						WHERE PULPIT.FACULTY = FACULTY.FACULTY) [Кол-во кафедр]
	   FROM FACULTY


SELECT FACULTY.FACULTY, (SELECT COUNT(*)
			            FROM PULPIT
						WHERE PULPIT.FACULTY = FACULTY.FACULTY)
FROM FACULTY

SELECT FACULTY.FACULTY, COUNT(PULPIT.PULPIT_NAME)
FROM FACULTY
	INNER JOIN PULPIT ON PULPIT.FACULTY = FACULTY.FACULTY
WHERE PULPIT.FACULTY = FACULTY.FACULTY
GROUP BY FACULTY.FACULTY


SELECT * FROM [Количество_кафедр]
-------------------------------------------------

-----------------------3-------------------------
CREATE VIEW [Аудитории](Код, Номер, Тип_Аудитории)
	AS SELECT AUDITORIUM.AUDITORIUM [Код],
			  AUDITORIUM.AUDITORIUM_NAME [Номер],
			  AUDITORIUM.AUDITORIUM_TYPE [Тип_Аудитории]
	   FROM AUDITORIUM
	   WHERE AUDITORIUM.AUDITORIUM_TYPE LIKE('ЛК%')

SELECT AUDITORIUM.AUDITORIUM [Код],
			  AUDITORIUM.AUDITORIUM_NAME
	   FROM AUDITORIUM
	   WHERE AUDITORIUM.AUDITORIUM_TYPE LIKE('ЛК%')

SELECT * FROM Аудитории

INSERT Аудитории VALUES('236-3', '236-3', 'ЛК')
DELETE Аудитории WHERE Код = '236-3'
-------------------------------------------------

-----------------------4-------------------------
CREATE VIEW [Лекционные_аудитории](Код, Номер, Тип_Аудитории)
	AS SELECT AUDITORIUM.AUDITORIUM [Код],
			  AUDITORIUM.AUDITORIUM_NAME [Номер],
			  AUDITORIUM.AUDITORIUM_TYPE [Тип_Аудитории]
	   FROM AUDITORIUM
	   WHERE AUDITORIUM.AUDITORIUM_TYPE LIKE('ЛК%') WITH CHECK OPTION

SELECT AUDITORIUM.AUDITORIUM [Код],
			  AUDITORIUM.AUDITORIUM_NAME
	   FROM AUDITORIUM
	   WHERE AUDITORIUM.AUDITORIUM_TYPE LIKE('ЛК%')

SELECT * FROM Аудитории

INSERT Аудитории VALUES('236-3', '236-3', 'ЛК')

INSERT Лекционные_аудитории VALUES('236123-3', '236123-3', 'фвфв')

UPDATE Аудитории SET Код = 1 WHERE Код = '236-3'
DELETE Аудитории WHERE Код = '1'
-------------------------------------------------

-----------------------5-------------------------
CREATE VIEW [Дисциплины](код, наименование_дисциплины, код_кафедры)
	AS SELECT TOP 15 SUBJECT.SUBJECT,
					  SUBJECT.SUBJECT_NAME,
					  SUBJECT.PULPIT
	FROM SUBJECT
	ORDER BY SUBJECT.SUBJECT

SELECT * FROM Дисциплины
-------------------------------------------------

-----------------------6-------------------------
--CREATE VIEW [Количество_кафедр]
--	AS SELECT FACULTY.FACULTY [Факультет], (SELECT COUNT(*)
--			            FROM PULPIT
--						WHERE PULPIT.FACULTY = FACULTY.FACULTY) [Кол-во кафедр]
--	   FROM FACULTY

ALTER VIEW [Количество_кафедр] WITH SCHEMABINDING
AS SELECT faculty.FACULTY [Факультет], COUNT(pulpit.PULPIT_NAME) [Кол-во кафедр]
	FROM dbo.FACULTY faculty
		INNER JOIN dbo.PULPIT pulpit ON pulpit.FACULTY = faculty.FACULTY
	GROUP BY faculty.FACULTY

--ALTER TABLE PULPIT DROP COLUMN FACULTY
-------------------------------------------------