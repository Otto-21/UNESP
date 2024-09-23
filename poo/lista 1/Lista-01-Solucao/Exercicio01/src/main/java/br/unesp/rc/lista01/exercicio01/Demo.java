package br.unesp.rc.lista01.exercicio01;

import br.unesp.rc.lista01.exercicio01.modelo.Funcionario;
import br.unesp.rc.lista01.utilitario.Teclado;

/**
 *
 * @author Prof. Dr. Frank J. Affonso
 */
public class Demo {

    public static void main(String[] args) {
        Funcionario funcionario = new Funcionario();

        System.out.println("");
        System.out.println("CALCULADORA DE IMPOSTO");
        System.out.println("");

        System.out.println("Digite o nome do funcionário:");
        funcionario.setNome(Teclado.lerString());
        System.out.println("Digite o CPF do funcionário:");
        funcionario.setCpf(Teclado.lerString());
        System.out.println("Digite o salário do funcionário:");
        funcionario.setSalario(Teclado.lerDouble());

        double imposto = funcionario.calcularIR(funcionario);

        System.out.println(String.format("Nome do funcionário: %s", funcionario.getNome()));
        System.out.println(String.format("CPF do funcionário.: %s", funcionario.getCpf()));
        System.out.println(String.format("Salário bruto......: R$ %.2f", funcionario.getSalario()));
        System.out.println(String.format("Imposto retido.....: R$ %.2f", imposto));
        System.out.println(String.format("Salário líquido....: R$ %.2f", funcionario.getSalario() - imposto));
    }

}
