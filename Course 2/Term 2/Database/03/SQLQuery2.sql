
SELECT * FROM Loans
UPDATE Loans set Код_клиента = 3 where id in (2);

DROP DATABASE KOVK_MyBase_02;

DROP DATABASE IF EXISTS KOVK_MyBase_02_test;

CREATE DATABASE KOVK_MyBase_02_test
ON PRIMARY
(
	NAME = N'KOVK_MyBase_02_test_mdf',
	FILENAME = N'D:\Labs\Course 2\Term 2\Database\03\KOVK_MyBase_02_test.mdf',
	SIZE = 10240KB,
	MAXSIZE = UNLIMITED,
	FILEGROWTH = 1024KB
),
(
	NAME = N'KOVK_MyBase_02_test_log',
	FILENAME = N'D:\Labs\Course 2\Term 2\Database\03\KOVK_MyBase_02_test.ndf',
	SIZE = 10240KB,
	MAXSIZE = 2048GB,
	FILEGROWTH = 10%
),
FILEGROUP FG1
(
	NAME = N'KOVK_MyBase_02_test_1',
	FILENAME = N'D:\Labs\Course 2\Term 2\Database\03\KOVK_MyBase_02_test_1.ndf',
	SIZE = 10240KB,
	MAXSIZE = 1GB,
	FILEGROWTH = 25%
),
(
	NAME = N'KOVK_MyBase_02_test_2',
	FILENAME = N'D:\Labs\Course 2\Term 2\Database\03\KOVK_MyBase_02_test_2.ndf',
	SIZE = 10240KB,
	MAXSIZE = 1GB,
	FILEGROWTH = 25%
)
LOG ON
(
	NAME = N'KOVK_MyBase_02_test_log',
	FILENAME = N'D:\Labs\Course 2\Term 2\Database\03\KOVK_MyBase_02_test_log.ldf',
	SIZE = 10240KB,
	MAXSIZE = 2048GB,
	FILEGROWTH = 10%
);