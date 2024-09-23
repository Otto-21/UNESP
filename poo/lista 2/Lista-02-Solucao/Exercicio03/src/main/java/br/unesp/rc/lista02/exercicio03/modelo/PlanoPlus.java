package br.unesp.rc.lista02.exercicio03.modelo;

import java.util.ArrayList;
import java.util.Date;
import java.util.List;

/**
 *
 * @author Prof. Dr. Frank J. Affonso
 */
public class PlanoPlus extends PlanoNormal {

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
