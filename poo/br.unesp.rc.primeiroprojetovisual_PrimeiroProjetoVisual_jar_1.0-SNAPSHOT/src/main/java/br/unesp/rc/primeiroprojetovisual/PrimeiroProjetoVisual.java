/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Project/Maven2/JavaApp/src/main/java/${packagePath}/${mainClassName}.java to edit this template
 */

package br.unesp.rc.primeiroprojetovisual;

import br.unesp.rc.primeiroprojetovisual.visual.FormPrincipal;
import javax.swing.JFrame;

/**
 *
 * @author aluno
 */
public class PrimeiroProjetoVisual {

    public static void main(String[] args) {
        JFrame frame= new FormPrincipal();
        frame.pack();
        frame.setVisible(true);
    }
}
