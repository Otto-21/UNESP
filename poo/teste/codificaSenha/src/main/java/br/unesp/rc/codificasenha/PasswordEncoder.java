/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.unesp.rc.codificasenha;

import java.util.Random;
import java.util.Scanner;

/**
 *
 * @author ottoj
 */
public class PasswordEncoder {
    // Método para codificar a senha
    public static String encodePassword(String password) {
        // Modificação 1: Substituir algumas letras por números
        password = password.replace('a', '4');
        password = password.replace('e', '3');
        password = password.replace('i', '1');
        password = password.replace('o', '0');
        
        // Modificação 2: Adicionar caracteres especiais
        Random random = new Random();
        String specialChars = "!@#$%&*";
        StringBuilder encodedPassword = new StringBuilder();
        for (char c : password.toCharArray()) {
            encodedPassword.append(c);
            if (random.nextBoolean()) {
                encodedPassword.append(specialChars.charAt(random.nextInt(specialChars.length())));
            }
        }
        
        // Modificação 3: Misturar as letras
        char[] charArray = encodedPassword.toString().toCharArray();
        for (int i = 0; i < charArray.length; i++) {
            int randomIndex = random.nextInt(charArray.length);
            char temp = charArray[i];
            charArray[i] = charArray[randomIndex];
            charArray[randomIndex] = temp;
        }
        
        return new String(charArray);
    }
    
    // Método para decodificar a senha
    public static String decodePassword(String encodedPassword) {
        // Modificação 3: Inverter a mistura de letras
        char[] charArray = encodedPassword.toCharArray();
        for (int i = 0; i < charArray.length / 2; i++) {
            char temp = charArray[i];
            charArray[i] = charArray[charArray.length - i - 1];
            charArray[charArray.length - i - 1] = temp;
        }
        
        // Modificação 2: Remover os caracteres especiais
        StringBuilder decodedPassword = new StringBuilder();
        for (char c : charArray) {
            if (Character.isLetterOrDigit(c)) {
                decodedPassword.append(c);
            }
        }
        
        // Modificação 1: Substituir os números por letras
        decodedPassword = new StringBuilder(decodedPassword.toString().replace('4', 'a'));
        decodedPassword = new StringBuilder(decodedPassword.toString().replace('3', 'e'));
        decodedPassword = new StringBuilder(decodedPassword.toString().replace('1', 'i'));
        decodedPassword = new StringBuilder(decodedPassword.toString().replace('0', 'o'));
        
        return decodedPassword.toString();
    }
    
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        System.out.print("Digite a senha: ");
        String password = scanner.nextLine();
        
        // Codificar a senha
        String encodedPassword = encodePassword(password);
        System.out.println("Senha codificada: " + encodedPassword);
        
        // Decodificar a senha
        String decodedPassword = decodePassword(encodedPassword);
        System.out.println("Senha decodificada: " + decodedPassword);
        
        scanner.close();
    }
}
