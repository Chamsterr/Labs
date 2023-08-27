package org.example;

import java.io.*;
import java.net.*;
import java.util.*;

public class Server {
    private static final int PORT = 8080;
    private static Map<String, String> topics = new HashMap<>();

    public static void main(String[] args) {
        topics.put("topic1", "Message for topic 1");
        topics.put("topic2", "Message for topic 2");
        topics.put("topic3", "Message for topic 3");

        try (ServerSocket serverSocket = new ServerSocket(PORT)) {
            System.out.println("Server started on port " + PORT);

            while (true) {
                new TopicHandler(serverSocket.accept()).start();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static class TopicHandler extends Thread {
        private Socket socket;
        private BufferedReader in;
        private PrintWriter out;

        public TopicHandler(Socket socket) {
            this.socket = socket;
        }

        public void run() {
            try {
                in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
                out = new PrintWriter(socket.getOutputStream(), true);

                while (true) {
                    String command = in.readLine();

                    if (command.equals("/topic")) {
                        out.println(topics.keySet());
                    } else if (topics.containsKey(command)) {
                        out.println(topics.get(command));
                    } else {
                        out.println("Unknown command or topic!");
                    }
                }
            } catch (IOException e) {
                e.printStackTrace();
            } finally {
                try {
                    socket.close();
                } catch (IOException e) {}
            }
        }
    }
}
