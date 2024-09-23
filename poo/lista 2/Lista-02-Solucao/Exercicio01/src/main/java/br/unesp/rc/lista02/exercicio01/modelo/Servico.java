package br.unesp.rc.lista02.exercicio01.modelo;

/**
 *
 * @author Prof. Dr. Frank J. Affonso
 */
public class Servico {

    private boolean trocaDeOleo;
    private boolean trocaDePneu;
    private boolean limpezaDoMotor;

    public Servico() {
    }

    public Servico(boolean trocaDeOleo, boolean trocaDePneu, boolean limpezaDoMotor) {
        this.trocaDeOleo = trocaDeOleo;
        this.trocaDePneu = trocaDePneu;
        this.limpezaDoMotor = limpezaDoMotor;
    }

    public boolean isTrocaDeOleo() {
        return trocaDeOleo;
    }

    public void setTrocaDeOleo(boolean trocaDeOleo) {
        this.trocaDeOleo = trocaDeOleo;
    }

    public boolean isTrocaDePneu() {
        return trocaDePneu;
    }

    public void setTrocaDePneu(boolean trocaDePneu) {
        this.trocaDePneu = trocaDePneu;
    }

    public boolean isLimpezaDoMotor() {
        return limpezaDoMotor;
    }

    public void setLimpezaDoMotor(boolean limpezaDoMotor) {
        this.limpezaDoMotor = limpezaDoMotor;
    }

    @Override
    public String toString() {
        return "Servico{" + "trocaDeOleo=" + trocaDeOleo + ", trocaDePneu=" + trocaDePneu + ", limpezaDoMotor=" + limpezaDoMotor + '}';
    }

}
