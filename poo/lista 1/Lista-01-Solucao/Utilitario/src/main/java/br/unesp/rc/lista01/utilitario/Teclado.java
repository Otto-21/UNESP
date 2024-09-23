package br.unesp.rc.lista01.utilitario;

import java.util.Scanner;

/**
 *
 * @author Prof. Dr. Frank J. Affonso
 */
public class Teclado {

    private static Scanner scanner = new Scanner(System.in);

    private Teclado() {

    }

    public static boolean lerBoolean() {
        return scanner.nextBoolean();
    }

    public static char lerChar() {
        String token = scanner.next();
        return token.charAt(0);
    }

    public static byte lerByte() {
        return scanner.nextByte();
    }

    public static short lerShort() {
        return scanner.nextShort();
    }

    public static int lerInt() {
        int numero = scanner.nextInt();
        scanner.nextLine(); // bug: https://stackoverflow.com/questions/13102045/scanner-is-skipping-nextline-after-using-next-or-nextfoo
        return numero;
    }

    public static long lerLong() {
        return scanner.nextLong();
    }

    public static float lerFloat() {
        return scanner.nextFloat();
    }

    public static double lerDouble() {
        return scanner.nextDouble();
    }

    public static String lerString() {
        return scanner.nextLine();
    }

}
