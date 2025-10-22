import com.sun.messaging.ConnectionConfiguration;
import com.sun.messaging.ConnectionFactory;
import jakarta.jms.Destination;
import jakarta.jms.JMSContext;
import jakarta.jms.JMSProducer;
import jakarta.servlet.ServletException;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

import java.io.IOException;
import java.io.PrintWriter;

public class HelloServlet extends HttpServlet {
    public void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        PrintWriter writer = response.getWriter();
        ConnectionFactory factory = new com.sun.messaging.ConnectionFactory();
        String mes=request.getParameter("message");


        try{
            JMSContext context = factory.createContext("admin","admin");
            factory.setProperty(ConnectionConfiguration.imqAddressList, "mq://127.0.0.1:7676, mq://127.0.0.1:7676");

            Destination cardsQueue = context.createQueue("Servlet");
            JMSProducer producer = context.createProducer();

            producer.send(cardsQueue, mes);

            System.out.println("Placed an information...");
        } catch (Exception e) {
            System.out.println(e.getMessage());;
        }

        response.sendRedirect("");
    }
}
