<%@ page contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" %>
<!DOCTYPE html>
<html>
<head>
    <title>JSP - Hello World</title>
</head>
    <body>
        <h1><%= "Hello World!" %></h1>
        <form action="${pageContext.request.contextPath}/GetResultServlet" method="get">
            <input name="a" placeholder="a">
            <input name="b" placeholder="b">
            <input name="c" placeholder="c">
            <input name="x" placeholder="x">

            <input type="submit" value="get result">
        </form>
    </body>
</html>