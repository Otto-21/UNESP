package br.unesp.rc.lista02.exercicio03.modelo;

import java.util.Date;

/**
 *
 * @author Prof. Dr. Frank J. Affonso
 */
public class PlanoVip extends PlanoNormal {

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
