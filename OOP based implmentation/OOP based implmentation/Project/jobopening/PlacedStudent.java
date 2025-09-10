package jobopening;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class PlacedStudent {
    public static void genReport() {
        try (BufferedReader reader = new BufferedReader(new FileReader("src/resources/hiredStudents.txt"))) {
            String line;
            System.out.println("===============================================================");
            System.out.println("----- Placed Students Report -----");

            while ((line = reader.readLine()) != null) {
                
                String[] details = line.split(" - ");

                if (details.length >= 3) {
                    String jobId = details[0].split(":")[1].trim();
                    String rollNumber = details[1].split(":")[1].trim();
                    String ctc = details[2].split(":")[1].trim();

                    System.out.println("Job ID: " + jobId + " || Roll Number: " + rollNumber + " || CTC: " + ctc);
                } else {
                    System.out.println("Invalid entry found in the file: " + line);
                }
            }

            System.out.println("----- End of Report -----");
            System.out.println("===============================================================");
        } catch (IOException e) {
            System.out.println("An error occurred while reading the file: " + e.getMessage());
            e.printStackTrace();
        }
    }
}
