/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package serverdocs;

import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.FileWriter;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Vector;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;

/**
 * Classe referente à interface gráfica do servidor.
 * 
 * @author Joao Pedro
 * @author Luis Fernando
 * 
 */
public class GraphicServer extends JFrame {

    JLabel servidor = new JLabel("Servidor");
    JButton OnOff = new JButton("LIGAR");
    JButton Desconectar = new JButton("Desconectar");
    boolean ligado;

    /**
     *Construtor da interface gráfica do servidor.
     * 
     * @param server
     * @param clients
     * @param arquivos
     * @param nomeArq
     * @throws InterruptedException
     */
    public GraphicServer(ServerSocket server, Vector<ForwardMessage> clients, Vector<String> arquivos, Vector<String> nomeArq) throws InterruptedException {
        this.setVisible(true);
        this.setLayout(new BorderLayout());

        this.ligado = false;
        this.add(servidor, BorderLayout.NORTH);
        this.add(OnOff, BorderLayout.SOUTH);
        this.add(Desconectar, BorderLayout.CENTER);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        this.pack();

        OnOff.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if (GraphicServer.this.ligado) {
                    GraphicServer.this.ligado = false;
                    OnOff.setText("LIGAR");
                    Desconectar.doClick();
                } else {
                    GraphicServer.this.ligado = true;
                    OnOff.setText("DESLIGAR");       
                }
            }
        });

        Desconectar.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try {
                    for (ForwardMessage c : clients) {
                        c.getInput().close();
                        c.getOutput().close();
                        c.getSocket().close();
                    }
                    FileWriter writer = new FileWriter("arquivos.txt");
                    for (String c : nomeArq) {
                        writer.write(c);
                        writer.write('\n');
                    }
                    writer.close();
                    for (int i = 0; i < nomeArq.size(); i++) {
                        writer = new FileWriter(nomeArq.get(i));
                        writer.write(arquivos.get(i));
                        writer.close();
                    }

                } catch (IOException ex) {
                    Logger.getLogger(GraphicServer.class.getName()).log(Level.SEVERE, null, ex);
                }
            }

        });

        Socket socket;

        while (true) {
            Thread.sleep(50);
            while (this.ligado) {
                try {
                    socket = server.accept();
                    while(!this.ligado){
                        Thread.sleep(50);
                    }
                    ObjectInputStream input = new ObjectInputStream(socket.getInputStream());
                    ObjectOutputStream output = new ObjectOutputStream(socket.getOutputStream());

                    output.writeInt(nomeArq.size());
                    output.flush();

                    for (String a : nomeArq) {
                        output.writeUTF(a);
                        output.flush();
                    }

                    String arq = input.readUTF();

                    int indice = nomeArq.indexOf(arq);

                    if (indice == -1) {
                        output.writeUTF("");
                        output.flush();
                        nomeArq.add(arq);
                        arquivos.add("");
                        indice = nomeArq.size() - 1;
                    } else {
                        output.writeUTF(arquivos.get(indice));
                        output.flush();
                    }

                    ForwardMessage client = new ForwardMessage(input, output, clients, arquivos, arquivos.get(indice), nomeArq, nomeArq.elementAt(indice), socket);
                    clients.add(client);
                    Thread t = new Thread(client);
                    t.start();

                } catch (IOException ex) {

                }

            }
        }

    }

}
