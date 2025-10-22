LOAD DATA
INFILE 'task.csv'
INTO TABLE Task
FIELDS TERMINATED BY ',' OPTIONALLY ENCLOSED BY '"'
(
    ID,
    Created_at TIMESTAMP "YYYY-MM-DD HH24:MI:SS.FF3",
    Updated_at TIMESTAMP "YYYY-MM-DD HH24:MI:SS.FF3",
    Name CHAR(255) "UPPER(:Name)",
    Is_Completed "decode(:Is_Completed, 'true', 1, 'false', 0)",
    User_id "ROUND(:User_id, 1)",
    Priority "ROUND(:Priority, 1)"
)
