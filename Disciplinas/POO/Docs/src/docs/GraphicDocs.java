/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package docs;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.LinkedList;
import java.util.Scanner;
import javax.swing.JButton;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JMenuItem;
import javax.swing.border.EtchedBorder;
import javax.swing.border.TitledBorder;

/**
 *
 * @author luis
 */
public class GraphicDocs extends JFrame {
    
    Docs arq;
    Thread t;
    
    JTextArea texto = new JTextArea();
    JTextArea docsText = new JTextArea();
    JScrollPane scrollComando = new JScrollPane(docsText); 
    JScrollPane scrollTexto = new JScrollPane(texto); 
    JButton adicionarBut = new JButton("Adicionar");
    JButton removerBut = new JButton("Remover");
    JButton desfazerBut = new JButton("Desfazer");
    JButton refazerBut = new JButton("Refazer");
    JButton copyBut = new JButton("Copiar");
    JButton pasteBut = new JButton("Colar");
    JButton cutBut = new JButton("Recortar");
    JMenuBar menuBar = new JMenuBar();
    JPanel panelBut = new JPanel();
    JPanel panelText = new JPanel();
    JFrame helpFrame = new JFrame("Help");
    
    public GraphicDocs(Docs arq, Server s) {
        super("Docs");
        
        this.arq = arq;
        t = new Thread(s);
        this.setSize(800, 800);
        
        texto.setEditable(false);
        texto.setLineWrap(true);
        docsText.setLineWrap(true);
        scrollComando.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);
        scrollComando.setPreferredSize(new Dimension(400,400));
        scrollTexto.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);
        scrollTexto.setPreferredSize(new Dimension(400,400));
        this.setJMenuBar(menuBar);
        
        JMenu fileMenu = new JMenu("File");
        
        menuBar.add(fileMenu);

        JMenuItem helpMenu = new JMenuItem("Help");
        
        menuBar.add(helpMenu);
        
        helpMenu.setSize(10, 30);
        
        JPanel helpPanel = new JPanel();
        JPanel adHPanel = new JPanel();
        JPanel remHPanel = new JPanel();
        JPanel ccpHPanel = new JPanel();
        
        
        helpFrame.setSize(450,220);
        
        helpFrame.add(helpPanel);
       
        JTextArea adHLabel = new JTextArea("Para adicionar um texto, digite-o na área de comandos e então pressione o botão Adicionar.");
        JTextArea remHLabel = new JTextArea("Para remover um trecho do texto, digite o número de caracteres a serem removidos na área de comandos e então pressione o botão Remover.");
        JTextArea ccpHLabel = new JTextArea("Para copiar ou recortar, selecione o texto desejado e então clique no respectivo botão. Para colar, basta clicar no botão Colar.");
        
        adHLabel.setSize(440,100);
        remHLabel.setSize(440,100);
        ccpHLabel.setSize(440,100);
        
        adHLabel.setLineWrap(true);
        adHLabel.setEditable(false);
        remHLabel.setLineWrap(true);
        remHLabel.setEditable(false);
        ccpHLabel.setLineWrap(true);
        ccpHLabel.setEditable(false);
        
        helpFrame.getContentPane().setBackground(Color.red);
        
        adHLabel.setBorder(new TitledBorder(new EtchedBorder(),"Adicionar"));
        remHLabel.setBorder(new TitledBorder(new EtchedBorder(),"Remover"));
        ccpHLabel.setBorder(new TitledBorder(new EtchedBorder(),"Copiar/Recortar/Colar"));
        
        GridBagLayout grid = new GridBagLayout();
        
        helpPanel.setLayout(grid);
        
        GridBagConstraints c = grid.getConstraints(helpPanel);
        c.gridx = 0;
        c.gridy = 0;
        helpPanel.add(adHPanel,c);
        c.gridx = 0;
        c.gridy = 1;
        helpPanel.add(remHPanel,c);
        c.gridx = 0;
        c.gridy = 2;
        helpPanel.add(ccpHPanel,c);
        
        helpPanel.setBackground(Color.WHITE);
        adHPanel.setBackground(Color.WHITE);
        remHPanel.setBackground(Color.WHITE);
        ccpHPanel.setBackground(Color.WHITE);
                      
        adHPanel.add(adHLabel);
        remHPanel.add(remHLabel);
        ccpHPanel.add(ccpHLabel);        
        
        JMenuItem openMenu = new JMenuItem("Open");
        JMenuItem exitMenu = new JMenuItem("Exit");
        JMenuItem saveMenu = new JMenuItem("Save");
        JMenuItem saveAsMenu = new JMenuItem("Save as...");
        JMenuItem discMenu = new JMenuItem("Disconnect");
        
        fileMenu.add(openMenu);
        fileMenu.add(saveMenu);
        fileMenu.add(saveAsMenu);
        fileMenu.addSeparator();
        fileMenu.add(discMenu);
        fileMenu.addSeparator();
        fileMenu.add(exitMenu);
        
        
        panelBut.setLayout(grid);
        c = grid.getConstraints(panelBut);
        c.gridx = 0;
        c.gridy = 0;
        panelBut.add(adicionarBut, c);
        c.gridx = 1;
        c.gridy = 0;
        panelBut.add(removerBut, c);
        c.gridx = 2;
        c.gridy = 0;
        panelBut.add(desfazerBut, c);
        c.gridx = 3;
        c.gridy = 0;
        panelBut.add(refazerBut, c);
        c.gridx = 4;
        c.gridy = 0;
        panelBut.add(copyBut, c);
        c.gridx = 5;
        c.gridy = 0;
        panelBut.add(pasteBut, c);
        c.gridx = 6;
        c.gridy = 0;
        panelBut.add(cutBut, c);
        
        
        this.setLayout(new BorderLayout());
        this.add(panelBut, BorderLayout.NORTH);
        
        docsText.setBorder(new TitledBorder(new EtchedBorder(),"Comandos"));
        texto.setBorder(new TitledBorder(new EtchedBorder(),"Texto"));
        panelText.setLayout(new GridLayout(2,1));

        texto.setText(arq.getTexto().toString());
        
        this.add(scrollComando, BorderLayout.CENTER);
        this.add(scrollTexto, BorderLayout.SOUTH);
        
        adicionarBut.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e) {
                Docs.InsereTexto(arq, Docs.InputString(docsText.getText()), true);
                texto.setText(arq.getTexto().toString());
                docsText.setText("");
            }
            
        });
        
        removerBut.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e) {
                String tmp;
                int num;
                tmp = docsText.getText();
                try{
                    num = Integer.parseInt(tmp);
                    Docs.RemoveTexto(arq, num, true);
                    docsText.setText("");
                    texto.setText(arq.getTexto().toString());
                }
                catch(IllegalArgumentException f){
                    JOptionPane.showMessageDialog(GraphicDocs.this,"Digite um número válido!");
                    docsText.setText("");
                }
            }
        });
        
        refazerBut.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e) {
                Docs.Refazer(arq);
                texto.setText(arq.getTexto().toString());
            }
            
        });
        
        desfazerBut.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e) {
                
                try{
                    Docs.Desfazer(arq);
                    texto.setText(arq.getTexto().toString());
                }
                catch(NullPointerException f){
                    
                }
            }
            
        });
        
        copyBut.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e) {
                arq.setCopy_paste(texto.getSelectedText());
            }
            
        });
        
        cutBut.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e) {
                int fim = texto.getSelectionEnd();
                int i;
                
                arq.setCopy_paste(texto.getSelectedText());
                try{
                    Docs.RemoveTexto(arq, arq.getCopy_paste().length(), false, fim);
                    texto.setText(arq.getTexto().toString());
                }catch(NullPointerException d){
                    
                }
            }
            
        });
        
        pasteBut.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e) {
                try{    
                    Docs.InsereTexto(arq, Docs.InputString(arq.getCopy_paste()), true);
                    texto.setText(arq.getTexto().toString());
                }catch(NullPointerException d){
                    
                }
                
            }
            
        });
        
        exitMenu.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        });
        
        openMenu.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e) {
                JFileChooser file = new JFileChooser(); 
                int returnVal = file.showOpenDialog(openMenu);
                
                if (returnVal == JFileChooser.APPROVE_OPTION) {
                    arq.setF(file.getSelectedFile());
                    try {
                        Scanner s = new Scanner(arq.getF());
                        arq.setTexto(Docs.InputString(""));
                        while(s.hasNext()){
                            Docs.InsereTexto(arq, Docs.InputString(s.nextLine()), false);
                            if(s.hasNext()){
                                Docs.InsereTexto(arq, Docs.InputString("\n"), false);
                            }  
                        }
                        if(!t.isAlive()){
                            t.start();
                        }
                    } catch (FileNotFoundException ex) {
                        JOptionPane.showMessageDialog(GraphicDocs.this,"Arquivo nao encontrado");
                    }
                }
                arq.setCopy_paste("");
                arq.setPilha(new LinkedList());
                texto.setText(arq.getTexto().toString());
            }
        });
        
        saveMenu.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e) {
                if(arq.getF()==null){
                    JFileChooser file = new JFileChooser(); 
                    int returnVal = file.showSaveDialog(saveMenu);
                
                    if (returnVal == JFileChooser.APPROVE_OPTION) {
                        arq.setF(file.getSelectedFile());
                        if(!t.isAlive()){
                            t.start();
                        }
                        t.interrupt();
                    } 
                }else{
                    t.interrupt();
                }
            }
        });
        
        saveAsMenu.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e) {

                JFileChooser file = new JFileChooser(); 
                int returnVal = file.showSaveDialog(saveMenu);
                
                if (returnVal == JFileChooser.APPROVE_OPTION) {
                    arq.setF(file.getSelectedFile());
                    t.interrupt();
                }
                
            }
        });
        
        discMenu.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e) {
                if(t.isAlive()){
                    Server.setOnline(false);
                    t.interrupt();
                }
                t = new Thread(s);
                arq.setTexto(Docs.InputString(""));
                arq.setF(null);
                arq.setPilha(new LinkedList());
                arq.setCopy_paste("");
                texto.setText(arq.getTexto().toString());
            }
            
        });
        
        helpMenu.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e) {
                helpFrame.setVisible(true);
            }
            
        });
    }
    
    
    
    
  
}
