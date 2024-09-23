package br.unesp.rc.lista02.exercicio01;

import br.unesp.rc.lista02.exercicio01.modelo.Automovel;
import br.unesp.rc.lista02.exercicio01.modelo.Caminhao;
import br.unesp.rc.lista02.exercicio01.modelo.OrdemServico;
import br.unesp.rc.lista02.exercicio01.modelo.Servico;
import br.unesp.rc.lista02.exercicio01.repositorio.Oficina;
import br.unesp.rc.lista02.exercicio01.modelo.Veiculo;

/**
 *
 * @author Prof. Dr. Frank J. Affonso
 */
public class Demo {

    public static void main(String[] args) {
        Oficina oficina = new Oficina();

        System.out.println("---");
        System.out.println("ATENDIMENTOS");
        System.out.println("---");

        Veiculo veiculo1 = new Automovel(5, "Celta", "LT", 2012);
        Servico servico1 = new Servico(true, false, false);
        OrdemServico ordemServico1 = new OrdemServico(1, veiculo1, servico1);
        oficina.registarManutencao(ordemServico1);

        Veiculo veiculo2 = new Automovel(5, "Prisma", "LTZ", 2015);
        Servico servico2 = new Servico(true, false, true);
        OrdemServico ordemServico2 = new OrdemServico(2, veiculo2, servico2);
        oficina.registarManutencao(ordemServico2);

        Veiculo veiculo3 = new Caminhao(6, "Carreta de três eixos", "Simples", 2020);
        Servico servico3 = new Servico(true, false, false);
        OrdemServico ordemServico3 = new OrdemServico(3, veiculo3, servico3);
        oficina.registarManutencao(ordemServico3);

        Veiculo veiculo4 = new Caminhao(6, "Carreta de dois eixos", "Luxo", 2022);
        Servico servico4 = new Servico(true, false, true);
        OrdemServico ordemServico4 = new OrdemServico(4, veiculo4, servico4);
        oficina.registarManutencao(ordemServico4);

        System.out.println("---");
        oficina.imprimeFila();
        System.out.println("---");

        System.out.println("\n");

        System.out.println("---");
        System.out.println("INICIANDO OS ATENDIMENTOS");
        System.out.println("---");

        while (!oficina.filaVazia()) {
            OrdemServico os = oficina.proximo();
            
            if (os.getServico().isTrocaDePneu()) {
                os.getVeiculo().trocarPneu();
            }

            if (os.getServico().isTrocaDeOleo()) {
                os.getVeiculo().trocarOleo();
            }

            if (os.getServico().isLimpezaDoMotor()) {
                os.getVeiculo().limparMotor();
            }
        }
    }
}
