package com.example.exam_06_dislike_like;

import jakarta.servlet.*;
import jakarta.servlet.http.*;
import jakarta.servlet.annotation.*;

import java.io.IOException;
import java.sql.*;
import java.util.ArrayList;
import java.util.List;

@WebServlet(name = "PostServlet", value = "/PostServlet")
public class PostServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        try {
            Connection connection = DBManager.getConnection();

            String query = "SELECT * FROM \"posts\"";

            Statement statement = connection.createStatement();

            ResultSet rs = statement.executeQuery(query);

            List<Post> posts = new ArrayList<>();

            while (rs.next())
            {
                Post post = new Post(
                        rs.getString("text"),
                        rs.getInt("like"),
                        rs.getInt("dislike")
                );
                 posts.add(post);

            }
            request.setAttribute("posts", posts);
            request.getRequestDispatcher("loog.jsp").forward(request, response);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

    }
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        try {
            Connection connection = DBManager.getConnection();
            String action = request.getParameter("action");
            String text = request.getParameter("text");
            PreparedStatement statement = null;

            if ("like".equals(action)) {
                // Запрос SQL для увеличения количества лайков
                String query = "UPDATE posts SET \"like\" = \"like\" + 1 WHERE \"text\" = ?";
                statement = connection.prepareStatement(query);
                statement.setString(1, text);
            } else if ("dislike".equals(action)) {
                // Запрос SQL для увеличения количества дизлайков
                String query = "UPDATE posts SET \"dislike\" = \"dislike\" + 1 WHERE \"text\" = ?";
                statement = connection.prepareStatement(query);
                statement.setString(1, text);
            }

            if (statement != null) {
                statement.executeUpdate();
            }

            doGet(request, response);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

}
