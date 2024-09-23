package br.unesp.rc.lista01.exercicio06;

import br.unesp.rc.lista01.exercicio06.modelo.Matriz;
import br.unesp.rc.lista01.exercicio06.modelo.Vetor;
import br.unesp.rc.lista01.utilitario.Teclado;

/**
 *
 * @author Prof. Dr. Frank J. Affonso
 */
public class Demo {

    public static void main(String[] args) {
        Matriz matriz;
        int ordemMatriz;

        System.out.println("---");
        System.out.println("GERENCIADOR DE MATRIZ");

        System.out.println("Digite a ordem da matriz:");
        ordemMatriz = Teclado.lerInt();

        matriz = new Matriz(ordemMatriz);
        matriz.analisarMatriz();

        System.out.println("---");

        System.out.println("Matriz gerada...............:");
        matriz.visualizarMatriz();
        
        Vetor v1 = new Vetor(ordemMatriz);
        v1.setLista(matriz.getMaiorElementoLinhas());
        System.out.println("Maior elemento de cada linha: " + v1);

        Vetor v2 = new Vetor(ordemMatriz);
        v2.setLista(matriz.getMenorElementoLinhas());
        System.out.println("Menor elemento de cada linha: " + v2);

        System.out.println("---");
    }

}
