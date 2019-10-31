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
public class Usuario implements IElemento {
    private String nome;

    public Usuario() {
        this.nome = new String();
    }

    public Usuario(String nome) {
        this.nome = nome;
    }
    
    @Override
    public boolean equals(IElemento elem) throws IllegalArgumentException {
        if(elem instanceof Usuario){
            return this.nome.equals(((Usuario) elem).getNome());
        }
        throw new IllegalArgumentException("Tipo Invalido");
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    @Override
    public String toString() {
        return this.nome;
    }
    
    
    
    
    
}
