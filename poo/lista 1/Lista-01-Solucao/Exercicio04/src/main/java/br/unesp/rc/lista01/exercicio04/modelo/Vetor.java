package br.unesp.rc.lista01.exercicio04.modelo;

/**
 *
 * @author Prof. Dr. Frank J. Affonso
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

    public int[] compactarVetor() {
        int size = 0;
        for (int i = 0; i < this.array.length; i++) {
            if (array[i] > 0) {
                size++;
            }
        }

        int[] vetorSecundario = new int[size];
        for (int i = 0; i < size; i++) {
            if (array[i] > 0) {
                vetorSecundario[i] = array[i];
            }
        }

        return vetorSecundario;
    }

}
