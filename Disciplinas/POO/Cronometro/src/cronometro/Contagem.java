/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package cronometro;

import java.text.DecimalFormat;
import javax.swing.JTextField;

/**
 *
 * @author luis
 */
public class Contagem implements Runnable {
    JTextField segText, minText, miliText;

    public Contagem(JTextField miliText, JTextField segText, JTextField minText) {
        this.segText = segText;
        this.miliText = miliText;
        this.minText = minText;
    }

    @Override
    public void run() {
        try {
            while(!Thread.interrupted()){
                Thread.sleep(1);
                int num = Integer.parseInt(miliText.getText());
                DecimalFormat fmt = new DecimalFormat("000");
                if(num < 999){
                    num++;
                    miliText.setText(fmt.format(num));
                }else{
                    num = 0;
                    fmt = new DecimalFormat("00");
                    miliText.setText(fmt.format(num));
                    num = Integer.parseInt(segText.getText());
                    if(num < 59){
                        num++;
                        segText.setText(fmt.format(num));
                    }else{
                        num = 0;
                        segText.setText(fmt.format(num));
                        num = Integer.parseInt(minText.getText());
                        num ++; 
                        minText.setText(fmt.format(num));
                    }
                }
            }         
        } catch (InterruptedException ex) {
        }
        
    }
    
}
