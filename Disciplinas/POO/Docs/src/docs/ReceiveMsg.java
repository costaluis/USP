/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package docs;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JOptionPane;
import javax.swing.JTextArea;

/**
 * Classe que contém a thread que recebe o texto editado por outros clientes.
 *
 * @author Joao Pedro
 * @author Luis Fernando
 */
public class ReceiveMsg implements Runnable {

    private ObjectInputStream input;
    private ObjectOutputStream output;
    private JTextArea text;
    private Docs programa;
    private GraphicDocs graphic;
    public boolean on;

    /**
     * Construtor da thread do cliente.
     * 
     * @param input
     * @param text
     * @param output
     * @param programa
     * @param graphic 
     * 
     * @author João Pedro
     * @author Luis Fernando
     */
    public ReceiveMsg(ObjectInputStream input, JTextArea text, ObjectOutputStream output, Docs programa, GraphicDocs graphic) {
        this.input = input;
        this.output = output;
        this.text = text;
        this.on = false;
        this.programa = programa;
        this.graphic = graphic;
    }

    /**
     * Thread referente ao recebimento do texto.
     * 
     * @author Joao Pedro
     * @author Luis Fernando
     *
     */
    @Override
    public void run() {

        try {
            int n = input.readInt();
            String[] b = new String[n];
            for (int i = 0; i < n; i++) {
                b[i] = input.readUTF();
            }
            EscolheArq inicio = new EscolheArq(b, output);
            while (!inicio.closed) {
                Thread.sleep(50);
            }
            this.on = true;
            String t = input.readUTF();
            text.setText(t);
            programa.setTexto(Docs.InputString(t));
            int num = input.readInt();
            this.graphic.numClientes.setText("Clientes conectados: " + num);

        } catch (IOException | InterruptedException ex) {
            Logger.getLogger(ReceiveMsg.class.getName()).log(Level.SEVERE, null, ex);
        }

        String msgS;
        Text msg;
        while (!Thread.interrupted()) {
            
            try {
                msgS = input.readUTF();
                int num = input.readInt();
             
                this.graphic.numClientes.setText("Clientes conectados: " + num);
                msg = Docs.InputString(msgS);
                
                this.programa.setTexto(msg);
                this.text.setText(msgS);
            } catch (IOException ex) {
                try {
                    this.input.close();
                    this.output.close();
                    this.on = false;
                    JOptionPane.showMessageDialog(graphic, "Servidor encerrado!");
                    graphic.dispose(); 
                    System.exit(0);
                } catch (IOException ex1) {
                }    
            }

        }
    }

}
