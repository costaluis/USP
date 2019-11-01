/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package docs;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

/**
 * Classe que roda o servidor
 * @author Joao Pedro
 * @author Luis Fernando
 */
public class Server implements Runnable {
    Docs arq;
    File arquivo;
    private static boolean online;

    /**
     * Construtor da classe Server com paramêtros Docs e File.
     * @param arquivo
     * @param arq
     * @throws FileNotFoundException 
     */
    public Server(File arquivo, Docs arq) throws FileNotFoundException {
        this.arq = arq;
        this.online = true;
        this.arquivo = arquivo;
        FileReader inputStream = new FileReader(arquivo);
        Scanner s = new Scanner(inputStream);
        arq.setTexto(Docs.InputString(""));
        while(s.hasNext()){
            Docs.InsereTexto(arq,Docs.InputString(s.nextLine()),false);
        }
    }

    /**
     * Construtor da classe Server com parâmetro Docs.
     * @param arq 
     * @author João Pedro
     * @author Luis Fernando
     */
    public Server(Docs arq) {
        this.arq = arq;
        this.online = true;
    }
    
    /**
     *Thread que roda o servidor, salvando o arquivo ou desconectando o usuário
     * @author João Pedro
     * @author Luis Fernando
     */
    @Override
    public void run() {
        while(online){
            while(!Thread.interrupted() && online){
                try {
                    Thread.sleep(50);
                } catch (InterruptedException ex) {
                    break;
                }
            }
            
            try {
                FileWriter fw = new FileWriter(arq.getF());
                fw.write(arq.getTexto().toString());
                fw.close();
            } catch (IOException | NullPointerException ex) {
                break;
            }      
        }
        Server.setOnline(true);
       
    }

    /**
     * Retorna o status do servidor, ou seja, se ele está online ou não.
     * @return boolean
     * @author João Pedro
     * @author Luis Fernando
     */
    public static boolean isOnline() {
        return online;
    }

    /**
     * Altera o status do servidor.
     * @param online 
     * @author João Pedro
     * @author Luis Fernando
     */
    public static void setOnline(boolean online) {
        Server.online = online;
    }

    
    
    
    
    
    
}
