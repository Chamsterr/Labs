package org.example;

import java.io.*;
import java.net.*;
import java.util.Scanner;

public class Client {
    public static void main(String[] args) throws IOException {
        String serverAddress = "localhost"; // адрес сервера
        int port = 8081; // порт сервера

        Socket socket = new Socket(serverAddress, port);
        PrintWriter out = new PrintWriter(socket.getOutputStream(), true);

        // Чтение сообщений из консоли и отправка их на сервер
        Scanner scanner = new Scanner(System.in);

        Scanner sendReader = new Scanner(socket.getInputStream());
        String message;
        while (true) {
            message = scanner.nextLine();
            out.println(message);
            String s = sendReader.nextLine();
            System.out.println(s);
            // Проверка на выход из цикла
            if (message.equals("exit")) {
                break;
            }
        }

        // Закрытие потоков и сокета
        out.close();
        socket.close();
    }
}