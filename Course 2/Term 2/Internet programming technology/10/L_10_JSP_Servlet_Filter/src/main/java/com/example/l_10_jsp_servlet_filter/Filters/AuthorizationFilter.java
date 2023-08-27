package com.example.l_10_jsp_servlet_filter.Filters;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
import jakarta.servlet.*;
import jakarta.servlet.annotation.*;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpSession;

import java.io.IOException;

@WebFilter(filterName = "AuthorizationFilter", urlPatterns = { "/welcome.jsp", "/AddTeamServlet", "/DeleteTeamServlet" })
public class AuthorizationFilter implements Filter {
    @Override
    public void doFilter(ServletRequest request, ServletResponse response, FilterChain chain) throws ServletException, IOException {
        HttpServletRequest httpRequest = (HttpServletRequest) request;
        HttpSession session = httpRequest.getSession(false); // получаем текущую сессию или null, если сессии не существует
        if (session == null || session.getAttribute("login") == null) { // проверяем наличие атрибута username в сессии
            request.setAttribute("errorMessageNumber", 404);
            request.setAttribute("errorMessage", "Страницы не существует");
            RequestDispatcher dispatcher = request.getRequestDispatcher("errorPage.jsp");
            dispatcher.forward(request, response);
        } else {
            chain.doFilter(request, response);
        }
    }
}
