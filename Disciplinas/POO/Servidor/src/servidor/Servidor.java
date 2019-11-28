/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package servidor;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Vector;

/**
 *
 * @author manzato
 */
public class Servidor {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
        ServerSocket server = new ServerSocket(1234);
        Vector<ForwardMessage> clients = new Vector<ForwardMessage>();

        while (true) {
            System.out.println("Aguardando conexões...");
            Socket socket = server.accept();

            System.out.println("Conectado...");
            ObjectInputStream input = new ObjectInputStream(socket.getInputStream());
            ObjectOutputStream output = new ObjectOutputStream(socket.getOutputStream());

            //System.out.println("Obteve os fluxos...");
            ForwardMessage client = new ForwardMessage(input, output, clients);
            clients.add(client);
            Thread t = new Thread(client);
            t.start();
            //System.out.println("Iniciou a thread...");
        }
    }

}
