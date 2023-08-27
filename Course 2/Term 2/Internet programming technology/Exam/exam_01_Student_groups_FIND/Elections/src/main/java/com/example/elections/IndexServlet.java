package com.example.elections;

import jakarta.servlet.*;
import jakarta.servlet.http.*;
import jakarta.servlet.annotation.*;

import java.io.IOException;
import java.sql.*;
import java.util.ArrayList;
import java.util.List;

@WebServlet(name = "IndexServlet", value = "/IndexServlet")
public class IndexServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        Connection conn;
        List<String> names = new ArrayList<>();
        
        try {
            conn = DBManager.getConnection();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

        String query = "SELECT \"fullname\" FROM \"Votes\"";
        Statement statement;
        try {
            statement = conn.createStatement();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
        ResultSet rs;

        try {
            rs = statement.executeQuery(query);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

        while (true) {
            try {
                if (!rs.next()) break;
            } catch (SQLException e) {
                throw new RuntimeException(e);
            }
            try {
                names.add(rs.getString("fullname"));
            } catch (SQLException e) {
                throw new RuntimeException(e);
            }
        }
                
        request.setAttribute("names", names);
        request.getRequestDispatcher("index.jsp").forward(request, response);
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        Connection conn;
        String query = "UPDATE \"Votes\" SET \"number_of_voites\" = \"number_of_voites\" + 1 where fullname = ?";

        try {
            conn = DBManager.getConnection();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

        PreparedStatement preparedStatement;

        try {
            preparedStatement = conn.prepareStatement(query);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
        request.getParameter("name");
        try {
            preparedStatement.setString(1, request.getParameter("name"));
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

        try {
             preparedStatement.executeUpdate();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

        String query2 = "SELECT fullname, (number_of_voites * 100.0 / SUM(number_of_voites) OVER ()) AS percent_votes FROM \"Votes\"";
        try {
            Statement statement = conn.createStatement();
            ResultSet rs = statement.executeQuery(query2);
            List<String> candidates_with_scope = new ArrayList<>();

            while (rs.next()){
                String str = rs.getString("fullname") + rs.getString("percent_votes");
                candidates_with_scope.add(str);
            }

            request.setAttribute("list_of_candidates_with_scope", candidates_with_scope);
            request.getRequestDispatcher("result.jsp").forward(request, response);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }
}
