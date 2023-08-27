package org.example;

import java.io.IOException;
import java.net.*;

public class UDPSender {
    private DatagramSocket socket;
    private InetAddress adress;
    private int port;
    public UDPSender(String ipAddress, int port) throws SocketException, UnknownHostException {
        this.socket = new DatagramSocket();
        this.adress = InetAddress.getByName(ipAddress);
        this.port = port;
    }

    public void sendMessage(String message) throws IOException {
        byte[] messageBytes = message.getBytes();
        DatagramPacket datagramPacket = new DatagramPacket(messageBytes, messageBytes.length, adress, port);
        socket.send(datagramPacket);
    }

}
