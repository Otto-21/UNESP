package br.unesp.rc.lista01.exercicio05.modelo;

import java.util.Random;

/**
 *
 * @author Prof. Dr. Frank J. Affonso
 */
public class Matriz {

    private static final int MAIOR_NUMERO_ALEATORIO = 100;

    private int numeros[][];

    public Matriz(int ordemMatriz) {
        numeros = new int[ordemMatriz][ordemMatriz];
        preencherMatriz();
    }

    private void preencherMatriz() {
        Random rand = new Random();
        for (int i = 0; i < numeros.length; i++) {
            for (int j = 0; j < numeros[i].length; j++) {
                numeros[i][j] = rand.nextInt(MAIOR_NUMERO_ALEATORIO + 1);
            }
        }
    }

    public int getSomaElementosDiagonalSecundaria() {
        int somaDiagonalSecundaria = 0;
        for (int i = numeros.length - 1; i >= 0; i--) {
            somaDiagonalSecundaria += numeros[i][numeros.length - 1 - i];
        }
        return somaDiagonalSecundaria;
    }

    public void visualizarTriangularSuperior() {
        for (int i = 0; i < numeros.length; i++) {
            for (int j = 0; j < numeros[i].length; j++) {
                if (j >= i) {
                    System.out.printf("%3d ", numeros[i][j]);
                } else {
                    System.out.print("  0 ");
                }
            }
            System.out.println("");
        }
    }

    public int getMultiplicaoElementosDiagonalPrincipal() {
        int multiplicaoDiagonalPrincipal = 1;
        for (int i = 0; i < numeros.length; i++) {
            multiplicaoDiagonalPrincipal *= numeros[i][i];
        }
        return multiplicaoDiagonalPrincipal;
    }

    public void visualizarMatriz() {
        for (int i = 0; i < numeros.length; i++) {
            for (int j = 0; j < numeros[i].length; j++) {
                System.out.printf("%3d ", numeros[i][j]);
            }
            System.out.println("");
        }
    }

}
