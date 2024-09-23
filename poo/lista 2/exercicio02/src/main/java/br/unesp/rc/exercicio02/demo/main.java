/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.unesp.rc.exercicio02.demo;

import br.unesp.rc.exercicio02.visao.FormPrincipal;
import java.text.ParseException;
import javax.swing.JFrame;
/**
 *
 * @author ottoj
 */
import javax.swing.JFrame;
public class main {
    
    public static void main(String[] args) throws ParseException {
        JFrame frame= new FormPrincipal();
        frame.pack();
        frame.setVisible(true);
    }
   
}
