/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package biblioteca;

/**
 *
 * @author luis
 */
public class Local {
    private int andar;
    private String secao;

    public Local() {
        andar = 0;
        secao = null;
    }

    public Local(int andar, String secao) {
        this.andar = andar;
        this.secao = secao;
    }

    public void setAndar(int andar) throws IllegalArgumentException {
        if(andar < 1 || andar > 3){
            throw new IllegalArgumentException("Andar Invalido!");
        }
        this.andar = andar;
    }

    public void setSecao(String secao) throws NullPointerException {
        if(secao.isEmpty()){
            throw new NullPointerException("Entrada Invalida!");
        }
        this.secao = secao;
    }
    
    public String toString(){
        return "Andar: " + this.andar + "\n" + "Secao: " + this.secao;
    }
}


