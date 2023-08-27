package org.example;

import java.io.*;
import java.net.*;
import java.util.Scanner;

public class Client {
    public static void main(String[] args) throws IOException {
        String serverAddress = "localhost";
        int port = 8081;

        Socket socket = new Socket(serverAddress, port);
        PrintWriter out = new PrintWriter(socket.getOutputStream(), true);

        Scanner scanner = new Scanner(System.in);

        Scanner sendReader = new Scanner(socket.getInputStream());

        Boolean isGuesser = Boolean.valueOf(sendReader.nextLine());

        if (isGuesser){
            System.out.println("Угадываем число: ");
            do {
                out.println(scanner.nextLine());
            }while (!Boolean.valueOf(sendReader.nextLine()));
            System.out.println("Грац");
        }
        else {
            System.out.println("Загадайте число");
            out.println(scanner.nextLine());
        }
    }
}
