<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<html>
<head>
    <title>Cards</title>
</head>
<body>
    <button onclick="window.location.href='${pageContext.request.contextPath}/getCards'">GET</button>
    <table>
        <tr>
            <th>NAME</th>
            <th>SUM</th>
        </tr>
        <c:forEach var="card" items="${cards}">
            <tr>
                <td><c:out value="${card.name}"/></td>
                <td><c:out value="${card.sum}"/></td>
            </tr>
        </c:forEach>
    </table>
</body>
</html>
