/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.unesp.rc.exercicio6.modelo;

/**
 *
 * @author ottoj
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
