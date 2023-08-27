-----------------------1-------------------------
CREATE VIEW [�������������]
	AS SELECT TEACHER [���],
			  TEACHER_NAME [���_�������������],
			  GENDER [���],
			  PULPIT [��� �������]
	   FROM TEACHER

SELECT *
FROM [�������������]
-------------------------------------------------

-----------------------2-------------------------
CREATE VIEW [����������_������]
	AS SELECT FACULTY.FACULTY [���������], (SELECT COUNT(*)
			            FROM PULPIT
						WHERE PULPIT.FACULTY = FACULTY.FACULTY) [���-�� ������]
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


SELECT * FROM [����������_������]
-------------------------------------------------

-----------------------3-------------------------
CREATE VIEW [���������](���, �����, ���_���������)
	AS SELECT AUDITORIUM.AUDITORIUM [���],
			  AUDITORIUM.AUDITORIUM_NAME [�����],
			  AUDITORIUM.AUDITORIUM_TYPE [���_���������]
	   FROM AUDITORIUM
	   WHERE AUDITORIUM.AUDITORIUM_TYPE LIKE('��%')

SELECT AUDITORIUM.AUDITORIUM [���],
			  AUDITORIUM.AUDITORIUM_NAME
	   FROM AUDITORIUM
	   WHERE AUDITORIUM.AUDITORIUM_TYPE LIKE('��%')

SELECT * FROM ���������

INSERT ��������� VALUES('236-3', '236-3', '��')
DELETE ��������� WHERE ��� = '236-3'
-------------------------------------------------

-----------------------4-------------------------
CREATE VIEW [����������_���������](���, �����, ���_���������)
	AS SELECT AUDITORIUM.AUDITORIUM [���],
			  AUDITORIUM.AUDITORIUM_NAME [�����],
			  AUDITORIUM.AUDITORIUM_TYPE [���_���������]
	   FROM AUDITORIUM
	   WHERE AUDITORIUM.AUDITORIUM_TYPE LIKE('��%') WITH CHECK OPTION

SELECT AUDITORIUM.AUDITORIUM [���],
			  AUDITORIUM.AUDITORIUM_NAME
	   FROM AUDITORIUM
	   WHERE AUDITORIUM.AUDITORIUM_TYPE LIKE('��%')

SELECT * FROM ���������

INSERT ��������� VALUES('236-3', '236-3', '��')

INSERT ����������_��������� VALUES('236123-3', '236123-3', '����')

UPDATE ��������� SET ��� = 1 WHERE ��� = '236-3'
DELETE ��������� WHERE ��� = '1'
-------------------------------------------------

-----------------------5-------------------------
CREATE VIEW [����������](���, ������������_����������, ���_�������)
	AS SELECT TOP 15 SUBJECT.SUBJECT,
					  SUBJECT.SUBJECT_NAME,
					  SUBJECT.PULPIT
	FROM SUBJECT
	ORDER BY SUBJECT.SUBJECT

SELECT * FROM ����������
-------------------------------------------------

-----------------------6-------------------------
--CREATE VIEW [����������_������]
--	AS SELECT FACULTY.FACULTY [���������], (SELECT COUNT(*)
--			            FROM PULPIT
--						WHERE PULPIT.FACULTY = FACULTY.FACULTY) [���-�� ������]
--	   FROM FACULTY

ALTER VIEW [����������_������] WITH SCHEMABINDING
AS SELECT faculty.FACULTY [���������], COUNT(pulpit.PULPIT_NAME) [���-�� ������]
	FROM dbo.FACULTY faculty
		INNER JOIN dbo.PULPIT pulpit ON pulpit.FACULTY = faculty.FACULTY
	GROUP BY faculty.FACULTY

--ALTER TABLE PULPIT DROP COLUMN FACULTY
-------------------------------------------------