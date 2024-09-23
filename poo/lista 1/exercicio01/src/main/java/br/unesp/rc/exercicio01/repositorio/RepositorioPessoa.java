/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.unesp.rc.exercicio01.repositorio;

import br.unesp.rc.exercicio01.modelo.Pessoa;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author ottoj
 */
public class RepositorioPessoa {
    private List<Pessoa> pessoas;

    public RepositorioPessoa() {
        pessoas= new ArrayList<>();
    }
    
    public void adicionar(Pessoa pessoa){
        pessoas.add(pessoa);
    }
    
    public void imprime(){
        for(Pessoa p: pessoas){
            System.out.println(p);
            System.out.println("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
        }
    }
}
