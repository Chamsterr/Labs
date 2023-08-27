<%@ taglib prefix="my" uri="http://mytags" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<!DOCTYPE html>
<html>
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