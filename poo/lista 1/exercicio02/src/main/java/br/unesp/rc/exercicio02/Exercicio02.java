package br.unesp.rc.exercicio02;

import br.unesp.rc.exercicio02.modelo.Curso;
import br.unesp.rc.exercicio02.repositorio.RepositorioCurso;

/**
 *
 * @author aluno
 */
public class Exercicio02 {

    public static void main(String[] args) {
        Curso c1 = new Curso("BCC", 1, 30, 50, 10);
        Curso c2 = new Curso("Geografia", 2, 30, 10, 50);
        Curso c3 = new Curso("Geologia", 3, 30, 40, 40);
        Curso c4 = new Curso("Pedagogia", 4, 30, 10, 50);
        Curso c5 = new Curso("Biologia", 5, 30, 30, 30);
        
        RepositorioCurso repositorio= new RepositorioCurso();
        repositorio.adicionar(c1);
        repositorio.adicionar(c2);
        repositorio.adicionar(c3);
        repositorio.adicionar(c4);
        repositorio.adicionar(c5);
        
        repositorio.imprime();
        repositorio.cursoMaiorCandidatoVaga();
        repositorio.calcularTotalCandidatos();
    }
}
