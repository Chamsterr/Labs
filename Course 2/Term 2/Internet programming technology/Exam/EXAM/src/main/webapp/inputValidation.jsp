<%--
  Created by IntelliJ IDEA.
  User: Chamster
  Date: 6/24/2023
  Time: 9:36 AM
  To change this template use File | Settings | File Templates.
--%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
    <title>Ввод данных</title>
</head>
<body>
    <form action="check.jsp" method="post">
        <label for="spec">Специализация:</label><br>
        <input type="text" id="spec" name="spec" value=""><br>
        <label for="course">Курс:</label><br>
        <input type="text" id="course" name="course" value=""><br><br>
        <input type="submit" value="Проверить">
    </form>
</body>
</html>
