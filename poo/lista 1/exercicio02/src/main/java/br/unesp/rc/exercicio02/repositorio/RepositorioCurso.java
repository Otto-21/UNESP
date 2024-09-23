package br.unesp.rc.exercicio02.repositorio;

import br.unesp.rc.exercicio02.modelo.Curso;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author Otto
 */
public class RepositorioCurso {
    private List<Curso> cursos;

    public RepositorioCurso() {
        cursos = new ArrayList<>();
    }
    
    public void adicionar(Curso curso){
        cursos.add(curso);
    }
    
    /**
     * calcula e imprime as informações do curso com a maior relação candidato/vaga
     */
    public void cursoMaiorCandidatoVaga(){
        int comparaQtdCandidato=0;
        Curso cursoMaiorCandidatoVaga= new Curso();
        for(Curso c: cursos){
            if(c.calcularTotalCandidatos()>comparaQtdCandidato){
                comparaQtdCandidato=c.calcularTotalCandidatos();
                cursoMaiorCandidatoVaga=c;
            }
        }
        System.out.printf("\nCurso com maior numero de candidato/vaga: %s\tCodigo: %d\tRelacao candidato/vaga: %2.2f",
                cursoMaiorCandidatoVaga.getNome(),cursoMaiorCandidatoVaga.getCodigo(),cursoMaiorCandidatoVaga.calcularRelacaoCandidatoVaga());
    }
    
    /**
     * calcula e imprime o total de candidatos inscritos
     */
    public void calcularTotalCandidatos(){
        int total=0;
        for(Curso c: cursos){
            total+=c.calcularTotalCandidatos();
        }
        System.out.printf("\n\nO total de candidatos é: %d",total);
    }
    
    /**
     * imprime os dados gerais de cada curso cadastrado
     */
    public void imprime(){
        for(Curso c : cursos){
            System.out.println(c);
            System.out.println("\tCandidato/Vaga: "+c.calcularRelacaoCandidatoVaga());
            System.out.printf("\tPorcentagem Feminina: %2.2f%%\n",c.calcularPorcentagemCandidatosFeminino());
            System.out.println("\tTotal Candidatos: "+c.calcularTotalCandidatos());
            System.out.println("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
        }
    }

}
