<%--
  Created by IntelliJ IDEA.
  User: Chamster
  Date: 6/24/2023
  Time: 9:36 AM
  To change this template use File | Settings | File Templates.
--%>
<%@page import="com.example.exam.SpecializationValidator, com.example.exam.CourseValidator"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
    <title>Проверка данных</title>
</head>
<body>
    <%
        String spec = request.getParameter("spec");
        String course = request.getParameter("course");
        SpecializationValidator specValidator = new SpecializationValidator();
        CourseValidator courseValidator = new CourseValidator();

        if (specValidator.validate(spec) && courseValidator.validate(Integer.parseInt(course))) {
    %>
        <p>Данные корректны!</p>
    <%
        } else {
    %>
        <p>Введены некорректные данные!</p>
    <%
        }
    %>
</body>
</html>
