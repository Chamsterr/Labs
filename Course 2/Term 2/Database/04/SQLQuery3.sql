SELECT *
FROM Loans
JOIN Loan_type ON Loans.Код_вида = Loan_type.id
---------------------------------------------------

SELECT *
FROM Loans
JOIN Loan_type ON Loan_type.id = Loans.Код_вида and Название_вида_кредита LIKE ('Быс%')
---------------------------------------------------

SELECT Контактноe_лицо, Телефон,
case
	when Вид_собственности like ('гос%') then 'Вежливо'
	else '...'
end as [Комментарий]
FROM Loans
JOIN Loan_type ON Loan_type.id = Loans.Код_вида
JOIN Clients ON Clients.id = Loans.Код_клиента

---------------------------------------------------
SELECT *
FROM Loans
FULL JOIN Loan_type ON Loans.id = Loan_type.id

SELECT *
FROM Loan_type
FULL JOIN Loans ON Loans.id = Loan_type.id


SELECT *
FROM Loan_type
FULL OUTER JOIN Loans ON Loans.id = Loan_type.id
WHERE Loan_type.id  is  null

SELECT *
FROM Loan_type
FULL OUTER JOIN Loans ON Loans.id = Loan_type.id
WHERE Loans.id is NOT null

---------------------------------------------------

INSERT INTO Loans(ID, Код_вида, Код_клиента, Сумма, Дата_возврата, Дата_выдачи, test2) VALUES (6, 2, 3, 321313, '2023-03-18', '2023-05-05', NULL)

SELECT ISNULL(test2, 'pp') AS [Просто_текст], Loans.Сумма
FROM Loans
---------------------------------------------------

SELECT *
FROM Loans CROSS JOIN Loan_type
WHERE Loans.Код_вида = Loan_type.id