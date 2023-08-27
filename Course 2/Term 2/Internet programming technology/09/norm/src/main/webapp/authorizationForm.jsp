<%--
  Created by IntelliJ IDEA.
  User: Chamster
  Date: 4/28/2023
  Time: 12:48 AM
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Форма авторизации</title>
</head>
<body>
    <h1>Авторизация</h1>
    <form action="${pageContext.request.contextPath}/second-servlet" method="post">
        <label for="username">Username:</label>
        <input type="text" id="username" name="username"><br><br>
        <label for="password">Password:</label>
        <input type="password" id="password" name="password"><br><br>
        <input type="submit" value="Submit">
    </form>
    <p>${requestScope.errorMessage}</p>
    <a href="${pageContext.request.contextPath}/registration">Регистрация</a>
</body>
</html>
