package br.unesp.rc.lista02.utilitarios;

import java.text.SimpleDateFormat;
import java.util.Date;

/**
 *
 * @author Prof. Dr. Frank J. Affonso
 */
public class Conversor {

    private Conversor() {

    }

    public static Date converterStringParaDate(String data) {
        SimpleDateFormat simpleDateFormat = new SimpleDateFormat("dd/MM/yyyy");
        try {
            return simpleDateFormat.parse(data);
        } catch (Exception ex) {
            System.out.printf("[ERRO] Não foi possível formatar a data %s\n", data);
        }
        return null;
    }

}
