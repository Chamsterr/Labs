package com.example.exam_08_4_fields_a_b_c_x;

import jakarta.servlet.*;
import jakarta.servlet.http.*;
import jakarta.servlet.annotation.*;

import java.io.IOException;

@WebServlet(name = "GetResultServlet", value = "/GetResultServlet")
public class GetResultServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String a = request.getParameter("a");
        String b = request.getParameter("b");
        String c = request.getParameter("c");
        String x = request.getParameter("x");

        if (a != "" && b != "" && c != "" && x != ""){
            request.setAttribute("sum", Integer.parseInt(a) + Integer.parseInt(b) + Integer.parseInt(c) +Integer.parseInt(x));
            request.getRequestDispatcher("result.jsp").forward(request, response);
        }
        else {
            response.getWriter().println("Error");
        }
    }
}
