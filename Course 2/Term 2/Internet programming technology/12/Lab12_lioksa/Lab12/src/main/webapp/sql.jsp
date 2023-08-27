<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ taglib prefix="sql" uri="http://java.sun.com/jsp/jstl/sql" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<html>
<head>
    <title>Sql</title>
</head>
<body>
<sql:setDataSource var="db"
                   driver="org.postgresql.Driver"
                   url="jdbc:postgresql://localhost:8888/postgres"
                   user="postgres" password="1"/>

<sql:query var="result" dataSource="${db}">
    SELECT * FROM Users
</sql:query>

<table style="border: 1px solid black;">
    <tr>
        <th>battalion_name</th>
        <th>soft_attack</th>
        <th>hard_attack</th>
    </tr>

<c:forEach var="row" items="${result.rows}">
    ID: ${row.id}, Age: ${row.age}, Name: ${row.name}<br/>
</c:forEach>

</table>
</body>
</html>
