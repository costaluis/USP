/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package serverdocs;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;
import java.util.Vector;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 * Classe que contém a thread que repassa mensagens para os clientes que editam um mesmo arquivo.
 *
 * @author Joao Pedro 
 * @author Luis Fernando
 */
public class ForwardMessage implements Runnable {
    private ObjectInputStream input;
    private ObjectOutputStream output;
    private Vector<ForwardMessage> clients;
    private Vector<String> arquivos;
    private Vector<String> nomesArq;
    private Socket socket;
    private String nomeArq;
    private String arquivo;

    /**
     * Construtor para a thread do servidor.
     * 
     * @param input
     * @param output
     * @param clients
     * @param arquivos
     * @param arquivo
     * @param nomesArq
     * @param nomeArq
     * @param socket
     * 
     * @author Joao Pedro
     * @author Luis Fernando
     * 
     */
    public ForwardMessage(ObjectInputStream input, ObjectOutputStream output, Vector<ForwardMessage> clients, Vector<String> arquivos, String arquivo, Vector<String> nomesArq, String nomeArq, Socket socket) {
        this.input = input;
        this.output = output;
        this.clients = clients;
        this.arquivos = arquivos;
        this.arquivo = arquivo;
        this.nomesArq = nomesArq;
        this.nomeArq = nomeArq;
        this.socket = socket;
    }
    
    /**
     * Thread que repassa textos para os outros clientes.
     * 
     * @author Joao Pedro
     * @author Luis Fernando
     *
     */
    @Override
    public void run() {
        Text msg;
        String msgS;
        try {
            output.writeInt(this.numClients());
            output.flush();
        } catch (IOException ex) {
            Logger.getLogger(ForwardMessage.class.getName()).log(Level.SEVERE, null, ex);
        }
        while(true) {
            try {
                msgS = input.readUTF();
                msg = Docs.InputString(msgS);
                
                int indice = this.nomesArq.indexOf(this.nomeArq);
                arquivos.setElementAt(msgS, indice);
                
                for(ForwardMessage c : clients) {
                    if(this.nomeArq.equals(c.nomeArq)) {
                        c.output.writeUTF(msgS);
                        System.out.println(msgS);
                       
                        c.output.writeInt(this.numClients());
                        System.out.println(this.numClients());
                        c.output.flush();
                    }
                }
            } catch (IOException ex) {
                try {
                    clients.remove(this);
                    this.output.close();
                    this.input.close();                  
                } catch (IOException ex1) {
                    Logger.getLogger(ForwardMessage.class.getName()).log(Level.SEVERE, null, ex1);
                } finally {
                    return;
                }
            }
        }
    }

    /**
     *Função que retorna o InputStream obtido de um Socket.
     * 
     * @return ObjectInputStream
     * 
     * @author João Pedro
     * @author Luis Fernando
     */
    public ObjectInputStream getInput() {
        return input;
    }

    /**
     *Retorna o OutputStream obtido de um Socket.
     * 
     * @return ObjectOutputStream
     * 
     * @author João Pedro
     * @author Luis Fernando
     */
    public ObjectOutputStream getOutput() {
        return output;
    }

    /**
     *Retorna o Socket obtido de uma conexão.
     * 
     * @return Socket
     * 
     * @author João Pedro
     * @author Luis Fernando
     */
    public Socket getSocket() {
        return socket;
    }

    /**
     * Atribui um novo socket gerado de uma nova conexão.
     * 
     * @param socket
     * 
     * @author João Pedro
     * @author Luis Fernando
     */
    public void setSocket(Socket socket) {
        this.socket = socket;
    }
    
    /**
     * Função que retorna o número de clientes conectados no mesmo arquivo.
     * 
     * @author Joao Pedro 
     * @author Luis Fernando
     * 
     * @return int
     */
    public int numClients(){
        int total = 0;
        for(ForwardMessage c : this.clients){
            if(this.nomeArq.equals(c.nomeArq)){
                total++;
            }
        }
        return total;
    }
    
}
