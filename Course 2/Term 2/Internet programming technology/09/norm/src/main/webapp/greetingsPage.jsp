<%--
  Created by IntelliJ IDEA.
  User: Chamster
  Date: 4/28/2023
  Time: 1:51 AM
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Добро пожаловать</title>
</head>
<body>
    <h1>Добро пожаловать, ${requestScope.username} <br> Ваша роль ${requestScope.role}</h1>
    <h2>${requestScope.currentTime}</h2>
    <%
        Cookie[] cookies = request.getCookies();
        int visits = 1;
        String lastTime = "now";
        if (cookies != null) {
            for (Cookie cookie : cookies) {
                if (cookie.getName().equals("visits")) {
                    visits = Integer.parseInt(cookie.getValue());
                }
                else if (cookie.getName().equals("lastLoginTime")){
                    lastTime = String.valueOf(cookie.getValue());
                }
            }
        }
    %>
    <p>С вашего браузера сайт посетили - <%= visits %>. Последнее посещение <%= lastTime %> </p>
</body>
</html>
