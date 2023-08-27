package org.example;

import java.io.*;
import java.net.*;

public class Server {
    public static void main(String[] args) throws IOException {
        ServerSocket serverSocket = new ServerSocket(8081);

        while (true) {
            System.out.println("Waiting for client...");
            Socket clientSocket = serverSocket.accept();
            System.out.println("Client connected.");

            BufferedReader in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
            PrintWriter out = new PrintWriter(clientSocket.getOutputStream(), true);
            int yesCounter = 0;
            int noCounter = 0;
            String inputLine;
            while ((inputLine = in.readLine()) != null) {
                if (inputLine.equals("/yes"))
                {
                    System.out.println("yes");
                    yesCounter += 1;
                    out.println();
                }
                else if (inputLine.equals("/no"))
                {
                    System.out.println("no");
                    noCounter += 1;
                    out.println();
                }
                else if (inputLine.equals("/getall"))
                {
                    System.out.println("ga");
                    out.println("yes - " + yesCounter  + " no - " + noCounter);
                }
                else if (inputLine.equals("/help"))
                {
                    System.out.println("help");
                    out.println("/yes "  + " /no" + " /getall");
                }
                else if (inputLine.equals("/exit")) {
                    break;
                }
                out.flush();
            }


            System.out.println("Client disconnected.");

            // Закрытие потоков и сокета
            in.close();
            clientSocket.close();
        }
    }
}