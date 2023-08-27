use Kovkel_MyBase_03
Create table Clients
(
	id int primary key not null,
	��������_����� nvarchar(10) not null,
	���_������������� nvarchar(50) not null, 
	����� nvarchar(50) not null,
	������� int not null,
	���������e_���� nvarchar(10) not null
);

Create table Loan_type
(
	id int primary key not null,
	��������_����_������� nvarchar(50) not null,
	������ real not null
);

Create table Loans
(
	id int primary key not null,
	���_���� int foreign key references Loan_type(id),
	���_������� int foreign key references Clients(id),
	����� real not null,
	����_�������� date not null,
	����_������ date not null
);

ALTER Table Loans ADD test int;

ALTER Table Loans ADD test2 nchar(1) default 1 check (test2 in (1, 2));

ALTER Table Loans DROP Column test;
ALTER Table Loans DROP Column test2;

ALTER TABLE Clients
ALTER COLUMN ��������_����� nvarchar(50)

ALTER TABLE Clients
ALTER COLUMN ���������e_���� nvarchar(50)

ALTER TABLE Clients
ALTER COLUMN ������� nvarchar(50)



INSERT into Clients (id, ��������_�����, ���_�������������, �����, �������, ���������e_����)
			  values(1, '������', '�������', '���������� 11', '123213123', '���� ������'),
					(2, '����� ����', '���������������', '����� 15', '9876876', '������ ����������'),
					(3, '���������� ����', '�������', '��. ����������� 4', '+7 (495) 567-89-01', '����� ����������'),
					(4, '������������� ���������', '���������������', '��-� ������������� 12', '+7 (495) 234-56-78', '������� �������������'),
					(5, '������ �����������', '�������', '��. ��������� 8', '+7 (499) 321-54-76', '��������� ����������')


INSERT into Clients (id, ��������_�����, ���_�������������, �����, �������, ���������e_����)
			  values(6, '������� �������', '�������', '��. ���������� 20', '+7 (495) 123-45-67', '���� ���������');

INSERT into Loan_type(id, ��������_����_�������, ������)
			  values(1, '�������', 20),
					(2, '������', 7),
					(3, '�����', 1213)

INSERT INTO Loans (id, ���_����, ���_�������, �����, ����_��������, ����_������)
			VALUES (1, 1, 1, 10000, '2023-04-01', '2023-03-01'),
			(2, 2, 2, 50000, '2023-05-01', '2023-03-01'),
			(3, 3, 3, 1000, '2023-06-01', '2023-03-01'),
			(4, 1, 4, 20000, '2023-07-01', '2023-03-01'),
			(5, 2, 5, 30000, '2023-08-01', '2023-03-01');

			 
SELECT * FROM Loans
SELECT ����_��������, ����_������ FROM Loans

SELECT COUNT(*) FROM Loans

UPDATE Loans set ���_������� = 1;

--������� ���� ��� ���� �������� ��������� � ����� �� ��������� ��� ������� �������� � ���� 1 � ����� 1000 ��� 50000