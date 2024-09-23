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
