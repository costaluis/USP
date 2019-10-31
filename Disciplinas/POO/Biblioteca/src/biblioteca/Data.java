/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package biblioteca;

/**
 *
 * @author luis
 */
public class Data {
    private int dia;
    private int mes;
    private int ano;

    
    public Data() {
        dia = 0;
        mes = 0;
        ano = 0;
    }

    public void setDia(int dia) throws InvalidDateException {
        if(dia < 1 || dia > 31){
            throw new InvalidDateException("Dia invalido");
        }
        this.dia = dia;
    }

    public void setMes(int mes) throws InvalidDateException {
        if(mes < 1 || mes > 12){
            throw new InvalidDateException("Mes invalido");
        }
        this.mes = mes;
    }

    public void setAno(int ano) throws InvalidDateException {
        if(ano < 0){
            throw new InvalidDateException("Ano invalido");
        }
        this.ano = ano;
    }

    public int getDia() {
        return dia;
    }

    public int getMes() {
        return mes;
    }

    public int getAno() {
        return ano;
    }
    
    
    
    public String toString(){
        return this.dia + "/" + this.mes + "/" + this.ano;
    }
    
}
