<%--
  Created by IntelliJ IDEA.
  User: Chamster
  Date: 6/22/2023
  Time: 10:48 PM
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<%@ taglib uri="http://java.sun.com/jsp/jstl/functions" prefix="fn" %>
<html>
<head>
    <title>Title</title>
</head>
<body>
    ${list}
    <form action="${pageContext.request.contextPath}/FindServlet" method="post">
        <input type="hidden" name="listSize" value="${fn:length(list)}">
        <input type="submit" value="Count">
    </form>
</body>
</html>
