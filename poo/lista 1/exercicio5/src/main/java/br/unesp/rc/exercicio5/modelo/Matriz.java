/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.unesp.rc.exercicio5.modelo;

import java.util.Random;

/**
 *
 * @author ottoj
 */
public class Matriz {
    private int[][] numeros;
    private static final int MAIOR_NUMERO_ALEATORIO = 100;

    public Matriz(int tam) {
        this.numeros= new int[tam][tam];
        preencherMatriz();
    }
    
    public void preencherMatriz(){
        Random rand = new Random();
        for (int i = 0; i < numeros.length; i++) {
            for (int j = 0; j < numeros[i].length; j++) {
                numeros[i][j] = rand.nextInt(MAIOR_NUMERO_ALEATORIO + 1);
            }
        }
    }
    
    public int getSomaElementosDiagonalSecundaria(){
        int soma=0;
        for(int i=numeros.length-1; i>=0; i--){
            soma += numeros[i][numeros.length - 1 - i];
        }
        return soma;
    }
    
    public void visualizarTriangularSuperior(){
        for (int i = 0; i < numeros.length; i++) {
            for(int j=0; j < numeros[i].length; j++){
                if (j >= i) {
                    System.out.printf("%3d ", numeros[i][j]);
                } else {
                    System.out.print("  0 ");
                }
            }
            System.out.println("");
        }
    }
    
    public int getMultiplicaoElementosDiagonalPrincipal(){
        int produto=1;
        for(int i=0; i<numeros.length; i++){
            produto*=numeros[i][i];
        }
        return produto;
    }
    
     public void visualizarMatriz() {
        for (int i = 0; i < numeros.length; i++) {
            for (int j = 0; j < numeros[i].length; j++) {
                System.out.printf("[%2d] ", numeros[i][j]);
            }
            System.out.println("");
        }
    }
}
