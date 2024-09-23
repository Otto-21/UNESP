/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.unesp.rc.exercicio01.modelo;

/**
 *
 * @author ottoj
 */
public class Caminhao extends Veiculo{
    private int numeroEixos;

    public Caminhao(int numeroEixos, String nome, String modelo, int ano) {
        super(nome, modelo, ano);
        this.numeroEixos = numeroEixos;
    }

    public int getNumeroEixos() {
        return numeroEixos;
    }

    public void setNumeroEixos(int numeroEixos) {
        this.numeroEixos = numeroEixos;
    }
    
    @Override
    public void trocarPneu() {
        System.out.printf("  Trocando pneu do caminhão %s %s (%d)\n", getNome(), getModelo(), getAno());
    }

    @Override
    public void trocarOleo() {
        System.out.printf("  Trocando óleo do caminhão %s %s (%d)\n", getNome(), getModelo(), getAno());
    }

    @Override
    public void limparMotor() {
        System.out.printf("  Limpando motor do caminhão %s %s (%d)\n", getNome(), getModelo(), getAno());
    }

    @Override
    public String toString() {
        return "Caminhao{" + "numeroEixos=" + numeroEixos + ", " + super.toString();
    }
    
}
