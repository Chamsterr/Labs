CREATE TABLE KNV_t(x number(3) unique , s varchar2(50));

INSERT INTO KNV_t
(x, s)
VALUES
(1, 'Ковкель Никита');

COMMIT;


INSERT ALL
  INTO KNV_t (x, s) VALUES (2, 'Ирина Викторович')
  INTO KNV_t (x, s) VALUES (3, 'Артем Пшенко')
SELECT * FROM dual;

COMMIT;

SELECT * FROM KNV_t;

UPDATE KNV_T
    SET s = 'Ковель Никита Викторович'
WHERE x = 1;

UPDATE KNV_T
    SET s = 'Ирина Викторович Сергеевна'
WHERE x = 2;

COMMIT;

SELECT sum(x)
FROM KNV_T
WHERE x > 1;

INSERT INTO KNV_T
(x, s)
VALUES
(14, 'Никита Ковкель');

DELETE FROM KNV_T
WHERE s = 'Никита Ковкель';

COMMIT;

CREATE TABLE KNV_t1(x number(3), s varchar2(50));

CREATE TABLE KNV_t1 (
    text VARCHAR(255),
    ParentX NUMBER,
    FOREIGN KEY (ParentX) REFERENCES KNV_T(x)
);

INSERT ALL
  INTO KNV_t1 (text, ParentX) VALUES ('пмиртоьл', 1)
  INTO KNV_t1 (text, ParentX) VALUES ('ртоьлбд', 3)
SELECT * FROM dual;

SELECT * FROM KNV_t1;

SELECT *
FROM KNV_t
JOIN KNV_t1 on KNV_t.x = KNV_t1.ParentX;

SELECT *
FROM KNV_t
LEFT JOIN KNV_t1 on KNV_t.x = KNV_t1.ParentX;

SELECT *
FROM KNV_t
RIGHT JOIN KNV_t1 on KNV_t.x = KNV_t1.ParentX;

DROP TABLE KNV_t;
DROP TABLE KNV_t1;