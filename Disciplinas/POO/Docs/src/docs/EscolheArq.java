/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package docs;

import java.awt.BorderLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;
import java.io.ObjectOutputStream;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.DefaultListModel;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.JOptionPane;
import javax.swing.JPanel;

/**
 * Classe referente à janela de seleção de arquivos.
 *
 * @author Joao Pedro
 * @author Luis Fernando
 * 
 */
public class EscolheArq extends JFrame{
    JPanel botoes = new JPanel();
    JLabel arquivos = new JLabel("Arquivos:");
    DefaultListModel d = new DefaultListModel();
    JList lista = new JList(d);
    JButton novoArq = new JButton("Novo arquivo");
    JButton select = new JButton("Selecionar arquivo");
    boolean closed;
    
    /**
     * Construtor referente à interface gráfica da janela de seleção de arquivos.
     * @param arqs
     * @param output
     * 
     * @author Joao Pedro
     * @author Luis Fernando
     */
    public EscolheArq(String[] arqs, ObjectOutputStream output){
        this.setVisible(true);
        closed = false;
        this.setSize(300,300);
        this.setLayout(new BorderLayout());
        this.add(arquivos, BorderLayout.NORTH);
        this.add(lista, BorderLayout.CENTER);
        botoes.setLayout(new GridLayout());
        botoes.add(novoArq);
        botoes.add(select);
        this.add(botoes, BorderLayout.SOUTH);
        
        for(String a : arqs){
            d.addElement(a);
        }
        
        novoArq.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e) {
                String nome = JOptionPane.showInputDialog("Nome do arquivo");
                try {
                    output.writeUTF(nome);
                    output.flush();
                    EscolheArq.this.closed = true;
                    EscolheArq.this.setVisible(false);
                } catch (IOException ex) {
                    Logger.getLogger(EscolheArq.class.getName()).log(Level.SEVERE, null, ex);
                }
            }
        });
        
        select.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e) {
                String n = (String)lista.getSelectedValue();
                try {
                    output.writeUTF(n);
                    output.flush();
                    EscolheArq.this.closed = true;
                    EscolheArq.this.setVisible(false);
                } catch (IOException ex) {
                    Logger.getLogger(EscolheArq.class.getName()).log(Level.SEVERE, null, ex);
                }
                
            }
        });
    }

}