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
    <title>Error Page</title>
</head>
<body>
    <p style="color: red">${requestScope.errorMessageNumber}</p>
    <p style="color: red">${requestScope.errorMessage}</p>
</body>
</html>
