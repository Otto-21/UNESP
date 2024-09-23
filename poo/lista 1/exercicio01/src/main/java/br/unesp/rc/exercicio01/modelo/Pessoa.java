/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.unesp.rc.exercicio01.modelo;

/**
 *
 * @author ottoj
 */
public class Pessoa {
    private String nome;
    private String cpf;
    private double salario;

    public Pessoa() {
    }

    public Pessoa(String nome, String cpf, double salario) {
        this.nome = nome;
        this.cpf = cpf;
        this.salario = salario;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getCpf() {
        return cpf;
    }

    public void setCpf(String cpf) {
        this.cpf = cpf;
    }

    public double getSalario() {
        return salario;
    }

    public void setSalario(double salario) {
        this.salario = salario;
    }    
    
    public static String formataCPF(String cpf){
        if (cpf.length() == 11) {
            return cpf.substring(0, 3) + "." + cpf.substring(3, 6) + "." + cpf.substring(6, 9) + "-"
                    + cpf.substring(9, 11);
        } else {
            return cpf;
        }
    }
    
    public double calculaImposto(){
        double imposto=0;
        if(salario<=1500){
            imposto=0;
        }
        else if(salario<=2000){
            imposto= 0.075;
        }
        else if(salario<=3000){
            imposto=0.15;
        }
        else if(salario<=4000){
            imposto=0.225;
        }
        else
            imposto=0.275;
        return salario*imposto;
    }

    @Override
    public String toString() {
        return "\nNome:\t\t\t"+nome+"\nCPF:\t\t\t"+formataCPF(cpf)+"\nSalario Bruto:\t\tR$: "+String.format("%.2f",salario)+
                "\nImposto:\t\tR$: "+String.format("%.2f",calculaImposto())+"\nSalario Liquido:\tR$: "+
                String.format("%.2f",salario-calculaImposto());
    }

}
