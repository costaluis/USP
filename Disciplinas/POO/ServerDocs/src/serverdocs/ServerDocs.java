/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package serverdocs;

import java.io.FileReader;
import java.io.IOException;
import java.net.ServerSocket;
import java.util.Scanner;
import java.util.Vector;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JFrame;

/**
 * Classe referente ao servidor do editor de texto.
 *
 * @author Joao Pedro
 * @author Luis Fernando
 * 
 */
public class ServerDocs {

    /**
     * Função main do Servidor.
     * 
     * @author Joao Pedro
     * @author Luis Fernando
     * @param args
     * @throws java.io.IOException
     * 
     */
    public static void main(String[] args) throws IOException {
        ServerSocket server = new ServerSocket(12345);
        Vector<ForwardMessage> clients = new Vector<ForwardMessage>();
        Vector<String> arquivos = new Vector<String>();
        Vector<String> nomeArq = new Vector<String>();
        
        Scanner reader = new Scanner(new FileReader("arquivos.txt"));
        while(reader.hasNext()){
            nomeArq.add(reader.nextLine());
        }
        for(int i=0; i<nomeArq.size(); i++){
            reader = new Scanner(new FileReader(nomeArq.get(i)));
            arquivos.add("");
            while(reader.hasNext()){
                arquivos.set(i, arquivos.get(i).concat(reader.nextLine()));
            }
        }
        GraphicServer graphic;
        try {
            graphic = new GraphicServer(server, clients, arquivos, nomeArq);
            graphic.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        } catch (InterruptedException ex) {
            Logger.getLogger(ServerDocs.class.getName()).log(Level.SEVERE, null, ex);
        }
        
       
    }
    
}
