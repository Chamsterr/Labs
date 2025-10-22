CREATE OR REPLACE TYPE user_type AS OBJECT (
    ID NUMBER,
    Created_at DATE,
    Updated_at DATE,
    Name VARCHAR2(255),
    Password VARCHAR2(255),
    User_setting_id NUMBER,
    MAP MEMBER FUNCTION get_id RETURN NUMBER,
    MEMBER FUNCTION get_name RETURN VARCHAR2,
    MEMBER PROCEDURE set_name(new_name IN VARCHAR2)
);
/

CREATE OR REPLACE TYPE BODY user_type AS
    MAP MEMBER FUNCTION get_id RETURN NUMBER IS
    BEGIN
        RETURN ID;
    END;

    MEMBER FUNCTION get_name RETURN VARCHAR2 IS
    BEGIN
        RETURN Name;
    END;

    MEMBER PROCEDURE set_name(new_name IN VARCHAR2) IS
    BEGIN
        Name := new_name;
    END;
END;
/

CREATE OR REPLACE TYPE task_type AS OBJECT (
    ID NUMBER,
    Created_at DATE,
    Updated_at DATE,
    Name VARCHAR2(255),
    Is_Completed NUMBER(1),
    User_id NUMBER,
    Priority NUMBER,

    MAP MEMBER FUNCTION get_id RETURN NUMBER DETERMINISTIC,
    MEMBER FUNCTION get_name RETURN VARCHAR2,
    MEMBER PROCEDURE set_name(new_name IN VARCHAR2)
);
/

CREATE OR REPLACE TYPE BODY task_type AS
    MAP MEMBER FUNCTION get_id RETURN NUMBER IS
    BEGIN
        RETURN ID;
    END;

    MEMBER FUNCTION get_name RETURN VARCHAR2 IS
    BEGIN
        RETURN Name;
    END;

    MEMBER PROCEDURE set_name(new_name IN VARCHAR2) IS
    BEGIN
        Name := new_name;
    END;
END;
/

CREATE TABLE object_user OF user_type;
CREATE TABLE object_task OF task_type;

DROP TABLE object_task;
DROP TABLE object_user;
select * from "UserTable";

BEGIN
    FOR user_rec IN (SELECT * FROM "UserTable") LOOP
        INSERT INTO object_user VALUES (
            user_type(user_rec.ID, user_rec.Created_at, user_rec.Updated_at, user_rec.Name, user_rec.Password, user_rec.User_setting_id)
        );
    END LOOP;
    COMMIT;
END;
/

BEGIN
    FOR task_rec IN (SELECT * FROM task) LOOP
        INSERT INTO object_task VALUES (
            task_type(task_rec.ID, task_rec.Created_at, task_rec.Updated_at, task_rec.Name, task_rec.Is_Completed, task_rec.User_id, task_rec.Priority)
        );
    END LOOP;
    COMMIT;
END;
/

select * from object_task;
select * from object_user;

CREATE OR REPLACE VIEW user_view AS
SELECT VALUE(u) AS user_obj
FROM object_user u;

CREATE OR REPLACE VIEW task_view AS
SELECT VALUE(u) AS task_obj
FROM object_task u;


SELECT * FROM user_view;
SELECT * FROM task_view;

drop view task_view;
drop view user_view;

CREATE INDEX task_priority_index ON object_task (Priority);
select * from object_task where  Priority = 1;


CREATE OR REPLACE FUNCTION get_user_id(u user_type) RETURN NUMBER DETERMINISTIC IS
BEGIN
  RETURN u.get_id();
END;
/


CREATE TABLE tasks_with_index (
    task task_type
);


CREATE BITMAP INDEX task_id_index ON tasks_with_index (task.get_id());

SELECT COUNT(*) FROM tasks_with_index t
WHERE t.task.get_id() < 3;

INSERT INTO tasks_with_index (task) VALUES (task_type(1, SYSDATE, SYSDATE, 'Task Name', 0, 1, 1));

SELECT * FROM tasks_with_index;