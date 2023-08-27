<%@ page contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" %>
<%@ taglib prefix = "c" uri = "http://java.sun.com/jsp/jstl/core" %>
<!DOCTYPE html>
<html>
<head>
    <title>JSP - Hello World</title>
</head>
<body>
<h1><%= "Hello World!" %>
</h1>
<br/>
    <form  action="${pageContext.request.contextPath}/IndexServlet" method="post">
        <label>
            <Select name="name">
                <c:forEach items="${names}" var="name">
                    <option>${name}</option>
                </c:forEach>
            </Select>
        </label>
        <input type="submit" value="vote">
    </form>
</body>
</html>