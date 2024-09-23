package br.unesp.rc.exercicio02.modelo;

/**
 *
 * @author aluno
 */
public class Curso {
    private String nome;
    private int codigo;
    private int numeroVagas;
    private int numeroCandidatosMasculino;
    private int numeroCandidatosFeminino;

    public Curso() {
    }

    public Curso(String nome, int código, int numeroVagas, int numeroCandidatosMasculino, int numeroCandidatosFeminino) {
        this.nome = nome;
        this.codigo = código;
        this.numeroVagas = numeroVagas;
        this.numeroCandidatosMasculino = numeroCandidatosMasculino;
        this.numeroCandidatosFeminino = numeroCandidatosFeminino;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getCodigo() {
        return codigo;
    }

    public void setCodigo(int código) {
        this.codigo = código;
    }

    public int getNumeroVagas() {
        return numeroVagas;
    }

    public void setNumeroVagas(int numeroVagas) {
        this.numeroVagas = numeroVagas;
    }

    public int getNumeroCandidatosMasculino() {
        return numeroCandidatosMasculino;
    }

    public void setNumeroCandidatosMasculino(int numeroCandidatosMasculino) {
        this.numeroCandidatosMasculino = numeroCandidatosMasculino;
    }

    public int getNumeroCandidatosFeminino() {
        return numeroCandidatosFeminino;
    }

    public void setNumeroCandidatosFeminino(int numeroCandidatosFeminino) {
        this.numeroCandidatosFeminino = numeroCandidatosFeminino;
    }

    @Override
    public String toString() {
        return "\nCurso:\t" + nome + "\n\tCod: " + codigo + "\n\tNumero de Vagas: " + numeroVagas + "\n\tCandidatos Masculinos: " + numeroCandidatosMasculino + "\n\tCandidatas Femininas: "+ numeroCandidatosFeminino;
    }
    
    public float calcularRelacaoCandidatoVaga(){
        return (float) (numeroCandidatosFeminino + numeroCandidatosMasculino) / numeroVagas;
    }
    
    public float calcularPorcentagemCandidatosFeminino(){
        int total=numeroCandidatosFeminino+numeroCandidatosMasculino;
        float porcentagem=0;
        porcentagem = (float) numeroCandidatosFeminino / total * 100;
        return porcentagem;
    }
    
    public int calcularTotalCandidatos(){
        return numeroCandidatosFeminino+numeroCandidatosMasculino;
    }
}
