package org.example;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;

public class UDPReceiver {
    private DatagramSocket socket;
    private byte[] messageBuff;

    public UDPReceiver(DatagramSocket socket, byte[] messageBuff) {
        this.socket = socket;
        this.messageBuff = messageBuff;
    }

    public String receiveMessage() throws IOException {
        DatagramPacket packet = new DatagramPacket(messageBuff, messageBuff.length);
        socket.receive(packet);
        return new String(packet.getData(), 0, packet.getLength());
    }
}
