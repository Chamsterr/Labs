import com.example.demo.DBManager;
import jakarta.servlet.*;
import jakarta.servlet.http.*;
import jakarta.servlet.annotation.*;

import java.io.IOException;
import java.sql.*;
import java.util.ArrayList;
import java.util.List;

@WebServlet(name = "FindServlet", value = "/FindServlet")
public class FindServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
         Connection connection;
        try {
            connection = DBManager.getConnection();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
        Integer searchTerm = Integer.valueOf(request.getParameter("group"));

        String query = "SELECT \"fullname\" FROM \"Student\" where \"group\" = ?";
        PreparedStatement pstmt = null;
        try {
            pstmt = connection.prepareStatement(query);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
        try {
            pstmt.setInt(1, searchTerm);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
        ResultSet rs = null;
        try {
            rs = pstmt.executeQuery();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

        List<String> list = new ArrayList<>();
        while (true) {
            try {
                if (!rs.next()) break;
            } catch (SQLException e) {
                throw new RuntimeException(e);
            }
            try {
                String fullname = rs.getString("fullname");
                list.add(fullname);
            } catch (SQLException e) {
                throw new RuntimeException(e);
            }
            // обработка результата
        }
        request.setAttribute("list", list);
        request.getRequestDispatcher("/SecondFile.jsp").forward(request, response);
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        response.getWriter().println(Integer.parseInt(request.getParameter("listSize")));
    }
}
