<%@ page contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" %>
<%@ include file="hw.jsp" %>

<!DOCTYPE html>
<html>
<head>
    <title>JSP - Hello World</title>
</head>
<body>
<t:hw/>
<h1><%= "Hello World!" %>
</h1>
<br/>
<my:myTag input="John" />
<a href="hello-servlet">Hello Servlet</a>
</body>
</html>