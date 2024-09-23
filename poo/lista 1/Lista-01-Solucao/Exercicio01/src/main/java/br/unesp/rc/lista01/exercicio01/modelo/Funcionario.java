package br.unesp.rc.lista01.exercicio01.modelo;

/**
 *
 * @author Prof. Dr. Frank J. Affonso
 */
public class Funcionario {

    private String nome;
    private String cpf;
    private double salario;

    public Funcionario() {
    }

    public Funcionario(String nome, String cpf, double salario) {
        this.nome = nome;
        this.cpf = cpf;
        this.salario = salario;
    }

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

    public double getSalario() {
        return salario;
    }

    public void setSalario(double salario) {
        this.salario = salario;
    }

    @Override
    public String toString() {
        return "Funcionario{" + "nome=" + nome + ", cpf=" + cpf + ", salario=" + salario + '}';
    }

    public double calcularIR(Funcionario funcionario) {
        double aliquota = 0;
        if (funcionario.getSalario() > 1500) {
            if (funcionario.getSalario() <= 2000) {
                aliquota = 0.075;
            } else if (funcionario.getSalario() <= 3000) {
                aliquota = 0.15;
            } else if (funcionario.getSalario() <= 4000) {
                aliquota = 0.225;
            } else {
                aliquota = 0.275;
            }
        }
        return funcionario.getSalario() * aliquota;
    }
}
