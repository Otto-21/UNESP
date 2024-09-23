package br.unesp.rc.lista01.exercicio03;

import br.unesp.rc.lista01.exercicio03.modelo.Vetor;
import br.unesp.rc.lista01.utilitario.Teclado;

/**
 *
 * @author Prof. Dr. Frank J. Affonso
 */
public class Demo {

    public static void main(String[] args) {
        Vetor vetor = new Vetor();
        int quantidadeNumeros;

        System.out.println("GERENCIADOR DE NÚMEROS");
        System.out.println("Digite a quantidade de números que serão gerados:");
        quantidadeNumeros = Teclado.lerInt();
        
        System.out.println("---");        
        vetor.geraElementos(quantidadeNumeros);
        
        System.out.println("Números gerados.....................: " + vetor);
        System.out.println("Soma dos números gerados............: " + vetor.soma());
        
        Vetor vetor2 = new Vetor();
        vetor2.setNumeros(vetor.ordemCrescente());
        System.out.println("Números gerados em ordem crescente..: " + vetor2);
        
        Vetor vetor3 = new Vetor();
        vetor3.setNumeros(vetor.ordemDecrescente());
        System.out.println("Números gerados em ordem decrescente: " + vetor3);
        
        System.out.println("Maior número gerado.................: " + vetor.maiorElemento());
        
        System.out.println("---");
    }

}
