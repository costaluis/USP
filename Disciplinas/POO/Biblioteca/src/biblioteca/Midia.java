/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package biblioteca;

import java.util.Scanner;

/**
 *
 * @author luis
 */
public class Midia {
    private String titulo;
    private String autor;
    private int ano;
    private String tipo;
    private String editora;
    private Local localizacao;
    private boolean disponivel;
    private static float multa = (float) 0.5;

    public Midia() {
        titulo = null;
        autor = null;
        ano = 0;
        tipo = null;
        editora = null;
        localizacao = null;
        disponivel = true;
    }

    public void setTitulo(String titulo) {
        this.titulo = titulo;
    }

    public void setAutor(String autor) {
        this.autor = autor;
    }

    public void setAno(int ano) throws InvalidDateException {
        if(ano < 0){
            throw new InvalidDateException("Ano invalido");
        }
        this.ano = ano;
    }

    public void setTipo(String tipo) {
        this.tipo = tipo;
    }

    public void setEditora(String editora) {
        this.editora = editora;
    }

    public void setLocalizacao(Local localizacao) {
        this.localizacao = localizacao;
    }
    
    public void setMidia() throws IllegalArgumentException, NullPointerException{
        Scanner tec = new Scanner(System.in);
        
        System.out.print("Insira o titulo da midia: ");
        String titulo = tec.nextLine();
        if(titulo.isEmpty()){
            throw new NullPointerException("Entrada Invalida!");
        }
        this.titulo = titulo;
        
        System.out.print("Insira o autor da midia: ");
        String autor = tec.nextLine();
        if(autor.isEmpty()){
            throw new NullPointerException("Entrada Invalida!");
        }
        this.autor = autor;
    
        System.out.print("Insira o ano de publicacao da midia: ");
        String anoS = tec.nextLine();
        if(anoS.isEmpty()){
            throw new NullPointerException("Entrada Invalida!");
        }
        int ano = Integer.parseInt(anoS);
        if(ano < 0){
            throw new IllegalArgumentException("Ano invalido!");
        }
        this.ano = ano;
        
        System.out.print("Insira o tipo da midia: ");
        String tipo = tec.nextLine();
        if(tipo.isEmpty()){
            throw new NullPointerException("Entrada Invalida!");
        }
        this.tipo = tipo;
        
        System.out.print("Insira a editora da midia: ");
        String editora = tec.nextLine();
        if(editora.isEmpty()){
            throw new NullPointerException("Entrada Invalida!");
        }
        this.editora = editora;
        
        try{
            this.localizacao = new Local();
            
            System.out.print("Insira o andar em que esta a midia: ");
            String andar = tec.nextLine();
            if(andar.isEmpty()){
                throw new NullPointerException("Entrada Invalida!");
            }
            this.localizacao.setAndar(Integer.parseInt(andar));
            
            System.out.print("Insira a secao em que esta a midia: ");
            this.localizacao.setSecao(tec.nextLine());
        }
        catch(IllegalArgumentException | NullPointerException e){
            System.err.println(e);
            System.exit(2);
        }
        
    }

    public void setDisponivel(boolean disponivel) {
        this.disponivel = disponivel;
    }

    public String getTitulo() {
        return titulo;
    }

    public String getAutor() {
        return autor;
    }

    public int getAno() {
        return ano;
    }

    public String getTipo() {
        return tipo;
    }

    public String getEditora() {
        return editora;
    }

    public Local getLocalizacao() {
        return localizacao;
    }

    public boolean isDisponivel() {
        return disponivel;
    }

    public static float getMulta() {
        return multa;
    }
    
    
    
    
    
}
