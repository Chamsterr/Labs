package lab.p2p.async;

import javax.jms.*;
import com.sun.messaging.ConnectionFactory;
import com.sun.messaging.ConnectionConfiguration;
import lab.p2p.Prospect;
public class SenderASYNC{
    public static void main(String[] args) {
        ConnectionFactory cf = new ConnectionFactory();

        try(JMSContext jmsContext=cf.createContext("admin","admin")){
            cf.setProperty(ConnectionConfiguration.imqAddressList,"mq://127.0.0.1:7676,mq://127.0.0.1:7676");
            Destination dest=jmsContext.createQueue("Ex2_ASYNC");
            Prospect test = new Prospect(5,15,"Buffer","keeper","Austria","B");
            ObjectMessage objMes= jmsContext.createObjectMessage(test);
            JMSProducer jmsProducer= jmsContext.createProducer();
            jmsProducer.send(dest,objMes);
            System.out.println("Message has been sent...");
        } catch (JMSException e) {
            throw new RuntimeException(e);
        }
    }
}
