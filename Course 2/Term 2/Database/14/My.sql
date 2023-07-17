--Функция подсчета клиентов с определенным видом собственности:
create function COUNT_CLIENTS (@PROPERTY_TYPE nvarchar(50)) returns int
as
begin
	declare @COUNT int = (select count(*)
						  from Clients
						  where Вид_собственности = @PROPERTY_TYPE)
	return @COUNT
end

declare @RES int = dbo.COUNT_CLIENTS('Частная')
print 'Количество клиентов: ' + cast(@RES as varchar)

-- Функция, возвращающая все виды кредитов с определенной ставкой:
create function FLOAN_TYPES (@RATE real) returns table
as return
	select *
	from Loan_type
	where Ставка = @RATE

select * from FLOAN_TYPES(7)

--Функция подсчета кредитов с определенной суммой:
create function FCOUNT_LOANS (@SUM real) returns int
as 
begin
	declare @COUNT int = (select count(*)
						  from Loans
						  where Сумма = @SUM)
	return @COUNT
end
print 'Количество кредитов: ' + cast(dbo.FCOUNT_LOANS(10000) as varchar)
