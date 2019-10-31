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
public class No implements IElemento {
    private IElemento elemento;
    private No next;

    public No() {
        this.elemento = null;
        this.next = null;
    }

    public IElemento getElemento() {
        return elemento;
    }

    public void setElemento(IElemento elemento) {
        this.elemento = elemento;
    } 

    public No getNext() {
        return next;
    }

    public void setNext(No next) {
        this.next = next;
    }
    
    
    
    @Override
    public boolean equals(IElemento elem) {
        return this.elemento.equals(elem);
    }
    
}
