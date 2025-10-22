SELECT USER FROM DUAL;

create table TableKNV (
    id number
);

DROP TABLE TableKNV;

create view ViewKNV as select * from TableKNV;

select * from ViewKNV;
drop table TableKNV;
drop view ViewKNV;