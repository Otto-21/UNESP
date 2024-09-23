package br.unesp.rc.lista02.exercicio01.modelo;

/**
 *
 * @author Prof. Dr. Frank J. Affonso
 */
public abstract class Veiculo {

    private String nome;
    private String modelo;
    private int ano;

    public Veiculo() {
    }

    public Veiculo(String nome, String modelo, int ano) {
        this.nome = nome;
        this.modelo = modelo;
        this.ano = ano;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getModelo() {
        return modelo;
    }

    public void setModelo(String modelo) {
        this.modelo = modelo;
    }

    public int getAno() {
        return ano;
    }

    public void setAno(int ano) {
        this.ano = ano;
    }

    @Override
    public String toString() {
        return "Veiculo{" + "nome=" + nome + ", modelo=" + modelo + ", ano=" + ano + '}';
    }

    public abstract void trocarPneu();

    public abstract void trocarOleo();

    public abstract void limparMotor();
}
