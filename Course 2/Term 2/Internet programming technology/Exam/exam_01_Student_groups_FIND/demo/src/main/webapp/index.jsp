<%@ page contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" %>
<%@ taglib prefix = "c" uri = "http://java.sun.com/jsp/jstl/core" %>

<!DOCTYPE html>
<html>
    <head>
        <title>Выберите группу</title>
    </head>
    <body>
        <h1>Выберите группу</h1>
        ${groups}
        <form action="${pageContext.request.contextPath}/FindServlet" method="get">
            <label>
                <select name="group">
                    <c:forEach items="${groups}" var="group">
                        <option>${group}</option>
                    </c:forEach>
                </select>
            </label>
            <input type="submit" value="FIND">
        </form>
    </body>
</html>
