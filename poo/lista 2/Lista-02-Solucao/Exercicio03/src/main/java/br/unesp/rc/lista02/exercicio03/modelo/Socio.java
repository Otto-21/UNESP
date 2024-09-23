package br.unesp.rc.lista02.exercicio03.modelo;

/**
 *
 * @author Prof. Dr. Frank J. Affonso
 */
public class Socio {

    private String nome;
    private String cpf;
    private Plano plano;

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getCpf() {
        return cpf;
    }

    public void setCpf(String cpf) {
        this.cpf = cpf;
    }

    public Plano getPlano() {
        return plano;
    }

    public void setPlano(Plano plano) {
        this.plano = plano;
    }

}
