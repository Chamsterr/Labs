package com.example.norm;

import jakarta.servlet.*;
import jakarta.servlet.http.*;
import jakarta.servlet.annotation.*;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.HttpURLConnection;
import java.net.URL;

@WebServlet(name = "Servlet7-1", value = "/Servlet7-1")
public class Servlet71 extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String param1 = request.getParameter("param1");

        String url = "/ServletTwo?param1=" + param1;

        // Создаем объект для отправки GET-запроса
        URL obj = new URL(request.getScheme(), request.getServerName(), request.getServerPort(), url);

        // Отправляем GET-запрос и получаем ответ
        HttpURLConnection con = (HttpURLConnection) obj.openConnection();

        response.setContentType("text/html;charset=UTF-8");
        con.setRequestMethod("GET");
        int responseCode = con.getResponseCode();
        PrintWriter out = response.getWriter();
        out.println(HttpURLConnection.HTTP_OK);
        out.println("<html>");
        out.println("<body>");
        out.println("<h1>Ответ от сервлета-два:</h1>");
        out.println("<p>" + request.getParameter("param1") + "</p>");
        out.println("</body>");
        out.println("</html>");
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    }
}
