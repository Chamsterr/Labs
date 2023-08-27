package com.example.norm;

import com.example.norm.DB;

import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.SQLException;
import java.sql.Statement;
import java.time.Instant;
import java.util.Date;
import java.util.Enumeration;

@WebServlet(name = "helloServlet", value = "/hello-servlet")
public class HelloServlet extends HttpServlet {
    public void init() {
    }

    public void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException {
        response.setContentType("text/html;charset=UTF-8");

        Date date = Date.from(Instant.now());
        PrintWriter out = response.getWriter();
        out.println("<html><head><meta charset=\"UTF-8\"></head><body>");
        out.println("<h1>" + date + "</h1>");
        out.println("<ul>");
            out.println("<li>IP-адреса клиента, от имени которого пришел запрос: " + request.getRemoteAddr() + "</li>");
            out.println("<li>Хостнейм: " + request.getRemoteHost() + " " + request.getRemoteUser() + "</li>");
            out.println("<li>Протокол: "+ request.getProtocol() + "</li>");
            out.println("<li>URL: "+ request.getRequestURL() + "</li>");
            out.println("<li>Протокол: "+ request.getProtocol() + "</li>");
            out.println("<li>Имя метода к доступу ресурса: "+ request.getMethod() + "</li>");
        out.println("</ul>");

        out.println("<a href=\"second-servlet\">second task</a>");

        Enumeration< String > e = request.getHeaderNames();
            while (e.hasMoreElements()) {
                String name = e.nextElement();
                String value = request.getHeader(name);
                out.println(name + " = " + value);
            }

        out.println("<form><input type='submit'></input></form>");
        out.println("</body></html>");
    }

    public void destroy() {
    }
}