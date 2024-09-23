package br.unesp.rc.exercicio03.modelo;

import java.util.Date;

/**
 *
 * @author ottoj
 */
public class PlanoNormal extends Plano{
    
    @Override
    public String getNome() {
        return "Normal";
    }

    @Override
    public Date getDataCriacao() {
        return new Date();
    }

    @Override
    public double getValorMensal() {
        return 50;
    }
    
}
