package br.unesp.rc.lista01.exercicio06.modelo;

import java.util.Random;

/**
 *
 * @author Prof. Dr. Frank J. Affonso
 */
public class Matriz {

    private static final int MAIOR_NUMERO_ALEATORIO = 100;

    private int numeros[][];
    private int maiorElementoLinhas[];
    private int menorElementoLinhas[];

    public Matriz(int ordemMatriz) {
        numeros = new int[ordemMatriz][ordemMatriz];
        maiorElementoLinhas = new int[ordemMatriz];
        menorElementoLinhas = new int[ordemMatriz];
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

    public void analisarMatriz() {
        for (int i = 0; i < numeros.length; i++) {
            maiorElementoLinhas[i] = numeros[i][0];
            menorElementoLinhas[i] = numeros[i][0];
            for (int j = 1; j < numeros[i].length; j++) {
                if (numeros[i][j] > maiorElementoLinhas[i]) {
                    maiorElementoLinhas[i] = numeros[i][j];
                }
                if (numeros[i][j] < menorElementoLinhas[i]) {
                    menorElementoLinhas[i] = numeros[i][j];
                }
            }
        }
    }

    public int[] getMaiorElementoLinhas() {
        return maiorElementoLinhas;
    }

    public int[] getMenorElementoLinhas() {
        return menorElementoLinhas;
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
