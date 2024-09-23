package br.unesp.rc.lista01.exercicio06.modelo;

/**
 *
 * @author Prof. Dr. Frank J. Affonso
 */
public class Vetor {

    private int lista[];

    public Vetor(int size) {
        this.lista = new int[size];
    }

    public int[] getLista() {
        return lista;
    }

    public void setLista(int[] lista) {
        this.lista = lista;
    }

    @Override
    public String toString() {
        String s = "{";
        int i;

        for (i = 0; i < this.lista.length - 1; i++) {
            s = s + this.lista[i] + ", ";
        }
        s = s + this.lista[i] + "}";

        return s;
    }

}
