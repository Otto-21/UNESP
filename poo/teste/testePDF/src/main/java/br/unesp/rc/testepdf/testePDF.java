package br.unesp.rc.testepdf;

import com.itextpdf.kernel.pdf.PdfDocument;
import com.itextpdf.kernel.pdf.PdfWriter;
import com.itextpdf.layout.Document;
import com.itextpdf.layout.element.Paragraph;
import com.itextpdf.kernel.font.PdfFont;
import com.itextpdf.kernel.font.PdfFontFactory;
import com.itextpdf.io.font.constants.StandardFonts;
import com.itextpdf.kernel.pdf.canvas.draw.SolidLine;
import com.itextpdf.layout.element.LineSeparator;
import com.itextpdf.layout.properties.TextAlignment;
import com.itextpdf.layout.properties.UnitValue;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.List;

/**
 *
 * @author ottoj
 */
public class testePDF {

    public static void main(String[] args) {
        String dest = "new_page_example.pdf";

        try {
            // Cria o escritor de PDF
            PdfWriter writer = new PdfWriter("C:\\Users\\ottoj\\Downloads\\aaaaaa\\Relatorio.pdf");

            // Cria o documento PDF
            PdfDocument pdfDoc = new PdfDocument(writer);
            Document document = new Document(pdfDoc);

            // Adiciona um parágrafo de texto na primeira página
            Paragraph para1 = new Paragraph("Este parágrafo está na primeira página.");
            document.add(para1);

            // Adiciona uma nova página
            pdfDoc.addNewPage();

            // Adiciona um parágrafo de texto na segunda página
            Paragraph para2 = new Paragraph("Este parágrafo está na segunda página.");
            document.add(new Paragraph("\n\n\n\n\n"));  // Adiciona espaço para garantir que o parágrafo esteja na segunda página
            document.add(para2);

            // Fecha o documento
            document.close();

            System.out.println("PDF criado com sucesso.");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
