package com.example.exam_03_binarysearchgame;

import jakarta.servlet.*;
import jakarta.servlet.http.*;
import jakarta.servlet.annotation.*;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.Random;

@WebServlet(name = "GameServlet", value = "/GameServlet")
public class GameServlet extends HttpServlet {
    private Integer count;
    public void init() throws ServletException {
        count = 0;
    }
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        PrintWriter out = response.getWriter();
        HttpSession session = request.getSession();

        Random random = new Random();
        int randomNumber = random.nextInt(101);

        // не нужно, но пусть будет)
        session.setAttribute("peekedNumber", request.getParameter("peek"));
        //
        session.setAttribute("ServerPeek", randomNumber);
        session.setAttribute("min", 0);
        session.setAttribute("max", 100);
        request.getRequestDispatcher("Game.jsp").forward(request, response);
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String buttonValue = request.getParameter("button"); // Получаем значение нажатой кнопки
        HttpSession session = request.getSession();

        Cookie[] cookies = request.getCookies();
        if (cookies != null) {
            for (Cookie cookie : cookies) {
                if (cookie.getName().equals("lastGameCount")) {
                    session.setAttribute("countLast", cookie.getValue());
                }
            }
        }

        if (buttonValue.equals(">")) {
            count += 1;
            int peekValue = (int) session.getAttribute("ServerPeek");
            session.setAttribute("max", peekValue);
            session.setAttribute("ServerPeek",( (int) session.getAttribute("min") +(int) session.getAttribute("max") - (int) session.getAttribute("min")) / 2);
            request.getRequestDispatcher("Game.jsp").forward(request, response);
        } else if (buttonValue.equals("<")) {
            count += 1;
            int peekValue = (int) session.getAttribute("ServerPeek");
            session.setAttribute("min", peekValue);
            session.setAttribute("ServerPeek",((int) session.getAttribute("max") + (int) session.getAttribute("min")) / 2);

            request.getRequestDispatcher("Game.jsp").forward(request, response);
        } else if (buttonValue.equals("=")) {
            response.getWriter().write("Congrat");
            Cookie cookie;
            cookie = new Cookie("lastGameCount", count.toString());
            count = 0;
            response.addCookie(cookie);
        }
    }
}
