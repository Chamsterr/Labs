-----------------------------1--------------------------
SELECT Loans.Код_вида, SUM(Loans.Сумма)
FROM Loans
WHERE Loans.Код_вида IN (1, 2)
GROUP BY ROLLUP (Loans.Код_вида, Loans.Сумма)
--------------------------------------------------------

-----------------------------2--------------------------
SELECT Loans.Код_вида, SUM(Loans.Сумма)
FROM Loans
WHERE Loans.Код_вида IN (1, 2)
GROUP BY CUBE(Loans.Код_вида)

--------------------------------------------------------

-----------------------------3--------------------------
SELECT Clients.Название_фирмы, ROUND(AVG(CAST(Loans.Сумма AS float(4))), 2)
FROM Loan_type
	JOIN Loans ON Loans.Код_вида = Loan_type.id
	JOIN Clients ON Loans.Код_клиента = Clients.id
WHERE Clients.id = 3
GROUP BY Clients.Название_фирмы
UNION
SELECT Clients.Название_фирмы, ROUND(AVG(CAST(Loans.Сумма AS float(4))), 2)
FROM Loan_type
	JOIN Loans ON Loans.Код_вида = Loan_type.id
	JOIN Clients ON Loans.Код_клиента = Clients.id
WHERE Clients.id = 1
GROUP BY Clients.Название_фирмы

SELECT Clients.Название_фирмы, ROUND(AVG(CAST(Loans.Сумма AS float(4))), 2)
FROM Loan_type
	JOIN Loans ON Loans.Код_вида = Loan_type.id
	JOIN Clients ON Loans.Код_клиента = Clients.id
WHERE Clients.id = 3
GROUP BY Clients.Название_фирмы
UNION ALL
SELECT Clients.Название_фирмы, ROUND(AVG(CAST(Loans.Сумма AS float(4))), 2)
FROM Loan_type
	JOIN Loans ON Loans.Код_вида = Loan_type.id
	JOIN Clients ON Loans.Код_клиента = Clients.id
WHERE Clients.id = 1
GROUP BY Clients.Название_фирмы
-------------------------------------------------------

-----------------------------4-5--------------------------
SELECT Clients.Название_фирмы, ROUND(AVG(CAST(Loans.Сумма AS float(4))), 2)
FROM Loan_type
	JOIN Loans ON Loans.Код_вида = Loan_type.id
	JOIN Clients ON Loans.Код_клиента = Clients.id
WHERE Clients.id = 3
GROUP BY Clients.Название_фирмы
INTERSECT
SELECT Clients.Название_фирмы, ROUND(AVG(CAST(Loans.Сумма AS float(4))), 2)
FROM Loan_type
	JOIN Loans ON Loans.Код_вида = Loan_type.id
	JOIN Clients ON Loans.Код_клиента = Clients.id
WHERE Clients.id = 1
GROUP BY Clients.Название_фирмы

SELECT Clients.Название_фирмы, ROUND(AVG(CAST(Loans.Сумма AS float(4))), 2)
FROM Loan_type
	JOIN Loans ON Loans.Код_вида = Loan_type.id
	JOIN Clients ON Loans.Код_клиента = Clients.id
WHERE Clients.id = 3
GROUP BY Clients.Название_фирмы
EXCEPT
SELECT Clients.Название_фирмы, ROUND(AVG(CAST(Loans.Сумма AS float(4))), 2)
FROM Loan_type
	JOIN Loans ON Loans.Код_вида = Loan_type.id
	JOIN Clients ON Loans.Код_клиента = Clients.id
WHERE Clients.id = 1
GROUP BY Clients.Название_фирмы
--------------------------------------------------------	