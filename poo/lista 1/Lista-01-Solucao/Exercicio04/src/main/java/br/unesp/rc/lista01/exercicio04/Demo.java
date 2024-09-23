package br.unesp.rc.lista01.exercicio04;

import br.unesp.rc.lista01.exercicio04.modelo.Vetor;

/**
 *
 * @author Prof. Dr. Frank J. Affonso
 */
public class Demo {

    public static void main(String[] args) {
        System.out.println("GERENCIADOR DE VETOR");

        int lista[] = {2, 5, 1, 0, 4, -1, 9, 7, 0, 8, 6};
        Vetor vetor = new Vetor(10);
        vetor.setArray(lista);
        
        System.out.println("---");
        System.out.println(print(vetor.getArray()));
        System.out.println("---");        
        int lista2[] = vetor.compactarVetor();
        System.out.println("---");
        System.out.println(print(lista2));
        System.out.println("---");
    }

    private static String print(int v[]) {
        String s = "{";
        int i;

        for (i = 0; i < v.length - 1; i++) {
            s = s + v[i] + ", ";
        }
        s = s + v[i] + "}";

        return s;
    }

}
