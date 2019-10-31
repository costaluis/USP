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
public class Usuario {
    private String nome;
    private Endereco endereco;
    private Data data_nasc;
    private String num_usp;
    private int temp_emp;
    private Midia midia_emp;

    public Usuario() {
        nome = null;
        endereco = null;
        data_nasc = null;
        num_usp = null;
        temp_emp = 0;
        midia_emp = null;
    }
    
    public void setUsuario() throws IllegalArgumentException, NullPointerException{
        Scanner tec = new Scanner(System.in);
        
        System.out.print("Insira o nome do usuario: ");
        String nome = tec.nextLine();
        if(nome.isEmpty()){
            throw new NullPointerException("Entrada Invalida!");
        }
        this.nome = nome;
        
        System.out.print("Insira o numero USP: ");
        String num_usp = tec.nextLine();
        if(num_usp.isEmpty()){
            throw new NullPointerException("Entrada Invalida!");
        }
        if(num_usp.length() != 7){
            throw new IllegalArgumentException("Numero USP Invalido!");
        }
        this.num_usp = num_usp;
        
 
        try{
            this.endereco = new Endereco();
            System.out.println("---Endereço---");
            System.out.print("Rua: ");
            this.endereco.setRua(tec.nextLine());
            
            System.out.print("Numero: ");
            this.endereco.setNum(Integer.parseInt(tec.nextLine()));
            
            System.out.print("Cidade: ");
            this.endereco.setCidade(tec.nextLine());
            
            System.out.print("Insira a data da nascimento (dd/mm/aaaa): ");
            String nasc = tec.nextLine();
            if(nasc.isEmpty()){
                throw new NullPointerException("Entrada Invalida!");
            }
            String[] dma = nasc.split("/");
            if(dma.length != 3){
                throw new IllegalArgumentException("Data Invalida!");
            }
            
            this.data_nasc = new Data();
            this.data_nasc.setDia(Integer.parseInt(dma[0]));
            this.data_nasc.setMes(Integer.parseInt(dma[1]));
            this.data_nasc.setAno(Integer.parseInt(dma[2]));
            
        }
        catch(IllegalArgumentException | InvalidDateException | NullPointerException e){
            System.err.println(e);
            System.exit(1);
        }
      
    }

    public void setMidia_emp(Midia midia_emp) {
        this.midia_emp = midia_emp;
    }

    
    
    public String getNome() {
        return nome;
    }

    public Endereco getEndereco() {
        return endereco;
    }

    public Data getData_nasc() {
        return data_nasc;
    }

    public String getNum_usp() {
        return num_usp;
    }

    public int getTemp_emp() {
        return temp_emp;
    }

    public Midia getMidia_emp() {
        return midia_emp;
    }
    
    
    
    public boolean equal(Usuario user){
        if(!(user.getNome().equals(this.nome))){
            return false;
        }
        if(!(user.getEndereco().getCidade().equals(this.endereco.getCidade()))){
            return false;
        }
        if(!(user.getEndereco().getRua().equals(this.endereco.getRua()))){
            return false;
        }
        if(!(user.getEndereco().getNum() == this.endereco.getNum())){
            return false;
        }
        if(!(user.getData_nasc().getDia() == this.data_nasc.getDia())){
            return false;
        }
        if(!(user.getData_nasc().getMes() == this.data_nasc.getMes())){
            return false;
        }
        if(!(user.getData_nasc().getAno() == this.data_nasc.getAno())){
            return false;
        }
        if(!(user.getNum_usp().equals(this.num_usp))){
            return false;
        }
        return true;
    }
    
}
