package br.unesp.rc.lista02.exercicio03.modelo;

import java.util.Date;

/**
 *
 * @author Prof. Dr. Frank J. Affonso
 */
public abstract class Plano {

    private Socio proprietario;

    public abstract String getNome();

    public abstract Date getDataCriacao();

    public abstract double getValorMensal();

    public Socio getProprietario() {
        return proprietario;
    }

    public void setProprietario(Socio proprietario) {
        this.proprietario = proprietario;
    }

}
