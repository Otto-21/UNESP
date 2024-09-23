/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.unesp.rc.exercicio01;

import br.unesp.rc.exercicio01.modelo.Pessoa;
import br.unesp.rc.exercicio01.repositorio.RepositorioPessoa;

/**
 *
 * @author ottoj
 */
public class Exercicio01 {
    public static void main(String[] args) {
        Pessoa p1=new Pessoa("Otto Jacometo","44903404862",2400);
        Pessoa p2=new Pessoa("José Emanuel da Silva","11111111111",1400);
        Pessoa p3=new Pessoa("Claudia Lopes","22222222222",1750);
        Pessoa p4=new Pessoa("Rafaela dos Santos","33333333333",5000);
        Pessoa p5=new Pessoa("Daniel de Carvalho","44444444444",3200);
        
        RepositorioPessoa repositorio= new RepositorioPessoa();
        repositorio.adicionar(p1);
        repositorio.adicionar(p2);
        repositorio.adicionar(p3);
        repositorio.adicionar(p4);
        repositorio.adicionar(p5);
        
        repositorio.imprime();
    }
}
