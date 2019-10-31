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
public class ListaEncadeada extends Lista {
    private No topo;

    public ListaEncadeada() {
        this.topo = null;
    }
    
    @Override
    public void inserir(IElemento elem){
        No tmp = new No();
        No aux = this.topo;
        tmp.setElemento(elem);
        tmp.setNext(null);
        if(aux == null){
            this.topo = tmp;
        }
        else{
            while(aux.getNext() != null){
                aux = aux.getNext();
            }
            aux.setNext(tmp);
        }    
        this.tamanho++;
    }
    
    @Override
    public void remover(IElemento elem) {
        No tmp = this.topo;
        No aux;
        if(tmp == null){
            return;
        }
        if(tmp.getElemento().equals(elem)){
            this.topo = tmp.getNext();
            this.tamanho--;
            return;
        }
        while(tmp.getNext() != null){
            if(tmp.getNext().getElemento().equals(elem)){
                aux = tmp.getNext().getNext();
                tmp.setNext(aux);
                this.tamanho--;
                return;
            }
            tmp = tmp.getNext();
        }
        return;
    }
    
    @Override
    public void imprimir(){
        No tmp = this.topo;
        while(tmp != null){
            System.out.print(tmp.getElemento() + " ");
            tmp = tmp.getNext();
        }
        System.out.println();
    }
    
}
