/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.unesp.rc.exercicio01.repositorio;

import br.unesp.rc.exercicio01.modelo.OrdemServico;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author ottoj
 */
public class Oficina {
    List<OrdemServico> fila = new ArrayList<>();
    
    public void registarManutencao(OrdemServico os) {
        fila.add(os);
    }

    public OrdemServico proximo() {
        return fila.remove(0);
    }

    public boolean filaVazia() {
        return fila.isEmpty();
    }

    public void imprimeFila() {
        for (OrdemServico os : fila) {
            System.out.println(os);
            System.out.println("\n");
        }
    }
}
