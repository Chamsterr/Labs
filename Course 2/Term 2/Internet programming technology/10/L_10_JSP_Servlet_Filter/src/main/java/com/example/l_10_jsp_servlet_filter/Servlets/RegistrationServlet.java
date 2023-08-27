package com.example.l_10_jsp_servlet_filter.Servlets;

import java.io.*;
import java.sql.Connection;
import java.sql.SQLException;

import db.BcryptHasher;
import db.DatabaseManager;
import db.UsersDAO;
import db.UsersDAOImpl;
import jakarta.servlet.ServletException;
import jakarta.servlet.http.*;
import jakarta.servlet.annotation.*;
import org.mindrot.jbcrypt.BCrypt;

@WebServlet(name = "RegistrationServlet", value = "/registration")
public class RegistrationServlet extends HttpServlet {
    Connection connection;
    public void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException {
        response.setContentType("text/html;charset=UTF-8");
        PrintWriter out = response.getWriter();
        response.sendRedirect("register.jsp");
    }

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

        String hashedPassword = null;
        try {
            hashedPassword = BcryptHasher.getPasswordHash(password);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

        try {
            if (usersDAO.checkIfUsernameExist(login)){
                request.setAttribute("registrationInfo", "Данный пользователь уже существует");
            }
            else{
                usersDAO.insert(login, hashedPassword);
                request.setAttribute("registrationInfo", "Аккаунт успешно зарегистрирован");
            }
            request.getRequestDispatcher("register.jsp").forward(request, response);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }
}