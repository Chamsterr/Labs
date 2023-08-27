package com.example.exam_04_json_name_sum;
import com.fasterxml.jackson.databind.ObjectMapper;
import jakarta.servlet.*;
import jakarta.servlet.http.*;
import jakarta.servlet.annotation.*;

import java.io.File;

import java.io.IOException;

@WebServlet(name = "JsonServlet", value = "/JsonServlet")
public class CardServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        ObjectMapper objectMapper = new ObjectMapper();
        CardWrapper cardWrapper = objectMapper.readValue(new File(getServletContext().getRealPath("/") + "/data.json"), CardWrapper.class);
        request.setAttribute("cards", cardWrapper.getCards().getCard());

        request.getRequestDispatcher("/display.jsp").forward(request, response);
    }
}
