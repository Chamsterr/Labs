use Kovkel_MyBase_03
Create table Clients
(
	id int primary key not null,
	Название_фирмы nvarchar(10) not null,
	Вид_собственности nvarchar(50) not null, 
	Адрес nvarchar(50) not null,
	Телефон int not null,
	Контактноe_лицо nvarchar(10) not null
);

Create table Loan_type
(
	id int primary key not null,
	Название_вида_кредита nvarchar(50) not null,
	Ставка real not null
);

Create table Loans
(
	id int primary key not null,
	Код_вида int foreign key references Loan_type(id),
	Код_клиента int foreign key references Clients(id),
	Сумма real not null,
	Дата_возврата date not null,
	Дата_выдачи date not null
);

ALTER Table Loans ADD test int;

ALTER Table Loans ADD test2 nchar(1) default 1 check (test2 in (1, 2));

ALTER Table Loans DROP Column test;
ALTER Table Loans DROP Column test2;

ALTER TABLE Clients
ALTER COLUMN Название_фирмы nvarchar(50)

ALTER TABLE Clients
ALTER COLUMN Контактноe_лицо nvarchar(50)

ALTER TABLE Clients
ALTER COLUMN Телефон nvarchar(50)



INSERT into Clients (id, Название_фирмы, Вид_собственности, Адрес, Телефон, Контактноe_лицо)
			  values(1, 'Крутая', 'частная', 'Крутетская 11', '123213123', 'Илья Иванов'),
					(2, 'Тихие Львы', 'государственная', 'Тихая 15', '9876876', 'Никита Викторович'),
					(3, 'Креативные Идеи', 'частная', 'ул. Фантазийная 4', '+7 (495) 567-89-01', 'Ольга Николаевна'),
					(4, 'Профессионалы Логистики', 'государственная', 'пр-т Логистический 12', '+7 (495) 234-56-78', 'Дмитрий Александрович'),
					(5, 'Лучшие Маркетологи', 'частная', 'ул. Рекламная 8', '+7 (499) 321-54-76', 'Екатерина Викторовна')


INSERT into Clients (id, Название_фирмы, Вид_собственности, Адрес, Телефон, Контактноe_лицо)
			  values(6, 'Быстрые Курьеры', 'частная', 'ул. Скоростная 20', '+7 (495) 123-45-67', 'Анна Сергеевна');

INSERT into Loan_type(id, Название_вида_кредита, Ставка)
			  values(1, 'Быстрый', 20),
					(2, 'Долгий', 7),
					(3, 'Микро', 1213)

INSERT INTO Loans (id, Код_вида, Код_клиента, Сумма, Дата_возврата, Дата_выдачи)
			VALUES (1, 1, 1, 10000, '2023-04-01', '2023-03-01'),
			(2, 2, 2, 50000, '2023-05-01', '2023-03-01'),
			(3, 3, 3, 1000, '2023-06-01', '2023-03-01'),
			(4, 1, 4, 20000, '2023-07-01', '2023-03-01'),
			(5, 2, 5, 30000, '2023-08-01', '2023-03-01');

			 
SELECT * FROM Loans
SELECT Дата_возврата, Дата_выдачи FROM Loans

SELECT COUNT(*) FROM Loans

UPDATE Loans set Код_клиента = 1;

--Вывести айди где дата возврата находится в каком то диапозоне код клиента содержит в себе 1 и сумма 1000 или 50000