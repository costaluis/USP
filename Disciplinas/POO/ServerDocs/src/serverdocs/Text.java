/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package serverdocs;

import java.util.LinkedList;

/**
 * Representa uma lista de caracteres.
 * @author João Pedro
 * @author Luis Fernando
 */
public class Text {
    
    private LinkedList <Character> texto;
    
    /**
     * Construtor da classe Text.
     * @author João Pedro
     * @author Luis Fernando
     */
    public Text() {
        this.texto = new LinkedList();
    }
    
    /**
     * Construtor com parâmetro da classe Text.
     * @param texto Lista encadeada de caracteres
     * @author João Pedro
     * @author Luis Fernando
     */
    public Text(LinkedList <Character> texto) {
        this.texto = texto;
    }
    
    /**
     * Retorna a lista encadeada de caracteres.
     * @return LinkedList
     * @author João Pedro
     * @author Luis Fernando
     */
    public LinkedList<Character> getTexto() {
        return texto;
    }
    
    /**
     * Atribui uma lista encadeada de caracteres ao objeto Text.
     * @param texto Lista encadeada de caracteres
     * @author João Pedro
     * @author Luis Fernando
     */
    public void setTexto(LinkedList<Character> texto) {
        this.texto = texto;
    }
    
    /**
     * Retorna uma string referente ao texto.
     * @return String
     * @author João Pedro
     * @author Luis Fernando
     */
    @Override
    public String toString() {
        String retorno = new String();
        for(Character i : this.getTexto())
            retorno += i;
        return retorno;
    }
    
}
