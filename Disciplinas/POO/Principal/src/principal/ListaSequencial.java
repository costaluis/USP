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
public class ListaSequencial extends Lista {
    private IElemento[] data;

    public ListaSequencial() {
        this.data = new IElemento[100];
        for(int i=0; i<100; i++){
            data[i] = null;
        }
    }
    
    public ListaSequencial(int tamanho_max){
        this.data = new IElemento[tamanho_max];
        for(int i=0; i<tamanho_max; i++){
            data[i] = null;
        }
    }

    @Override
    public void inserir(IElemento elem) {
        for(int i=0; i<data.length; i++){
            if(data[i] == null){
                data[i] = elem;
                tamanho++;
                return;
            }
        }
    }

    @Override
    public void imprimir() {
        for (IElemento data1 : this.data) {
            if(data1 != null){
                System.out.print(data1 + " ");
            }
        }
        System.out.println();
    }

    @Override
    public void remover(IElemento elem) {
        for(int i=0; i<data.length; i++){
            if(data[i] != null){
                if(data[i].equals(elem)){
                    for(int j=i;j<data.length-1;j++){
                        data[j] = data[j+1];
                    }
                    return;
                }
            }
        }
    }
    
    
}
