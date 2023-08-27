package com.example.norm;

import jakarta.servlet.*;
import jakarta.servlet.annotation.*;
import jakarta.servlet.http.HttpServletRequest;

import java.io.IOException;
import java.util.Date;

@WebFilter(filterName = "LoggingFilter", urlPatterns = {"/*"})
public class LogFilter implements Filter {
    private FilterConfig filterConfig;

    public void init(FilterConfig filterConfig) throws ServletException {
        this.filterConfig = filterConfig;
    }

    public void doFilter(ServletRequest request, ServletResponse response, FilterChain chain) throws IOException, ServletException {
        // Получаем информацию о запросе
        HttpServletRequest httpRequest = (HttpServletRequest) request;
        String url = httpRequest.getRequestURL().toString();
        String method = httpRequest.getMethod();
        String remoteAddr = request.getRemoteAddr();
        Date date = new Date();

        // Логируем информацию о запросе
        System.out.printf("%s - %s - %s - %s\n", date, method, url, remoteAddr);

        // Передаем запрос дальше по цепочке фильтров и сервлетов
        chain.doFilter(request, response);
    }

    public void destroy() {
        filterConfig = null;
    }
}