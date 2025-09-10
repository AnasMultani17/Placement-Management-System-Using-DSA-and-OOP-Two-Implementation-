package jobopening;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class JobShow {
    public static void availableJob(String rollNum) {
        String ans1 = "";
        boolean jobFound = false; 
      
        try (BufferedReader reader = new BufferedReader(new FileReader("src/resources/StudentTest.txt"))) {
            String line;
            while ((line = reader.readLine()) != null) {
                if (line.split(":")[0].trim().equals(rollNum)) {
                    ans1 = line.split(":")[1].trim();
                    break; 
                }
            }
        } catch (IOException e) {
            System.out.println("An error occurred while reading the StudentDetails file.");
            e.printStackTrace();
            return;
        }

        if (ans1.isEmpty()) {
            System.out.println("===============================================================");
            System.out.println("Roll number not found or score is missing.");
            System.out.println("===============================================================");
            return;
        }

        try (BufferedReader reader = new BufferedReader(new FileReader("src/resources/JobOpenings.txt"))) {
            String line;
            String ans = "";
            System.out.println("===============================================================");

            while ((line = reader.readLine()) != null) {
                if (!line.isEmpty()) {
                    if (line.startsWith("Minimum Test Score: ")) {
                        ans = line.split(": ")[1].trim();                       
                    }
                    if (!ans.isEmpty() && Float.parseFloat(ans) <= Float.parseFloat(ans1)) {
                            System.out.println(line);
                            jobFound = true;
                        }
                }
            }
            System.out.println("===============================================================");
        } catch (IOException e) {
            System.out.println("An error occurred while reading the JobOpening file.");
            e.printStackTrace();
        }
        
        if (!jobFound) {
            System.out.println("===============================================================");
            System.out.println("No job available for you.");
            System.out.println("===============================================================");
        }
    }
}
