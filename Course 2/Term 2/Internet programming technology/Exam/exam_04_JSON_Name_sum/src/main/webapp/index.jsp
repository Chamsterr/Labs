<%@ page contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" %>
<!DOCTYPE html>
<html>
<head>
    <title>JSP - Hello World</title>
</head>
<body>
    <a href=""></a>
    <form action="${pageContext.request.contextPath}/JsonServlet" method="get">
        <input value="GET" type="submit">
    </form>
</body>
</html>