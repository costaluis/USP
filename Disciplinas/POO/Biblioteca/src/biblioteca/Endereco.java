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
public class Endereco {
    private String rua;
    private int num;
    private String cidade;

    public Endereco() {
        rua = null;
        num = 0;
        cidade = null;
    }

    public void setRua(String rua) throws NullPointerException {
        if(rua.isEmpty()){
            throw new NullPointerException("Entrada Invalida!");
        }
        this.rua = rua;
    }

    public void setNum(int num) throws IllegalArgumentException {
        if(num < 1){
            throw new IllegalArgumentException("Numero Invalido!");
        }
        this.num = num;
    }

    public void setCidade(String cidade) throws NullPointerException {
        if(cidade.isEmpty()){
            throw new NullPointerException("Entrada Invalida!");
        }
        this.cidade = cidade;
    }

    public String getRua() {
        return rua;
    }

    public int getNum() {
        return num;
    }

    public String getCidade() {
        return cidade;
    }
    
    

}
    
    
    
