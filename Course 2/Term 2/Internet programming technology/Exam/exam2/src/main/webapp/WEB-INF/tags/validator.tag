<%@ tag import="java.util.Arrays, java.util.List" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ attribute name="spec" required="true" rtexprvalue="true" %>
<%@ attribute name="course" required="true" rtexprvalue="true" type="java.lang.Integer" %>
<%@ tag body-content="empty" %>

<c:set var="validSpecs" value="1 40 01 01, 1 40 05 06, 1 98 45 73" scope="page" />

<c:choose>
    <c:when test="${validSpecs.contains(spec) && course >= 1 && course <= 4}">
        <c:set var="valid" value="true" scope="request" />
    </c:when>
    <c:otherwise>
        <c:set var="valid" value="false" scope="request" />
    </c:otherwise>
</c:choose>
