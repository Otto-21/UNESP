/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.unesp.rc.exercicio6;

import br.unesp.rc.exercicio6.modelo.Matriz;
import br.unesp.rc.exercicio6.modelo.Vetor;
import java.util.Scanner;

/**
 *
 * @author ottoj
 */
public class Demo {
    private static Scanner scanner = new Scanner(System.in);
    public static void main(String[] args) {
        Matriz matriz;
        int ordemMatriz;

        System.out.println("---");
        System.out.println("GERENCIADOR DE MATRIZ");

        System.out.println("Digite a ordem da matriz:");
        ordemMatriz = lerInt();

        matriz = new Matriz(ordemMatriz);

        System.out.println("---");

        System.out.println("Matriz gerada...............:");
        matriz.visualizarMatriz();
        
        Vetor v1 = new Vetor(ordemMatriz);
        v1.setLista(matriz.getMaiorElementoLinhas());
        System.out.println("Maior elemento de cada linha: " + v1);

        Vetor v2 = new Vetor(ordemMatriz);
        v2.setLista(matriz.getMenorElementoColunas());
        System.out.println("Menor elemento de cada linha: " + v2);

        System.out.println("---");
    }
    public static int lerInt() { 
        int numero = scanner.nextInt();
        scanner.nextLine(); // bug: https://stackoverflow.com/questions/13102045/scanner-is-skipping-nextline-after-using-next-or-nextfoo
        return numero;
    }
}
