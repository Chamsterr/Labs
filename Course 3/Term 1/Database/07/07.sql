-- Все задания, начиная со 2-го, необходимо выполнять в рамках соединения
-- пользователя XXX (у каждого студента собственный пользователь и инфраструктура)
-- в своей PDB.

-- Рабочий способ (и правильный):
-- Делаем коннект от SYS к PDB и там создаем юзера

alter pluggable database KNV_PDB open;
-- Смотрим к чему мы подключены
show con_name;

create tablespace TS_KNV
  DATAFILE 'TS_KNV_LAB7_PDB.dbf'
  size 7M
  autoextend ON
  next 5M
  maxsize 20M;

create temporary tablespace TS_KNV_TEMP
  tempfile 'TS_KNV_TEMP_LAB7_PDB.dbf'
  size 5M
  autoextend ON
  next 3M
  maxsize 30M;

select TABLESPACE_NAME, STATUS, contents logging from SYS.DBA_TABLESPACES;
drop tablespace TS_KNV including contents and datafiles;
drop tablespace TS_KNV_TEMP including contents and datafiles;

CREATE PROFILE PF_KNV2 LIMIT
  FAILED_LOGIN_ATTEMPTS 7
  SESSIONS_PER_USER 3
  PASSWORD_LIFE_TIME 60
  PASSWORD_REUSE_TIME 365
  PASSWORD_LOCK_TIME 1
  CONNECT_TIME 180;

select * from DBA_PROFILES where profile = 'PF_KNV';
drop profile PF_KNV;


CREATE USER KNV2 identified by 111
  DEFAULT TABLESPACE TS_KNV2
  TEMPORARY TABLESPACE TS_KNV2_TEMP
  PROFILE PF_KNV2
  ACCOUNT UNLOCK;

select * from dba_users where USERNAME like 'KNV';
drop user KNV;

-- !!! Роли в PDB не работают, поэтому грант делаем сами (тут вроде все,
-- что нужно, если чего то нет, добавляйте по ходу)
GRANT CREATE SESSION TO KNV;
GRANT RESTRICTED SESSION TO KNV;
GRANT CREATE ANY TABLE TO KNV;
GRANT CREATE ANY VIEW TO KNV;
GRANT CREATE SEQUENCE TO KNV;
GRANT UNLIMITED TABLESPACE TO KNV;
GRANT CREATE CLUSTER TO KNV;
GRANT CREATE SYNONYM TO KNV;
GRANT CREATE PUBLIC SYNONYM TO KNV;
GRANT CREATE MATERIALIZED VIEW TO KNV;

select * from USER_SYS_PRIVS where username = 'KNV';

-- 1. Прочитайте задание полностью и выдайте своему пользователю необходимые права.

-- По факту, создаем коннект с юзером, которого мы создали выше
-- Если не помним как делать коннект, welcome to Lab3

-- 2. Создайте последовательность S1 (SEQUENCE), со следующими характеристиками:
-- начальное значение 1000;
-- приращение 10;
-- нет минимального значения;
-- нет максимального значения;
-- не циклическая;
-- значения не кэшируются в памяти;
-- хронология значений не гарантируется.
-- Получите несколько значений последовательности. Получите текущее значение последовательности.

create sequence S1
  start with 1000
  increment by 10
  nominvalue
  nomaxvalue
  nocycle
  nocache
  noorder;

select S1.NEXTVAL from DUAL;
select S1.CURRVAL from DUAL;

-- 3. Создайте последовательность S2 (SEQUENCE), со следующими характеристиками:
-- начальное значение 10;
-- приращение 10;
-- максимальное значение 100;
-- не циклическую.
-- Получите все значения последовательности.
-- Попытайтесь получить значение, выходящее за максимальное значение.

create sequence S2
  start with 10
  increment by 10
  maxvalue 100
  nocycle;

select S2.NEXTVAL from DUAL;

-- 5. Создайте последовательность S3 (SEQUENCE), со следующими характеристиками:
-- начальное значение 10;
-- приращение -10;
-- минимальное значение -100;
-- не циклическую;
-- гарантирующую хронологию значений.
-- Получите все значения последовательности.
-- Попытайтесь получить значение, меньше минимального значения.

create sequence S3
  start with 10
  increment by -10
  minvalue -100
  maxvalue 100
  nocycle
  order;

select S3.NEXTVAL from DUAL;

-- 6. Создайте последовательность S4 (SEQUENCE), со следующими характеристиками:
-- начальное значение 1;
-- приращение 1;
-- минимальное значение 10;
-- циклическая;
-- кэшируется в памяти 5 значений;
-- хронология значений не гарантируется.
-- Продемонстрируйте цикличность генерации значений последовательностью S4.

create sequence S4
  start with 1
  increment by 1
  maxvalue 10
  cycle
  cache 5
  noorder;

