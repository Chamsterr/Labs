package com.example.norm;

import jakarta.servlet.*;
import jakarta.servlet.annotation.*;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpSession;

import java.io.IOException;

@WebFilter(filterName = "Filter", urlPatterns = { "/TestServlet" })
public class LoginFilter implements Filter{
    public void init(FilterConfig config) throws ServletException {
    }

    public void destroy() {
    }

    @Override
    public void doFilter(ServletRequest request, ServletResponse response, FilterChain chain) throws ServletException, IOException {
        HttpServletRequest httpRequest = (HttpServletRequest) request;
        HttpSession session = httpRequest.getSession(false); // получаем текущую сессию или null, если сессии не существует
        if (session == null || session.getAttribute("username") == null) { // проверяем наличие атрибута username в сессии
            RequestDispatcher dispatcher = request.getRequestDispatcher("authorizationForm.jsp");
            dispatcher.forward(request, response);
        } else {
            chain.doFilter(request, response);
        }
    }
}
