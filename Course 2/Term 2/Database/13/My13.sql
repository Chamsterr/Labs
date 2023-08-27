-- ��������� ��� ��������� ���� ��������:
CREATE PROCEDURE GetAllClients
AS
BEGIN
	SELECT * FROM Clients
END

-- ��������� ��� ���������� ������ �������:
CREATE PROCEDURE AddClient
	@id INT,
	@��������_����� NVARCHAR(50),
	@���_������������� NVARCHAR(50),
	@����� NVARCHAR(50),
	@������� NVARCHAR(50),
	@���������e_���� NVARCHAR(50)
AS
BEGIN
	INSERT INTO Clients VALUES (@id, @��������_�����, @���_�������������, @�����, @�������, @���������e_����)
END

--��������� ��� �������� �������:
CREATE PROCEDURE DeleteClient
	@id INT
AS
BEGIN
	DELETE FROM Clients WHERE id = @id
END

EXEC GetAllClients

EXEC AddClient 
	@id = 100,
	@��������_����� = N'�������� �����',
	@���_������������� = N'���',
	@����� = N'�������� �����, 1',
	@������� = N'+7 123 456 7890',
	@���������e_���� = N'���� ������'

EXEC DeleteClient @id = 100;