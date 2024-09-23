package br.unesp.rc.lista01.exercicio05;

import br.unesp.rc.lista01.exercicio05.modelo.Matriz;
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

        System.out.println("---");        

        System.out.println("Matriz gerada...................................:");
        matriz.visualizarMatriz();
        System.out.println(String.format("Soma dos elementos da diagonal secundária.......: %d", matriz.getSomaElementosDiagonalSecundaria()));
        System.out.println(String.format("Mutiplicação dos elementos da diagonal principal: %d", matriz.getMultiplicaoElementosDiagonalPrincipal()));
        System.out.println("Matriz triangular superior......................:");
        matriz.visualizarTriangularSuperior();
        
        System.out.println("---");
    }

}
