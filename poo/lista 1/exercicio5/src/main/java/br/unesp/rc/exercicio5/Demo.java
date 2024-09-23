/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.unesp.rc.exercicio5;
import java.util.Scanner;
import br.unesp.rc.exercicio5.modelo.Matriz;

/**
 *
 * @author ottoj
 */
public class Demo {
    private static Scanner scanner = new Scanner(System.in);
    public static void main(String args[]){
        Matriz matriz;
        int ordemMatriz;

        System.out.println("---");
        System.out.println("GERENCIADOR DE MATRIZ");

        System.out.println("Digite a ordem da matriz:");
        ordemMatriz = lerInt();

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
    
    public static int lerInt() { 
        int numero = scanner.nextInt();
        scanner.nextLine(); // bug: https://stackoverflow.com/questions/13102045/scanner-is-skipping-nextline-after-using-next-or-nextfoo
        return numero;
    }
}
