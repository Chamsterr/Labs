<%--
  Created by IntelliJ IDEA.
  User: Chamster
  Date: 4/29/2023
  Time: 12:54 AM
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Регистрация</title>
</head>
<body>
    <h1>Регистрация</h1>
    <form action="${pageContext.request.contextPath}/registration" method="post">
        <label for="username">Username:</label>
        <input type="text" id="username" name="username"><br><br>
        <label for="password">Password:</label>
        <input type="password" id="password" name="password"><br><br>
        <input type="submit" value="Submit">
    </form>
    <a href="${pageContext.request.contextPath}/second-servlet">Авторизация</a>
    <p>${requestScope.registrationInfo}</p>
</body>
</html>
