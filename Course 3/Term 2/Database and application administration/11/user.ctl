LOAD DATA
INFILE 'user.csv'
INTO TABLE "UserTable"
FIELDS TERMINATED BY ',' OPTIONALLY ENCLOSED BY '"'
(
    ID,
    Created_at TIMESTAMP "YYYY-MM-DD HH24:MI:SS.FF3",
    Updated_at TIMESTAMP "YYYY-MM-DD HH24:MI:SS.FF3",
    Name CHAR(255) "UPPER(:Name)",
    Password CHAR(255) "UPPER(:Password)",
    User_setting_id INTEGER "ROUND(:User_setting_id, 1)"
)
