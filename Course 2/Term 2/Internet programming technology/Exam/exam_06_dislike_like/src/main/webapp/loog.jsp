<%--
  Created by IntelliJ IDEA.
  User: Chamster
  Date: 6/24/2023
  Time: 12:02 AM
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ taglib prefix = "c" uri = "http://java.sun.com/jsp/jstl/core" %>
<html>
<head>
    <title>Title</title>
</head>
<body>
    <c:forEach var="post" items="${posts}">
        <h2>${post.text}</h2>
        <form method="post" action="${pageContext.request.contextPath}/PostServlet">
            <input type="hidden" name="text" value="${post.text}">
            <button type="submit" name="action" value="like">Like</button>
            ${post.like}
            <button type="submit" name="action" value="dislike">Dislike</button>
            ${post.dislike}
        </form>
    </c:forEach>
</body>
</html>
