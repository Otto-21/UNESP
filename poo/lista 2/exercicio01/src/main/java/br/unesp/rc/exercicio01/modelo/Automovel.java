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
public class Automovel extends Veiculo{
    private int numeroPassageiros;

    public Automovel() {
    }

    public Automovel(int numeroPassageiros, String marca, String modelo, int ano) {
        super(marca, modelo, ano);
        this.numeroPassageiros = numeroPassageiros;
    }

    public int getNumeroPassageiros() {
        return numeroPassageiros;
    }

    public void setNumeroPassageiros(int numeroPassageiros) {
        this.numeroPassageiros = numeroPassageiros;
    }

    @Override
    public void trocarPneu() {
        System.out.printf("  Trocando pneu do automóvel %s %s (%d)\n", getNome(), getModelo(), getAno());
    }

    @Override
    public void trocarOleo() {
        System.out.printf("  Trocando óleo do automóvel %s %s (%d)\n", getNome(), getModelo(), getAno());
    }

    @Override
    public void limparMotor() {
        System.out.printf("  Limpando motor do automóvel %s %s (%d)\n", getNome(), getModelo(), getAno());
    }

    @Override
    public String toString() {
        return "Automovel{" + "numeroPassageiros=" + numeroPassageiros + ", " + super.toString();
    }
}
