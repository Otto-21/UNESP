/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.unesp.rc.exercicio6.modelo;

import java.util.Random;

/**
 *
 * @author ottoj
 */
public class Matriz {
    private int[][] numeros;
    private int[] vMaiorLinhas, vMenorColunas;
    private static final int MAIOR_NUMERO_ALEATORIO = 100;

    public Matriz(int tam) {
        this.numeros= new int[tam][tam];
        this.vMaiorLinhas= new int[tam];
        this.vMenorColunas= new int[tam];
        preencherMatriz();
        preencherVetores();
    }
    
    public void preencherMatriz(){
        Random rand = new Random();
        for (int i = 0; i < numeros.length; i++) {
            for (int j = 0; j < numeros[i].length; j++) {
                numeros[i][j] = rand.nextInt(MAIOR_NUMERO_ALEATORIO + 1);
            }
        }
    }
    
    public void preencherVetores(){
        for(int i=0; i<numeros.length; i++){
            for(int j=0; j<numeros.length; j++){
                if(j==0)
                    vMaiorLinhas[i]=numeros[i][j];
                else
                    if(vMaiorLinhas[i]<numeros[i][j])
                        vMaiorLinhas[i]=numeros[i][j];
                if(i==0)
                    vMenorColunas[j]=numeros[i][j];
                else
                    if(vMenorColunas[j]>numeros[i][j])
                        vMenorColunas[j]=numeros[i][j];
            }
        }
    }
    
    public int[] getMaiorElementoLinhas() {
        return vMaiorLinhas;
    }

    public int[] getMenorElementoColunas() {
        return vMenorColunas;
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
