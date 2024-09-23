package br.unesp.rc.lista01.exercicio03.modelo;

import java.util.Arrays;
import java.util.Collections;
import java.util.Random;

/**
 *
 * @author Prof. Dr. Frank J. Affonso
 */
public class Vetor {

    private static final int MAIOR_NUMERO_ALEATORIO = 100;
    private int numeros[];

    public Vetor() {
    }

    public int[] getNumeros() {
        return numeros;
    }

    public void setNumeros(int[] numeros) {
        this.numeros = numeros;
    }

    public void geraElementos(int tamanhoVetor) {
        numeros = new int[tamanhoVetor];
        Random rand = new Random();
        for (int i = 0; i < tamanhoVetor; i++) {
            this.numeros[i] = rand.nextInt(MAIOR_NUMERO_ALEATORIO + 1);
        }
    }

    public int soma() {
        int somaNumeros = 0;
        for (int i = 0; i < numeros.length; i++) {
            somaNumeros += numeros[i];
        }
        return somaNumeros;
    }

    public int[] ordemCrescente() {
        int copy[] = new int[this.numeros.length];

        copy = Arrays.copyOf(this.numeros, this.numeros.length);
        Arrays.sort(copy);
        
        return copy;
    }

    public int[] ordemDecrescente() {
        Integer copy[] = parserIntToInteger(this.numeros);

        Arrays.sort(copy, Collections.reverseOrder());

        return parserIntegerToInt(copy);
    }

    public int maiorElemento() {
        int maiorNumero = Integer.MIN_VALUE;
        
        for (int i = 0; i < numeros.length; i++) {
            if (numeros[i] > maiorNumero) {
                maiorNumero = numeros[i];
            }
        }
        
        return maiorNumero;
    }

    @Override
    public String toString() {
        String s = "{";
        int i;

        for (i = 0; i < this.numeros.length - 1; i++) {
            s = s + this.numeros[i] + ", ";
        }
        s = s + this.numeros[i] + "}";

        return s;
    }

    private Integer[] parserIntToInteger(int[] copy) {
        Integer array[] = new Integer[copy.length];

        for (int i = 0; i < copy.length; i++) {
            array[i] = copy[i];
        }

        return array;
    }

    private int[] parserIntegerToInt(Integer[] copy) {
        int array[] = new int[copy.length];

        for (int i = 0; i < copy.length; i++) {
            array[i] = copy[i];
        }

        return array;
    }

}
