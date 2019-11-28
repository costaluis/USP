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
import java.io.FileWriter;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;
import java.util.logging.Level;
import java.util.logging.Logger;
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
 * Classe que implementa a interface gráfica do cliente.
 *
 * @author Joao Pedro
 * @author Luis Fernando
 */
public class GraphicDocs extends JFrame {

    Docs arq;
    Thread t;
    ObjectInputStream input;
    ObjectOutputStream output;
    Socket socket;

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
    JLabel numClientes = new JLabel();

    /**
     * Construtor referente à Interface Gráfica do cliente.
     *
     * @param arq
     * @author João Pedro
     * @author Luis Fernando
     * @throws java.io.IOException
     */
    public GraphicDocs(Docs arq) throws IOException {
        super("Docs");

        this.socket = new Socket("127.0.0.1", 12345);

        this.output = new ObjectOutputStream(socket.getOutputStream());
        this.input = new ObjectInputStream(socket.getInputStream());

        this.arq = arq;
        ReceiveMsg tr = new ReceiveMsg(this.input, texto, output, arq, this);
        t = new Thread(tr);
        t.start();
        this.setSize(800, 800);

        texto.setEditable(false);
        texto.setLineWrap(true);
        docsText.setLineWrap(true);
        scrollComando.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);
        scrollComando.setPreferredSize(new Dimension(400, 400));
        scrollTexto.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);
        scrollTexto.setPreferredSize(new Dimension(400, 400));
        this.setJMenuBar(menuBar);

        JMenu fileMenu = new JMenu("File");

        menuBar.add(fileMenu);

        JMenuItem helpMenu = new JMenuItem("Help");

        menuBar.add(helpMenu);
        menuBar.add(numClientes);

        helpMenu.setSize(10, 30);

        JPanel helpPanel = new JPanel();
        JPanel adHPanel = new JPanel();
        JPanel remHPanel = new JPanel();
        JPanel ccpHPanel = new JPanel();

        helpFrame.setSize(450, 220);

        helpFrame.add(helpPanel);

        JTextArea adHLabel = new JTextArea("Para adicionar um texto, digite-o na área de comandos e então pressione o botão Adicionar.");
        JTextArea remHLabel = new JTextArea("Para remover um trecho do texto, digite o número de caracteres a serem removidos na área de comandos e então pressione o botão Remover.");
        JTextArea ccpHLabel = new JTextArea("Para copiar ou recortar, selecione o texto desejado e então clique no respectivo botão. Para colar, basta clicar no botão Colar.");

        adHLabel.setSize(440, 100);
        remHLabel.setSize(440, 100);
        ccpHLabel.setSize(440, 100);

        adHLabel.setLineWrap(true);
        adHLabel.setEditable(false);
        remHLabel.setLineWrap(true);
        remHLabel.setEditable(false);
        ccpHLabel.setLineWrap(true);
        ccpHLabel.setEditable(false);

        helpFrame.getContentPane().setBackground(Color.red);

        adHLabel.setBorder(new TitledBorder(new EtchedBorder(), "Adicionar"));
        remHLabel.setBorder(new TitledBorder(new EtchedBorder(), "Remover"));
        ccpHLabel.setBorder(new TitledBorder(new EtchedBorder(), "Copiar/Recortar/Colar"));

        GridBagLayout grid = new GridBagLayout();

        helpPanel.setLayout(grid);

        GridBagConstraints c = grid.getConstraints(helpPanel);
        c.gridx = 0;
        c.gridy = 0;
        helpPanel.add(adHPanel, c);
        c.gridx = 0;
        c.gridy = 1;
        helpPanel.add(remHPanel, c);
        c.gridx = 0;
        c.gridy = 2;
        helpPanel.add(ccpHPanel, c);

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

        fileMenu.add(openMenu);
        fileMenu.add(saveMenu);
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

        docsText.setBorder(new TitledBorder(new EtchedBorder(), "Comandos"));
        texto.setBorder(new TitledBorder(new EtchedBorder(), "Texto"));
        panelText.setLayout(new GridLayout(2, 1));

        texto.setText(arq.getTexto().toString());

        this.add(scrollComando, BorderLayout.CENTER);
        this.add(scrollTexto, BorderLayout.SOUTH);

        while (!tr.on) {
            try {
                Thread.sleep(50);
            } catch (InterruptedException ex) {
                Logger.getLogger(GraphicDocs.class.getName()).log(Level.SEVERE, null, ex);
            }
        }

        this.setVisible(true);

        adicionarBut.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Docs.InsereTexto(arq, Docs.InputString(docsText.getText()), true);
                texto.setText(arq.getTexto().toString());
                docsText.setText("");
                try {
                    output.writeUTF(texto.getText());
                    output.flush();
                } catch (IOException ex) {

                }
            }

        });

        removerBut.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String tmp;
                int num;
                tmp = docsText.getText();
                try {
                    num = Integer.parseInt(tmp);
                    Docs.RemoveTexto(arq, num, true);
                    docsText.setText("");
                    texto.setText(arq.getTexto().toString());
                } catch (IllegalArgumentException f) {
                    JOptionPane.showMessageDialog(GraphicDocs.this, "Digite um número válido!");
                    docsText.setText("");
                }
                try {
                    output.writeUTF(texto.getText());
                    output.flush();
                } catch (IOException ex) {
                    Logger.getLogger(GraphicDocs.class.getName()).log(Level.SEVERE, null, ex);
                }
            }
        });

        refazerBut.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Docs.Refazer(arq);
                texto.setText(arq.getTexto().toString());
                try {
                    output.writeUTF(texto.getText());
                    output.flush();
                } catch (IOException ex) {
                    Logger.getLogger(GraphicDocs.class.getName()).log(Level.SEVERE, null, ex);
                }
            }

        });

        desfazerBut.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {

                try {
                    Docs.Desfazer(arq);
                    texto.setText(arq.getTexto().toString());
                    output.writeUTF(texto.getText());
                    output.flush();
                } catch (NullPointerException | IOException f) {

                }

            }

        });

        copyBut.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                arq.setCopy_paste(texto.getSelectedText());
                try {
                    output.writeUTF(texto.getText());
                    output.flush();
                } catch (IOException ex) {
                    Logger.getLogger(GraphicDocs.class.getName()).log(Level.SEVERE, null, ex);
                }
            }

        });

        cutBut.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                int fim = texto.getSelectionEnd();
                int i;

                arq.setCopy_paste(texto.getSelectedText());
                try {
                    Docs.RemoveTexto(arq, arq.getCopy_paste().length(), false, fim);
                    texto.setText(arq.getTexto().toString());
                    output.writeUTF(texto.getText());
                    output.flush();
                } catch (NullPointerException | IOException d) {

                }
            }

        });

        pasteBut.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try {
                    Docs.InsereTexto(arq, Docs.InputString(arq.getCopy_paste()), true);
                    texto.setText(arq.getTexto().toString());
                    output.writeUTF(texto.getText());
                    output.flush();
                } catch (NullPointerException | IOException d) {

                }
            }

        });

        openMenu.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try {
                    t.interrupt();
                    GraphicDocs.this.input.close();
                    GraphicDocs.this.output.close();
                    GraphicDocs.this.socket.close();
                    System.out.println("aqui");
                    GraphicDocs.this.socket = new Socket("127.0.0.1", 12345);
                    GraphicDocs.this.output = new ObjectOutputStream(GraphicDocs.this.socket.getOutputStream());
                    GraphicDocs.this.input = new ObjectInputStream(GraphicDocs.this.socket.getInputStream());
                    System.out.println("oi");
                } catch (IOException ex) {
                    Logger.getLogger(GraphicDocs.class.getName()).log(Level.SEVERE, null, ex);
                }
                ReceiveMsg tr = new ReceiveMsg(GraphicDocs.this.input, GraphicDocs.this.texto, GraphicDocs.this.output, GraphicDocs.this.arq, GraphicDocs.this);
                t = new Thread(tr);
                t.start();

            }
        });

        exitMenu.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                try {
                    GraphicDocs.this.socket.close();
                    GraphicDocs.this.input.close();
                    GraphicDocs.this.output.close();
                } catch (IOException ex) {
                    Logger.getLogger(GraphicDocs.class.getName()).log(Level.SEVERE, null, ex);
                }
                
                System.exit(0);
            }
        });

        saveMenu.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {

                JFileChooser file = new JFileChooser();
                int returnVal = file.showSaveDialog(saveMenu);

                if (returnVal == JFileChooser.APPROVE_OPTION) {
                    try {
                        FileWriter writer = new FileWriter(file.getSelectedFile());
                        writer.write(GraphicDocs.this.texto.getText());
                        writer.close();
                    } catch (IOException ex) {
                        Logger.getLogger(GraphicDocs.class.getName()).log(Level.SEVERE, null, ex);
                    }
                    t.interrupt();
                }

            }
        });

        helpMenu.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                helpFrame.setVisible(true);
            }

        });
    }

}
