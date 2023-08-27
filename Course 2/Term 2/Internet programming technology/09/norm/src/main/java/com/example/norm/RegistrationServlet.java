package com.example.norm;

import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.Cookie;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import org.mindrot.jbcrypt.BCrypt;

import java.io.IOException;
import java.sql.Connection;
import java.sql.SQLException;

@WebServlet(name = "registration", value = "/registration")
public class RegistrationServlet extends HttpServlet {
    Connection connection;
    public void init() {
        try {
            connection = DB.getConnection();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException{
        String username = request.getParameter("username");
        String hashedPassword = BCrypt.hashpw(request.getParameter("password"), BCrypt.gensalt());

        AccountsDao accountsDao = new AccountsDaoImpl(connection);
        try {
            if (accountsDao.checkIfUsernameExist(username)){
                request.setAttribute("registrationInfo", "Данный пользователь уже существует");
            }
            else{
                accountsDao.insert(username, hashedPassword);
                request.setAttribute("registrationInfo", "Аккаунт успешно зарегистрирован");
            }
            request.getRequestDispatcher("registration.jsp").forward(request, response);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

    }
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        request.getRequestDispatcher("registration.jsp").forward(request, response);
    }
}
