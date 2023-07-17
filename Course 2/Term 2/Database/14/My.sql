--������� �������� �������� � ������������ ����� �������������:
create function COUNT_CLIENTS (@PROPERTY_TYPE nvarchar(50)) returns int
as
begin
	declare @COUNT int = (select count(*)
						  from Clients
						  where ���_������������� = @PROPERTY_TYPE)
	return @COUNT
end

declare @RES int = dbo.COUNT_CLIENTS('�������')
print '���������� ��������: ' + cast(@RES as varchar)

-- �������, ������������ ��� ���� �������� � ������������ �������:
create function FLOAN_TYPES (@RATE real) returns table
as return
	select *
	from Loan_type
	where ������ = @RATE

select * from FLOAN_TYPES(7)

--������� �������� �������� � ������������ ������:
create function FCOUNT_LOANS (@SUM real) returns int
as 
begin
	declare @COUNT int = (select count(*)
						  from Loans
						  where ����� = @SUM)
	return @COUNT
end
print '���������� ��������: ' + cast(dbo.FCOUNT_LOANS(10000) as varchar)
