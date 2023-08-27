package com.example.norm;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.*;
import org.mindrot.jbcrypt.BCrypt;
import java.text.SimpleDateFormat;


import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.Date;
import java.util.logging.Logger;

@WebServlet(name = "Second", value = "/second-servlet")
public class Second extends HttpServlet {

    Connection connection;
    String counterName;
    public void init() {
        counterName = "visits";
        try {
            connection = DB.getConnection();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }
    public void doPost(HttpServletRequest request, HttpServletResponse response) throws IOException, ServletException {
        response.setContentType("text/html;charset=UTF-8");
        PrintWriter out = response.getWriter();

        String username = request.getParameter("username");



        AccountsDao accountsDao = new AccountsDaoImpl(connection);
        try {
            if(accountsDao.getUserByCredentials(username, request.getParameter("password"))){
                Cookie[] cookies = request.getCookies();
                Date date = new Date();
                SimpleDateFormat dateFormat = new SimpleDateFormat("yyyy-MM-dd-HH:mm:ss");
                String formattedDate = dateFormat.format(date);
                HttpSession session = request.getSession();

                session.setAttribute("username", username);

                out.println("пошло");
                System.out.println(accountsDao.getAccountRoleByLogin(username));
                request.setAttribute("role", accountsDao.getAccountRoleByLogin(username));
                request.setAttribute("username", username);
                request.setAttribute("currentTime", date);

                Cookie counterCookie = null;
                if (cookies != null) {
                    for (Cookie cookie : cookies) {
                        if (cookie.getName().equals(counterName)) {
                            counterCookie = cookie;
                            break;
                        }
                    }
                }

                if (counterCookie == null) {
                    counterCookie = new Cookie(counterName, "1");
                    response.addCookie(counterCookie);
                }
                // Если cookie найдена, то увеличиваем счетчик на 1 и обновляем cookie
                else {
                    int counterValue = Integer.parseInt(counterCookie.getValue());
                    counterValue++;
                    counterCookie.setValue(Integer.toString(counterValue));
                    response.addCookie(counterCookie);
                }
                Cookie cookie = new Cookie("lastLoginTime", formattedDate);
                response.addCookie(cookie);
                getServletContext().getRequestDispatcher("/greetingsPage.jsp").forward(request, response);
            }
            else {
                request.setAttribute("errorMessage", "Не пошло");
                request.getRequestDispatcher("/authorizationForm.jsp").forward(request, response);
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }
    public void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException, ServletException {
        response.setContentType("text/html;charset=UTF-8");
        request.getRequestDispatcher("authorizationForm.jsp").forward(request, response);
    }

    public void destroy() {}
}
