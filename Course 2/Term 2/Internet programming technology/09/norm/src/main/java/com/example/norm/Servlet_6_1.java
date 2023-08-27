package com.example.norm;

import jakarta.servlet.*;
import jakarta.servlet.http.*;
import jakarta.servlet.annotation.*;

import java.io.IOException;
import java.io.PrintWriter;

@WebServlet(name = "Servlet_6_1", value = "/Servlet_6_1")
public class Servlet_6_1 extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        PrintWriter out = response.getWriter();
        String text = request.getParameter("test");

        response.sendRedirect("Servlet_6_2?param=" + text);
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        response.sendRedirect("Servlet_6_2?param=" + request.getParameter("task_b"));

    }
}
