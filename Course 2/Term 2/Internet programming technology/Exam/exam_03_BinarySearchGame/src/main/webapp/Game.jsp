<%--
  Created by IntelliJ IDEA.
  User: Chamster
  Date: 6/23/2023
  Time: 1:56 AM
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Game</title>
</head>
<body>
    <h1>${ServerPeek}</h1>
    <h1>мин-${min}</h1>
    <h1>макс-${max}</h1>
    <h1>${countLast}</h1>
    <form action="${pageContext.request.contextPath}/GameServlet" method="post">
        <input type="submit" name="button" value=">">
        <input type="submit" name="button" value="<">
        <input type="submit" name="button" value="=">
    </form>
</body>
</html>
