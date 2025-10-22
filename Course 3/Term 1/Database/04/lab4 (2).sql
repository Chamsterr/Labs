alter session set "_ORACLE_SCRIPT" = true;
--Task 1
select * from DBA_TABLESPACES;

--Task 2
Drop tablespace PNA_QDATA including contents and datafiles;

CREATE TABLESPACE PNA_QDATA
    DATAFILE 'PNA_QDATA.dbf'
    SIZE 10M
    AUTOEXTEND ON
    NEXT 5M
    MAXSIZE 20M
    OFFLINE;
    
drop user C##PNA;

create user C##PNA identified by 111;
grant
    connect,
    create session,
    alter session,
    create any table,
    drop any table,
    SYSDBA
TO C##PNA CONTAINER = all;
    
SELECT * from all_users;
    
ALTER TABLESPACE PNA_QDATA ONLINE;
SELECT tablespace_name, status, contents logging from SYS.DBA_TABLESPACES;

ALTER USER C##PNA QUOTA 2M ON PNA_QDATA;


--Для проверки квоты
SELECT tablespace_name, bytes, max_bytes
FROM dba_ts_quotas
WHERE tablespace_name = 'PNA_QDATA'
AND username = 'C##PNA';

--переключится на юзера 
SELECT * FROM dba_users;

CREATE TABLE PNA_T1(
    X INT PRIMARY KEY,
    Y INT
) TABLESPACE PNA_QDATA;

INSERT INTO PNA_T1(X, Y) VALUES (1,1);
INSERT INTO PNA_T1(X, Y) VALUES (2,2);
INSERT INTO PNA_T1(X, Y) VALUES (3,3);

SELECT * FROM PNA_T1;

--Task 3
SELECT * FROM dba_segments WHERE tablespace_name = 'PNA_QDATA';

--Task 4
DROP TABLE PNA_T1;
-- ЧТО ТО ТИПО КОРЗИНЫ
SELECT * FROM dba_segments WHERE tablespace_name = 'PNA_QDATA';
SELECT * FROM USER_RECYCLEBIN;

--Task 5
flashback table PNA_T1 to before drop;

--Task 6

DECLARE 
    i integer := 4;
BEGIN 
    WHILE i < 10004 LOOP
        INSERT INTO PNA_T1(X,Y) VALUES(i,i);
        i := i + 1;
    END LOOP;
END;

SELECT COUNT(*) FROM PNA_T1;

--Task 7
SELECT extents, bytes, blocks FROM dba_segments WHERE segment_name = 'PNA_T1';
SELECT * FROM dba_extents WHERE segment_name = 'PNA_T1';

--Task 8
DROP tablespace PNA_QDATA including contents and datafiles;

--Task 9
--выводит номера журналов
select group# from v$logfile;

select group# from v$log where status = 'CURRENT';

--Task 10
SELECT member FROM v$logfile;

--Task 11
SELECT group#, status from v$log;
ALTER system switch logfile;  -- выполнить 2 раза и следить, где в v$log status = 'CURRENT'
SELECT TO_CHAR(SYSDATE, 'hh24:MI DD MONTH YYYY') AS CURRENT_DATE FROM DUAL;

SELECT GROUP# FROM v$log WHERE status = 'CURRENT';

--Task 12
ALTER DATABASE ADD logfile
    group 4
    'E:\app\oradata\XE\REDO04.LOG'
    size 50m
    blocksize 512;

select group# from v$logfile;

ALTER DATABASE ADD logfile
    member
    'E:\app\oradata\XE\REDO04_1.LOG'
    to group 4;
    
ALTER DATABASE ADD logfile
    member
    'E:\app\oradata\XE\REDO04_2.LOG'
    to group 4;

ALTER DATABASE ADD logfile
    member
    'E:\app\oradata\XE\REDO04_3.LOG'
    to group 4;
    
SELECT * FROM V$LOG ORDER BY GROUP#;
SELECT * FROM V$LOGFILE ORDER BY GROUP#;
--оккуратно с переходом, следить за каждым шагом
ALTER system switch logfile;
SELECT GROUP#, STATUS FROM V$LOG;
SELECT GROUP# FROM V$LOG WHERE STATUS = 'CURRENT';


--Task 13 (Trouble)
alter database drop logfile member 'E:\app\oradata\XE\REDO04_1.LOG';
alter database drop logfile member 'E:\app\oradata\XE\REDO04_2.LOG';
alter database drop logfile member 'E:\app\oradata\XE\REDO04_3.LOG';
ALTER DATABASE DROP logfile group4;

--Task 14 
SELECT DBID, NAME, LOG_MODE from v$database;
SELECT INSTANCE_NAME, ARCHIVER, ACTIVE_STATE FROM V$INSTANCE;

--Task 15
SELECT * FROM V$ARCHIVED_LOG;

--Task 16
--включить архивирование 
--заходим в SQLPLUS
--connect /as sysdba  or  sys .as sysdba;
--shutdown immediate;
--statrup mount;
--alter database archivelog;
--alter database open;

SELECT DBID, NAME, LOG_MODE FROM V$DATABASE;
SELECT INSTANCE_NAME, ARCHIVED, ACTIVE_STATE FROM V$INSTANCE;

--Task 17
ALTER system switch logfile;
SELECT group# from v$log where status = 'CURRENT';
SELECT * FROM v$archived_log;

--Task 18
--выключить архивирование
--SQL PLUS
-- connect /as sysdba or ect;
-- shutdown immediate;
-- startup mount;
-- alter database noarchivelog;
-- alter database open;

-- должно быть LOG_MODE = NOARCHIVELOG; ARCHIVER = STOPPED
select DBID, name, LOG_MODE from v$database;
select INSTANCE_NAME, ARCHIVER, ATCIVE_STATE from v$instance;

--Task 19
select * from v$controlfile;

--Task 20
show parametr control_files;
select * from v$controlfile_record_section;

--Task 21
show patametr pfile;

--Task 22
show pfile = 'PNA_PFILE.ora' from spfile;

--Task 23
select * from v$pwfile_users;
show parameter remote_login_passwordfile;

--Task 24
select * from v$diag_info;

--Task 25



    