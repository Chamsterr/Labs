CREATE TABLESPACE TS_KNV
DATAFILE 'TS_KNV.dbf' SIZE 7M
AUTOEXTEND ON NEXT 5M MAXSIZE 20M;

drop tablespace  TS_KNV;

select TABLESPACE_NAME, STATUS, contents logging from SYS.DBA_TABLESPACES;

CREATE TEMPORARY TABLESPACE TS_KNV_TEMP
TEMPFILE 'TS_KNV_TEMP.dbf' SIZE 5M
AUTOEXTEND ON NEXT 3M MAXSIZE 30M;

select TABLESPACE_NAME, STATUS, contents logging from SYS.DBA_TABLESPACES;

select * from SYS.DBA_TABLESPACES;
select * from SYS.DBA_DATA_FILES;


alter session set "_ORACLE_SCRIPT"=TRUE;
create role RL_KNVCORE;
grant
    connect,
    create table,
    create view,
    create procedure,
    drop any table,
    drop any view,
    drop any procedure
to RL_KNVCORE;

drop role RL_KNVCORE;
--5
select * from DBA_ROLES where ROLE = 'RL_KNVCORE';
select * from DBA_SYS_PRIVS where GRANTEE = 'RL_KNVCORE';

--6
create profile PF_KNVCORE limit
    failed_login_attempts 7     -- число попыток входа в систему
    sessions_per_user 3         -- кол-во сессий на пользователя
    password_life_time 60       -- время жизни пароля
    password_reuse_time 365     -- время до повторного использования пароля
    password_lock_time 1        -- время блокировки пароля
    connect_time 180            -- время подключения
    idle_time 30;               -- время простоя

drop profile PF_KNVCORE cascade;
--7
select * from DBA_PROFILES;
select * from DBA_PROFILES where profile = 'PF_KNVCORE';
select * from DBA_PROFILES where profile = 'DEFAULT';

--8
--SHOW con_name
create user KNVCORE
    identified by "110"
    default tablespace TS_KNV
    temporary tablespace TS_KNV_TEMP
    profile PF_KNVCORE
    account unlock
    password expire;

grant
    create session,
    create table,
    create view,
    drop any table,
    drop any view

to KNVCORE;

drop user KNVCORE;
--
SELECT * FROM DBA_SYS_PRIVS WHERE GRANTEE = 'KNVCORE';

SELECT USER FROM DUAL;

create table TableKNV (
    id number
);
create view ViewKNV as select * from TableKNV;

select * from TableKNV;
drop table TableKNV;
drop view ViewKNV;

create user b identified by "password";
grant all privileges to b;