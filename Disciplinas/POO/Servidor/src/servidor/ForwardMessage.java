/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package servidor;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.Vector;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author manzato
 */
public class ForwardMessage implements Runnable {

    private ObjectInputStream input;
    private ObjectOutputStream output;
    private Vector<ForwardMessage> clients;

    public ForwardMessage(ObjectInputStream input, ObjectOutputStream output, Vector<ForwardMessage> clients) {
        this.input = input;
        this.output = output;
        this.clients = clients;
    }
    
    @Override
    public void run() {
        while(true) {
            try {
                String msg = input.readUTF();
                
                for(ForwardMessage c : clients) {
                    if(this != c) {
                        c.output.writeUTF(msg);
                        c.output.flush();
                    }
                }
            } catch (IOException ex) {
                try {
                    clients.remove(this);
                    this.input.close();
                    this.output.close();
                } catch (IOException ex1) {
                    Logger.getLogger(ForwardMessage.class.getName()).log(Level.SEVERE, null, ex1);
                } finally {
                    return;
                }
            }
        }
    }
    
}
