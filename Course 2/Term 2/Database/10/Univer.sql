-------------------1-----------------
exec sp_helpindex 'AUDITORIUM_TYPE'

DROP TABLE IF EXISTS #TempTable;

CREATE TABLE #TempTable (
    ID INT,
    Name NVARCHAR(50)
);

DECLARE @ID INT
DECLARE @Name NVARCHAR(50)

SET @ID = 1
SET @Name = 'Name';

WHILE @ID < 1000
BEGIN
	INSERT INTO #TempTable (ID, Name)
	VALUES (@ID, @Name);
	SET @ID = @ID + 1;
	SET @Name = 'Name' + CAST(@ID AS nvarchar(10));
END

SELECT *
FROM #TempTable

SELECT ID
FROM #TempTable

checkpoint; --фиксация БД
DBCC DROPCLEANBUFFERS; --очистить буферный кэш

CREATE CLUSTERED INDEX #TempTable_CIN ON #TempTable(ID)
DROP INDEX #TempTable_CIN
DROP TABLE IF EXISTS #TempTable;
-------------------------------------

-------------------2-----------------
DROP TABLE IF EXISTS #TempTable2;

CREATE TABLE #TempTable2 (
    ID INT,
    Name NVARCHAR(50)
);

DECLARE @ID2 INT
DECLARE @Name2 NVARCHAR(50)
SET @ID2 = 1
SET @Name2 = 'Name';

WHILE @ID2 < 10000
BEGIN
	INSERT INTO #TempTable2 (ID, Name)
	VALUES (@ID2, @Name2);
	SET @ID2 = @ID2 + 1;
	SET @Name2 = 'Name' + CAST(@ID2 AS nvarchar(10));
END

SELECT *
FROM #TempTable2

CREATE INDEX #TempTable2_NONCLU ON #TempTable2(ID, Name)


SELECT *
FROM #TempTable2
WHERE ID < 500 AND Name LIKE '%';

SELECT *
FROM #TempTable2
WHERE ID = 500 AND Name LIKE '%';

DROP TABLE IF EXISTS #TempTable2;
-------------------------------------

-------------------3-----------------
DROP TABLE IF EXISTS #TempTable3;

CREATE TABLE #TempTable3 (
    ID INT,
    Name NVARCHAR(50)
);

DECLARE @ID3 INT
DECLARE @Name3 NVARCHAR(50)
SET @ID3 = 1
SET @Name3 = 'Name';

WHILE @ID3 < 10000
BEGIN
	INSERT INTO #TempTable3 (ID, Name)
	VALUES (@ID3, @Name3);
	SET @ID3 = @ID3 + 1;
	SET @Name3 = 'Name' + CAST(@ID3 AS nvarchar(10));
END

CREATE INDEX #TempTable3_INDEX ON #TempTable3(ID) INCLUDE (Name)

SELECT Name
FROM #TempTable3
WHERE ID = 5


-------------------------------------

-------------------4-----------------
CREATE INDEX #TempTable3_INDEX_FILTER ON #TempTable3(ID) WHERE (ID > 500 AND ID < 1500)
-------------------------------------

-------------------5-----------------
USE tempdb
DROP TABLE IF EXISTS #TempTable3;

CREATE TABLE #TempTable3 (
    ID INT,
    Name NVARCHAR(50)
);

DECLARE @ID3_2 INT
DECLARE @Name3_2 NVARCHAR(50)
SET @ID3_2 = 1
SET @Name3_2 = 'Name';

WHILE @ID3_2 < 10000
BEGIN
	INSERT INTO #TempTable3 (ID, Name)
	VALUES (@ID3_2, @Name3_2);
	SET @ID3_2 = @ID3_2 + 1;
	SET @Name3_2 = 'Name' + CAST(@ID3_2 AS nvarchar(10));
END

CREATE INDEX #TempTable3_NONCLU ON #TempTable3(ID, Name)
USE tempdb
SELECT NAME [Индекс], AVG_FRAGMENTATION_IN_PERCENT [Фрагментация (%)]
FROM SYS.DM_DB_INDEX_PHYSICAL_STATS(DB_ID(N'tempdb'),
OBJECT_ID(N'#TempTable3'), NULL, NULL, NULL) SS
JOIN SYS.INDEXES II ON SS.OBJECT_ID = II.OBJECT_ID
AND SS.INDEX_ID = II.INDEX_ID WHERE NAME IS NOT NULL;
USE Univer2
DECLARE @Counter int;
SET @Counter = 1;
WHILE @Counter < 150
BEGIN
	INSERT top(10000) #TempTable3(ID, Name) SELECT ID, Name FROM #TempTable3;
	SET @Counter = @Counter + 1; 
END

DROP TABLE #TempTable3
ALTER INDEX #TempTable3_NONCLU ON #TempTable3 reorganize;
ALTER INDEX #TempTable3_NONCLU ON #TempTable3 REBUILD WITH(ONLINE = OFF);
-------------------------------------

-------------------6-----------------
DROP INDEX #TempTable3_NONCLU ON #TempTable3
CREATE INDEX #TempTable3_NONCLU ON #TempTable3(ID) WITH (FILLFACTOR = 65)
-------------------------------------