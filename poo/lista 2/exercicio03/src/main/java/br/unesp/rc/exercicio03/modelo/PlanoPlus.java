/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.unesp.rc.exercicio03.modelo;

import java.util.ArrayList;
import java.util.Date;
import java.util.List;

/**
 *
 * @author ottoj
 */
public class PlanoPlus extends PlanoNormal{
    private static int NUMERO_MAXIMO_DEPENDENTES = 3;

    private List<Socio> dependentes = new ArrayList<>();
    
    @Override
    public String getNome() {
        return "Plus";
    }

    @Override
    public Date getDataCriacao() {
        return new Date();
    }

    @Override
    public double getValorMensal() {
        return super.getValorMensal() + 200;
    }

    public List<Socio> getDependentes() {
        return dependentes;
    }
    
    public boolean adicionarDependente(Socio dependente) {
        if (dependentes.size() < NUMERO_MAXIMO_DEPENDENTES) {
            return dependentes.add(dependente);
        }
        return false;
    }
}
