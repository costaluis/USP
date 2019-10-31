/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package cronometro;

import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.GridLayout;
import java.awt.Insets;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.text.DecimalFormat;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextField;

/**
 *
 * @author luis
 */
public class GraphsCronometro extends JFrame {
    Thread t1;
    JTextField minText = new JTextField("000");
    JTextField segText = new JTextField("00");
    JTextField miliText = new JTextField("00");
    
    JButton exitBut = new JButton("Fechar");
    JButton resetBut = new JButton("Reset");
    JButton stopgoBut = new JButton("Iniciar");
    
    JPanel butPanel = new JPanel();
    JPanel textPanel = new JPanel();

    public GraphsCronometro() {
        super("Cronometro");
        
        this.setSize(new Dimension(300, 100));
        
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        minText.setEditable(false);
        segText.setEditable(false);
        miliText.setEditable(false);
        
        GridBagLayout grid = new GridBagLayout();
        textPanel.setLayout(grid);
        GridBagConstraints c = grid.getConstraints(textPanel);
        c.insets = new Insets(0,0,0,5);
        c.gridx = 0;
        c.gridy = 0;
        c.ipadx = 15;
        c.ipady = 4;
        textPanel.add(minText,c);
        c.gridx = 1;
        c.gridy = 0;
        c.ipadx = 15;
        c.ipady = 4;
        textPanel.add(segText,c);
        c.gridx = 2;
        c.gridy = 0;
        c.ipadx = 32;
        c.ipady = 4;
        textPanel.add(miliText,c);
        
        butPanel.setLayout(new GridLayout(1,3));
        butPanel.add(exitBut);
        butPanel.add(resetBut);
        butPanel.add(stopgoBut);
        
        this.setLayout(new BorderLayout());
        this.add(textPanel, BorderLayout.CENTER);
        this.add(butPanel, BorderLayout.SOUTH);
        
        DecimalFormat fmt = new DecimalFormat("00");
        String tmp = fmt.format(0);
        minText.setText(tmp);
        segText.setText(tmp);
        fmt = new DecimalFormat("000");
        tmp = fmt.format(0);
        miliText.setText(tmp);
        
        this.t1 = new Thread(new Contagem(this.miliText,this.segText,this.minText));
        
        exitBut.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        });
        
        resetBut.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e) {
                DecimalFormat fmt = new DecimalFormat("00");
                String tmp = fmt.format(0);
                minText.setText(tmp);
                segText.setText(tmp);
                fmt = new DecimalFormat("000");
                tmp = fmt.format(0);
                miliText.setText(tmp);
                t1.interrupt();
                stopgoBut.setText("Iniciar");
            }         
        });
        
        stopgoBut.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e) {
                String msg = stopgoBut.getText();
                if(msg.equals("Iniciar")){
                    t1 = new Thread(new Contagem(miliText,segText,minText));
                    t1.start();
                    stopgoBut.setText("Parar");
                    
                }
                if(msg.equals("Parar")){
                    t1.interrupt();
                    stopgoBut.setText("Iniciar");
                }
            }
        });
        
        
        
        
    }
    
    
    
    
}
