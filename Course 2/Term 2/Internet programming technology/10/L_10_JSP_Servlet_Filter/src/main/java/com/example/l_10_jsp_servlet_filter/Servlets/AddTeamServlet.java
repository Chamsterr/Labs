package com.example.l_10_jsp_servlet_filter.Servlets;

import java.io.*;
import java.sql.Connection;
import java.sql.SQLException;

import db.*;
import jakarta.servlet.ServletException;
import jakarta.servlet.http.*;
import jakarta.servlet.annotation.*;

@WebServlet(name = "AddTeamServlet", value = "/AddTeamServlet")
public class AddTeamServlet extends HttpServlet {
    public void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String teamName = request.getParameter("teamName");
        String contact = request.getParameter("contactEmail");

        Connection connection = null;
        try {
            connection = DatabaseManager.getConnection();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

        PlayerTeamDAO playerTeamDAO = new PlayerTeamsDAOImpl(connection);

        try {
            playerTeamDAO.UpdateTeams(teamName, contact);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
        response.sendRedirect("welcome.jsp");
    }
}