select S4.NEXTVAL from DUAL;

-- 7. Получите список всех последовательностей в словаре базы данных,
-- владельцем которых является пользователь XXX.
SELECT * FROM ALL_SEQUENCES WHERE SEQUENCE_OWNER = 'KNV';
DROP SEQUENCE S1;
DROP SEQUENCE S2;
DROP SEQUENCE S3;
DROP SEQUENCE S4;

-- 8. Создайте таблицу T1, имеющую столбцы N1, N2, N3, N4, типа NUMBER (20),
-- кэшируемую и расположенную в буферном пуле KEEP.
-- С помощью оператора INSERT добавьте 7 строк, вводимое значение для столбцов
-- должно формироваться с помощью последовательностей S1, S2, S3, S4.

CREATE TABLE T1 (
  N1 NUMBER(20),
  N2 NUMBER(20),
  N3 NUMBER(20),
  N4 NUMBER(20)
) CACHE STORAGE ( BUFFER_POOL KEEP ) tablespace TS_KNV;

ALTER TABLE T1 STORAGE (BUFFER_POOL KEEP);

INSERT INTO T1(N1, N2, N3, N4)
    VALUES (S1.CURRVAL, S2.CURRVAL, S3.CURRVAL, S4.CURRVAL);

SELECT * FROM T1;


-- 9. Создайте кластер ABC, имеющий hash-тип (размер 200) и
-- содержащий 2 поля: X (NUMBER (10)), V (VARCHAR2(12)).
CREATE CLUSTER ABC (
  X NUMBER(10),
  V VARCHAR2(12)
) SIZE 200 HASHKEYS 200;

-- 10. Создайте таблицу A, имеющую столбцы XA (NUMBER (10)) и VA (VARCHAR2(12)),
-- принадлежащие кластеру ABC, а также еще один произвольный столбец.
CREATE TABLE A (
  XA NUMBER(10),
  VA VARCHAR2(12),
  Y NUMBER(10)
) CLUSTER ABC(XA, VA);

-- 11. Создайте таблицу B, имеющую столбцы XB (NUMBER (10)) и VB (VARCHAR2(12)),
-- принадлежащие кластеру ABC, а также еще один произвольный столбец.
CREATE TABLE B (
  XB NUMBER(10),
  VB VARCHAR2(12),
  Z NUMBER(10)
) CLUSTER ABC(XB, VB);

INSERT INTO B VALUES (1, '1', 1);

-- 12. Создайте таблицу С, имеющую столбцы XС (NUMBER (10)) и VС (VARCHAR2(12)),
-- принадлежащие кластеру ABC, а также еще один произвольный столбец.
CREATE TABLE C (
  XC NUMBER(10),
  VC VARCHAR2(12),
  W NUMBER(10)
) CLUSTER ABC(XC, VC);

INSERT INTO C VALUES (1, '1', 1);

-- 13. Найдите созданные таблицы и кластер в представлениях словаря Oracle.
SELECT TABLE_NAME FROM USER_TABLES;
SELECT CLUSTER_NAME FROM USER_CLUSTERS;

-- 14. Создайте частный синоним для таблицы XXX.С и продемонстрируйте его применение.
CREATE SYNONYM SC FOR KNV.C;
SELECT * FROM C;
SELECT * FROM SC;

-- 15. Создайте публичный синоним для таблицы XXX.B и продемонстрируйте его применение.
CREATE PUBLIC SYNONYM SB FOR KNV.B;
SELECT * FROM SB;


-- 16. Создайте две произвольные таблицы A и B (с первичным и внешним ключами),
-- заполните их данными, создайте представление V1,
-- основанное на SELECT... FOR A inner join B.
-- Продемонстрируйте его работоспособность.
CREATE TABLE A16 (
  XA NUMBER(10),
  VA VARCHAR2(12),
  Y NUMBER(10),
  CONSTRAINT PK_A16 PRIMARY KEY (XA)
);

CREATE TABLE B16 (
  XB NUMBER(10),
  VB VARCHAR2(12),
  Z NUMBER(10),
  CONSTRAINT FK_B16 FOREIGN KEY (XB) REFERENCES A16(XA)
);

INSERT INTO A16 VALUES (2, '1', 1);
INSERT INTO B16 VALUES (2, '1', 1);

CREATE VIEW V1 AS
  SELECT * FROM A16
  INNER JOIN B16 ON A16.XA = B16.XB;

SELECT * FROM V1;

-- 17. На основе таблиц A и B создайте материализованное представление MV,
-- которое имеет периодичность обновления 2 минуты.
-- Продемонстрируйте его работоспособность.
CREATE MATERIALIZED VIEW MV
  REFRESH FORCE ON DEMAND
  next SYSDATE + 2/1440
  as
    select * from A16
    inner join
    B16
    on A16.XA = B16.XB;

select * from MV;