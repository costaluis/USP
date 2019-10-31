/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package principal;

/**
 *
 * @author luis
 */
public abstract class Lista implements Imprimivel {
    protected int tamanho;

    public Lista() {
        this.tamanho = 0;
    }

    public abstract void inserir(IElemento elem);

    public int getTamanho() {
        return tamanho;
    }

    public void setTamanho(int tamanho) {
        this.tamanho = tamanho;
    }

    @Override
    public abstract void imprimir();
    
    public abstract void remover(IElemento elem);
    
    
}
