/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package biblioteca;

import java.io.IOException;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Scanner;


/**
 *
 * @author luis
 */
public class Biblioteca {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IllegalArgumentException, IOException {
        // TODO code application logic here
        int i;
        LinkedList<Usuario> usuarios = new LinkedList();
        LinkedList<Midia> midias = new LinkedList();
        Scanner tec = new Scanner(System.in);
        while(true){
            System.out.println("--- Escolha um opcao ---");
            System.out.println("1. Inserir usuario.");
            System.out.println("2. Inserir midia.");
            System.out.println("3. Remover usuario.");
            System.out.println("4. Remover midia.");
            System.out.println("5. Emprestar midia.");
            System.out.println("6. Encerrar programa.");
            i = tec.nextInt();
            Runtime.getRuntime().exec("clear");
            switch(i){
                case 1:
                    Usuario new_user = new Usuario();
                    try{
                        new_user.setUsuario();
                    }
                    catch(IllegalArgumentException | NullPointerException e){
                        System.err.println(e);
                        System.err.println("Erro ao inserir usuario");
                        break;
                    }
                    if(Biblioteca.user_exist(usuarios, new_user)){
                        throw new IllegalArgumentException("Usuario ja existente!");
                    }
                    usuarios.add(new_user);
                    System.out.println("Usuario Inserido!");
                    break;
                case 2:
                    Midia new_midia = new Midia();
                    try{
                        new_midia.setMidia();
                    }
                    catch(IllegalArgumentException | NullPointerException e){
                        System.err.println(e);
                        System.err.println("Erro ao inserir midia");
                        break;
                    }
                    midias.add(new_midia);
                    System.out.println("Midia Inserida");
                    break;
                case 3:
                    int indice;
                    try{
                        indice = Biblioteca.busca_user(usuarios);
                    }
                    catch(IllegalArgumentException | NullPointerException e){
                        System.err.println(e);
                        System.err.println("Erro ao remover usuario!");
                        break;
                    }                   
                    if(indice == -1){
                        throw new NullPointerException("Usuario nao encontrado!");
                    }
                    usuarios.remove(indice);
                    break;
                case 4:
                    int ind;
                    try{
                        ind = Biblioteca.busca_midia(midias);
                    }
                    catch(IllegalArgumentException | NullPointerException e){
                        System.err.println(e);
                        System.err.println("Erro ao remover midia!");
                        break;
                    }                   
                    midias.remove(ind);            
                    break; 
                case 5:
                    int indi;
                    int indi_1;
                    try{
                        indi = Biblioteca.busca_user(usuarios);
                    }
                    catch(IllegalArgumentException | NullPointerException e){
                        System.err.println(e);
                        System.err.println("Erro ao buscar usuario!");
                        break;
                    } 

                    if(usuarios.get(indi).getTemp_emp() > 7){
                        System.out.println("Usuario com atraso.");
                        float multa = Midia.getMulta() * (usuarios.get(indi).getTemp_emp()-7);
                        System.out.println("Pagar multa de R$" + multa);
                        break;
                    }
                    if(indi == -1){
                        throw new NullPointerException("Usuario nao encontrado!");
                    }
                    try{
                        indi_1 = Biblioteca.busca_midia(midias);
                    }
                    catch(IllegalArgumentException | NullPointerException e){
                        System.err.println(e);
                        System.err.println("Erro ao buscar midia!");
                        break;
                    } 
                    
                    if(!midias.get(indi_1).isDisponivel()){
                        System.out.println("Midia ja emprestada!");
                        break;
                    }
                    usuarios.get(indi).setMidia_emp(midias.get(indi_1));
                    midias.get(indi_1).setDisponivel(false);
                    break; 
                case 6:
                    System.out.println("Programa Encerrado!");
                    System.exit(0);
                    break;
                default:
                    System.out.println("Entrada Invalida!");
                    break;
            }
        }
        
        
    }
    
    public static boolean user_exist(LinkedList usuarios, Usuario user){
        for(int i=0; i<usuarios.size(); i++){
            if(usuarios.get(i).equals(user)){
                return true;
            }
        }
        return false;
    }
    
    public static int busca_user(LinkedList <Usuario> usuarios) throws NullPointerException{
        Scanner tec = new Scanner(System.in);
        System.out.print("Insira o numero USP do usuario: ");
        String num_usp = tec.nextLine();
        if(num_usp.isEmpty()){
            throw new NullPointerException("Entrada Invalida!");
        }
        for(int i=0; i<usuarios.size();i++){
            if(usuarios.get(i).getNum_usp().equals(num_usp)){
                return i;
            }
        }
        return -1;
    }
    
    public static int busca_midia(LinkedList <Midia> midias) throws NullPointerException, IllegalArgumentException{
        Scanner tec = new Scanner(System.in);
        ArrayList indices = new ArrayList();
        System.out.println("Insira o titulo/autor da midia: ");
        String ent = tec.nextLine();
        if(ent.isEmpty()){
            throw new NullPointerException("Entrada Invalida!");
        }
        for(int i=0; i<midias.size();i++){
            if(midias.get(i).getTitulo().startsWith(ent) || midias.get(i).getAutor().startsWith(ent)){
                indices.add(i);
            }
        }
        
        System.out.println("Informe a midia requerida: ");
        
        for(int j=0; j<indices.size();j++){
            System.out.println(j + ". " + midias.get((int)indices.get(j)).getTitulo() + " - " + midias.get((int)indices.get(j)).getAutor());
        }
        
        int req = tec.nextInt();
        
        if(req<0 || req>indices.size()){
            throw new IllegalArgumentException("Entrada Invalida!");
        }
        
        return (int) indices.get(req);
    }
}
