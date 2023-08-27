<%--
  Created by IntelliJ IDEA.
  User: Chamster
  Date: 6/23/2023
  Time: 12:55 AM
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>

<%@ taglib prefix = "c" uri = "http://java.sun.com/jsp/jstl/core" %>

<html>
<head>
    <title>Результат</title>
</head>
<body>
    ${list_of_candidates_with_scope}

    <c:forEach items="${list_of_candidates_with_scope}" var="name">
        <option>${name}</option>
    </c:forEach>

    <a href="IndexServlet">страница голосования</a>
</body>
</html>
