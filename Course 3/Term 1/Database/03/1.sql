--1
SELECT * FROM v$pdbs;
--2
SELECT instance_name, host_name FROM v$instance;
--3
SELECT comp_id, comp_name, version, status FROM dba_registry;
select  * from V_$PDBS;
--4
CREATE USER KNVCORE IDENTIFIED BY "123321";

alter session set container = CDB$ROOT;
CREATE PLUGGABLE DATABASE KNV_PDB3
ADMIN USER SYSDBA
IDENTIFIED BY booble34
FILE_NAME_CONVERT = ('pdbseed', 'new_pdb3');
select * from dba_pdbs;select * from dba_pdbs;

-- conn c##knv/123321@//localhost:1521/KNV_PDB as SYSDBA
--
create pluggable database KNV_PDB2 admin user sysdba identified by booble34
file_name_convert=('/opt/oracle/oradata/XE/pdbseed/' , '/opt/oracle/oradata/XE/pdb2/');
--
--!connect sys as sydba
alter session set container = CDB$ROOT;
alter pluggable database KNV_PDB3 open  read write force;
--
alter session set container = KNV_PDB3;
grant create session to SYSDBA container =current ;
grant sysdba to SYSDBA container = current ;
--5
alter session set container = CDB$ROOT;
select name from V_$PDBS;


































--TASK 1, 3
SELECT name, open_mode FROM v$pdbs;
alter pluggable database INS_PDB open;
select instance_name, con_id, version from v$instance;
--TASK 4
ALTER SESSION SET CONTAINER = INS_PDB;

create tablespace TS_INS_PDB
datafile 'ts_ins_pdb.dbf'
size 7M
autoextend on next 5M
maxsize 20M
extent management local;


create temporary tablespace TS_KVS_PDB_TEMP
tempfile 'ts_ins_pdb_temp.dbf'
size 5M
autoextend on next 3M
maxsize 30M
extent management local;

alter session set "_ORACLE_SCRIPT"=true;

create role RL_INSCORE_PDB;

grant create session,
      create table, drop any table,
      create view, drop any view,
      create procedure, drop any procedure
to RL_INSCORE_PDB;

create profile PF_INSCORE_PDB limit
    password_life_time unlimited
    sessions_per_user 3
    failed_login_attempts 30
    password_lock_time 1
    password_reuse_time 10
    connect_time 180
    idle_time 30;
commit;
create user U1_INS_PDB identified by Pa$$w0rd
  default tablespace TS_INS_PDB quota unlimited on TS_INS_PDB
  temporary tablespace TS_INS_PDB_TEMP
  profile PF_INSCORE_PDB
  account unlock;

grant RL_INSCORE_PDB to U1_INS_PDB;


SELECT owner, object_name, object_type
FROM all_objects
WHERE owner IN ('C##INS', 'U1_INS_PDB', 'c##INS1')
ORDER BY owner, object_type, object_name;

create user c##INS1 identified by pass;

grant create session to c##INS1;

ALTER USER C##INS1 QUOTA 2M ON TS_INS;

select TABLESPACE_NAME from dba_tablespaces;


select *from v$session;