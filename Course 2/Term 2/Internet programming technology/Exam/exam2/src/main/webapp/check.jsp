<%@ taglib prefix="my" uri="http://mytags" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ page import="java.lang.Integer" %>

<my:validator spec="${param.spec}" course="${Integer.parseInt(param.course)}" />

<c:choose>
    <c:when test="${valid}">
        <p>Данные корректны!</p>
    </c:when>
    <c:otherwise>
        <p>Введены некорректные данные!</p>
    </c:otherwise>
</c:choose>
