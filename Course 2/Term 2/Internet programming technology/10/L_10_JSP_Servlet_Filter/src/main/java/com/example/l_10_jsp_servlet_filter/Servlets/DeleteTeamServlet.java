package com.example.l_10_jsp_servlet_filter.Servlets;

import db.DatabaseManager;
import db.PlayerTeamDAO;
import db.PlayerTeamsDAOImpl;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

import java.io.IOException;
import java.sql.Connection;
import java.sql.SQLException;

@WebServlet(name = "DeleteTeamServlet", value = "/DeleteTeamServlet")
public class DeleteTeamServlet extends HttpServlet {
    public void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String teamName = request.getParameter("teamName");
        Connection connection;
        try {
            connection = DatabaseManager.getConnection();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

        PlayerTeamDAO playerTeamDAO = new PlayerTeamsDAOImpl(connection);
        try {
            playerTeamDAO.DeleteTeamByName(teamName);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
        response.sendRedirect("welcome.jsp");
    }
}