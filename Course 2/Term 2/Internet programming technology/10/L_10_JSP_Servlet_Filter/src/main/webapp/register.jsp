<%--
  Created by IntelliJ IDEA.
  User: Chamster
  Date: 5/6/2023
  Time: 1:24 AM
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
        <label for="login">Login:&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</label>
        <input type="text" id="login" name="login"><br><br>
        <label for="password">Password:</label>
        <input type="password" id="password" name="password"><br><br>
        <input type="submit" value="Submit">
    </form>
    <p>${requestScope.registrationInfo}</p>
    <a href="${pageContext.request.contextPath}/login">Авторизация</a>
</body>
</html>
