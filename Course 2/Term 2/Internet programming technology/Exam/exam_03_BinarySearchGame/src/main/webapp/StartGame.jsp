<%--
  Created by IntelliJ IDEA.
  User: Chamster
  Date: 6/23/2023
  Time: 1:34 AM
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Выберите число</title>
    <script>
    function updateValue(val) {
        document.getElementById('currentValue').textContent = val;
    }
    </script>
</head>
<body>
    <h1>Выберите число</h1>
    <form action="${pageContext.request.contextPath}/GameServlet" method="get">
      <label>
        <input type="range" min="0" max="100" value="50" name="peek" oninput="updateValue(this.value)">
          <span id="currentValue">50</span>
      </label>
      <br/>
      <input type="submit" value="Выбрать!">
    </form>
</body>
</html>
