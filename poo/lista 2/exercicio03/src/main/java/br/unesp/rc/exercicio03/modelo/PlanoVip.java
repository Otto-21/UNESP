/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.unesp.rc.exercicio03.modelo;

import java.util.Date;

/**
 *
 * @author ottoj
 */
public class PlanoVip extends PlanoNormal{
    private Socio amigo;
    
    @Override
    public String getNome() {
        return "Vip";
    }

    @Override
    public Date getDataCriacao() {
        return new Date();
    }

    @Override
    public double getValorMensal() {
        return super.getValorMensal() + 100;
    }

    public Socio getAmigo() {
        return amigo;
    }

    public void setAmigo(Socio amigo) {
        this.amigo = amigo;
    }
    
}
