package org.example;

import java.io.*;
import java.net.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class Server {
    public static void main(String[] args) throws IOException {
        List<ClientHandler> clients = new ArrayList<>();

        Boolean gameFlag = true;
        ServerSocket serverSocket = new ServerSocket(8081);
        System.out.println("Waiting for client...");

        while (clients.size() < 2) {
            Socket clientSocket = serverSocket.accept();
            ClientHandler ch = new ClientHandler(clientSocket);
            ch.start();
            clients.add(ch);
            System.out.println("Client connected.");
        }

        Random rd = new Random();

        ClientHandler main = clients.get(Math.round(rd.nextInt(2)));
        clients.remove(main);

        main.getOut().println(false);
        Integer number = Integer.parseInt(main.getIn().readLine());

        System.out.println(number);

        clients.get(0).getOut().println(true);

        while (Integer.parseInt(clients.get(0).getIn().readLine()) != number){
           clients.get(0).getOut().println(false);
        }

        clients.get(0).getOut().println(true);
        clients.get(0).getOut().println("Бинго");
    }

    public static class ClientHandler extends Thread{
        Socket socket;
        BufferedReader in;
        PrintWriter out;

        public Socket getSocket() {
            return socket;
        }

        public BufferedReader getIn() {
            return in;
        }

        public PrintWriter getOut() {
            return out;
        }

        public ClientHandler(Socket socket) throws IOException {
            this.socket = socket;
            this.in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            this.out = new PrintWriter(socket.getOutputStream(), true);
        }

        @Override
        public void run() {
        }
    }
}
