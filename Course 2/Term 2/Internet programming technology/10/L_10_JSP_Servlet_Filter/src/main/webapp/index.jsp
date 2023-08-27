<%--
  Created by IntelliJ IDEA.
  User: Chamster
  Date: 5/6/2023
  Time: 3:45 AM
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Welcome</title>
</head>
<body>
    <h1>Добро пожаловать</h1>
    <a href="${pageContext.request.contextPath}/login">Авторизация</a>
    <a href="${pageContext.request.contextPath}/registration">Регистрация</a>
</body>
</html>
