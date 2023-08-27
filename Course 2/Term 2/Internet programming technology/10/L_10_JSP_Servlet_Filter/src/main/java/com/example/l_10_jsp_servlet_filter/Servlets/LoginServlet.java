package com.example.l_10_jsp_servlet_filter.Servlets;

import java.io.*;
import java.sql.Connection;
import java.sql.SQLException;

import db.DatabaseManager;
import db.UsersDAO;
import db.UsersDAOImpl;
import jakarta.servlet.ServletException;
import jakarta.servlet.http.*;
import jakarta.servlet.annotation.*;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
import org.mindrot.jbcrypt.BCrypt;

@WebServlet(name = "LoginServlet", value = "/login")
public class LoginServlet extends HttpServlet {
    Connection connection;

    public void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException {

        response.setContentType("text/html;charset=UTF-8");
        PrintWriter out = response.getWriter();
        response.sendRedirect("login.jsp");
    }
/*    private static final Logger logger = LogManager.getLogger();*/
    public void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
        PrintWriter out = response.getWriter();

        String login = request.getParameter("login");
        String password = request.getParameter("password");

        try {
            connection = DatabaseManager.getConnection();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

        UsersDAO usersDAO = new UsersDAOImpl(connection);

        try {
            if(usersDAO.getUserByCredentials(login, password)){
                HttpSession session = request.getSession();

                session.setAttribute("login", login);
                session.setAttribute("role", usersDAO.getAccountRoleByLogin(login));

                request.getRequestDispatcher("/welcome.jsp").forward(request, response);
            }
            else {
/*                logger.info("Не пошло");*/
                request.setAttribute("errorMessage", "Не пошло");
                request.getRequestDispatcher("/login.jsp").forward(request, response);
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }
}