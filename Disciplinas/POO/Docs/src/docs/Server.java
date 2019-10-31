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
import java.util.LinkedList;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JOptionPane;

/**
 *
 * @author luis
 */
public class Server implements Runnable {
    Docs arq;
    File arquivo;
    private static boolean online;

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

    public Server() {
    }

    public Server(Docs arq) {
        this.arq = arq;
        this.online = true;
    }
    
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

    public static boolean isOnline() {
        return online;
    }

    public static void setOnline(boolean online) {
        Server.online = online;
    }

    
    
    
    
    
    
}
