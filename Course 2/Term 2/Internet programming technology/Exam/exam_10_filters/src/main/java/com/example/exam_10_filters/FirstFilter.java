package com.example.exam_10_filters;

import jakarta.servlet.*;
import jakarta.servlet.annotation.*;
import jakarta.servlet.*;
import jakarta.servlet.http.*;
import jakarta.servlet.annotation.*;
import java.io.IOException;
import java.util.logging.FileHandler;
import java.util.logging.Level;
import java.util.logging.Logger;

@WebFilter(filterName = "FirstFilter", urlPatterns = {"/*"})
public class FirstFilter implements Filter {
    private static final Logger log = Logger.getLogger(FirstFilter.class.getName());

    public void init(FilterConfig config) throws ServletException {
        try {
            FileHandler handler = new FileHandler("D:\\Labs\\Course 2\\Term 2\\Internet programming technology\\Exam\\exam_10_filters\\logfile.log", true);
            log.addHandler(handler);
        } catch (IOException e) {
            log.log(Level.SEVERE, "Cannot create FileHandler for log", e);
        }
    }

    public void destroy() {
    }

    @Override
    public void doFilter(ServletRequest request, ServletResponse response, FilterChain chain) throws ServletException, IOException {
        HttpServletRequest httpReq = (HttpServletRequest) request;
        String ipAddress = httpReq.getRemoteAddr();
        long timestamp = System.currentTimeMillis();

        log.info("IP " + ipAddress + ", Time " + timestamp);

        chain.doFilter(request, response);
    }
}
