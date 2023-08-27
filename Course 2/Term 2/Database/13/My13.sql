-- Процедура для получения всех клиентов:
CREATE PROCEDURE GetAllClients
AS
BEGIN
	SELECT * FROM Clients
END

-- Процедура для добавления нового клиента:
CREATE PROCEDURE AddClient
	@id INT,
	@Название_фирмы NVARCHAR(50),
	@Вид_собственности NVARCHAR(50),
	@Адрес NVARCHAR(50),
	@Телефон NVARCHAR(50),
	@Контактноe_лицо NVARCHAR(50)
AS
BEGIN
	INSERT INTO Clients VALUES (@id, @Название_фирмы, @Вид_собственности, @Адрес, @Телефон, @Контактноe_лицо)
END

--Процедура для удаления клиента:
CREATE PROCEDURE DeleteClient
	@id INT
AS
BEGIN
	DELETE FROM Clients WHERE id = @id
END

EXEC GetAllClients

EXEC AddClient 
	@id = 100,
	@Название_фирмы = N'Тестовая фирма',
	@Вид_собственности = N'ООО',
	@Адрес = N'Тестовый адрес, 1',
	@Телефон = N'+7 123 456 7890',
	@Контактноe_лицо = N'Иван Иванов'

EXEC DeleteClient @id = 100;