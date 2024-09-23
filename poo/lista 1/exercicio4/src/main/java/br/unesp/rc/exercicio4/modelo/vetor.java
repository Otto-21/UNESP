/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.unesp.rc.exercicio4.modelo;

/**
 *
 * @author ottoj
 */
public class Vetor {
    private static final int MAIOR_NUMERO_ALEATORIO = 100;

    private int[] array;

    public Vetor(int size) {
        array = new int[size];
    }

    public int[] getArray() {
        return array;
    }

    public void setArray(int[] array) {
        this.array = array;
    }
    
    public int[] compactarVetor(){
        int size = 0;
        for (int i = 0; i < this.array.length; i++) {
            if (array[i] > 0) {
                size++;
            }
        }
        
        int[] novo= new int[size];
        int cont=0;
        for(int i=0; i<this.array.length; i++){
            if(array[i]>0)
                novo[cont++]=array[i];
        }
        return novo;
    }
    
}

