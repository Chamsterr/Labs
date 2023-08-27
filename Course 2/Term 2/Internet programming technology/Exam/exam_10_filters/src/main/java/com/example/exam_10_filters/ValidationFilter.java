package com.example.exam_10_filters;

import jakarta.servlet.*;
import jakarta.servlet.annotation.*;
import jakarta.servlet.*;
import jakarta.servlet.http.*;
import jakarta.servlet.annotation.*;
import java.io.IOException;
import java.util.logging.Logger;
import java.io.IOException;

@WebFilter(filterName = "ValidationFilter", urlPatterns = {"/MyServlet"})
public class ValidationFilter implements Filter {
    public void init(FilterConfig config) throws ServletException {
    }

    public void destroy() {
    }

    @Override
    public void doFilter(ServletRequest request, ServletResponse response, FilterChain chain) throws IOException, ServletException {
        HttpServletRequest httpReq = (HttpServletRequest) request;
        HttpServletResponse httpRes = (HttpServletResponse) response;

        String phone = httpReq.getParameter("phone");
        String email = httpReq.getParameter("email");

        if (phone == null || email == null || phone.isEmpty() || email.isEmpty()) {
            httpReq.setAttribute("errorMessage", "Телефон и/или адрес электронной почты отсутствуют");
            RequestDispatcher rd = request.getRequestDispatcher("/errorPage.jsp");
            rd.forward(request, response);
        } else {
            chain.doFilter(request, response);
        }
    }
}
