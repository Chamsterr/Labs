        <%@ page import="db.PlayerTeamDAO" %>
<%@ page import="db.PlayerTeamsDAOImpl" %>
<%@ page import="java.sql.Connection" %>
<%@ page import="db.DatabaseManager" %>
<%@ page import="java.sql.SQLException" %>
        <%@ page import="java.sql.ResultSet" %>
        <%@ page import="java.io.PrintWriter" %><%--
  Created by IntelliJ IDEA.
  User: Chamster
  Date: 5/6/2023
  Time: 1:24 AM
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Welcome</title>
    <link rel="stylesheet" href="styles/main.css">
</head>
<body>
    <jsp:include page="templates/header.jsp"/>
    <h1>Добро пожаловать, ${sessionScope.login} <br> Ваша роль ${sessionScope.role}</h1>
    <% Connection connection;
        try {
            connection = DatabaseManager.getConnection();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }%>
    <% PlayerTeamDAO playerTeamDAO = new PlayerTeamsDAOImpl(connection);%>
    <% ResultSet teams = playerTeamDAO.getAllTeams();%>
    <table>
      <thead>
        <tr>
          <th>Название команды</th>
          <th>Email</th>
        </tr>
      </thead>
      <tbody>
        <% while (true) {
            try {
                if (!teams.next()) break;
            } catch (SQLException e) {
                throw new RuntimeException(e);
            } %>
          <tr>
            <td><%= teams.getString("team_name") %></td>
            <td><%= teams.getString("contact_email") %></td>
            <td>
                <form method="post" action="${pageContext.request.contextPath}/DeleteTeamServlet">
                    <input type="hidden" name="teamName" value="<%= teams.getString("team_name") %>">
                    <input value="Удалить" type="submit">
                </form>
            </td>
          </tr>
        <% } %>
      </tbody>
    </table>

    <form action="${pageContext.request.contextPath}/AddTeamServlet" method="POST">
      <label for="teamName">Название команды:</label>
      <input type="text" id="teamName" name="teamName"><br>

      <label for="contactEmail">Контактный email:</label>
      <input type="email" id="contactEmail" name="contactEmail"><br>

      <input type="submit" value="Отправить">
    </form>
</body>
</html>
