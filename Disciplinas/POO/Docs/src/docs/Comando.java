/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package docs;

/**
 * Representa um comando referente à manipulação do objeto Text.
 * 
 * @author João Pedro
 * @author Luis Fernando
 */
public class Comando {
    private int instrucao;
    private Text operando;
    private int fim;
    
    /**
     * Construtor da classe comando.
     * 
     * @author João Pedro
     * @author Luis Fernando
     */
    public Comando() {
        this.instrucao = 0;
        this.operando = new Text();
        this.fim = -1;
    }
    
    /**
     * Construtor com parâmetros da classe Comando.
     * @param instrucao Índice da instrução
     * @param operando Texto a ser operado
     * @author João Pedro
     * @author Luis Fernando
     */
    public Comando(int instrucao, Text operando) {
        this.instrucao = instrucao;
        this.operando = operando;
    }
    
    /**
     * Retorna o número da instrução.
     * @return int
     * @author João Pedro
     * @author Luis Fernando
     */
    public int getInstrucao() {
        return instrucao;
    }
    
    /**
     * Atribui um número de instrução ao comando.
     * @param instrucao Índice da instrução
     * @author João Pedro
     * @author Luis Fernando
     */
    public void setInstrucao(int instrucao) {
        this.instrucao = instrucao;
    }
    
    /**
     * Retorna a lista encadeada de caracteres referente ao comando.
     * @return Text
     * @author João Pedro
     * @author Luis Fernando
     */
    public Text getOperando() {
        return operando;
    }
    
    /**
     * Atribui uma lista encadeada de caracteres referente a um comando.
     * @param operando Texto a ser operado
     * @author João Pedro
     * @author Luis Fernando
     */
    public void setOperando(Text operando) {
        this.operando = operando;
    }

    /**
     * Retorna o fim de um comando.
     * @return int
     * @author João Pedro
     * @author Luis Fernando
     */
    public int getFim() {
        return fim;
    }

    /**
     * Atribui um novo valor para o fim de um comando.
     * @param fim 
     * @author João Pedro
     * @author Luis Fernando
     */
    public void setFim(int fim) {
        this.fim = fim;
    }
    
    
}
