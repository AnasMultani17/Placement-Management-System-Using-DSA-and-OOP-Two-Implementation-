package test;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;

public class mcqs {
    public static Scanner sc = new Scanner(System.in);

    public static float giveTest() {
        int score = 0;
        int totalQue = 0;       
        try (BufferedReader reader = new BufferedReader(new FileReader("src/resources/dsa_mcq_placement_test.txt"))) {
            String line;
            String ans = "";

            while ((line = reader.readLine()) != null) { 
                if (!line.isEmpty()) {
                    if (line.startsWith("Answer:")) {
                        ans = line.split(": ")[1].trim();
                        System.out.print("Give your answer: ");
                        String answer = sc.nextLine();

                        if (answer.equalsIgnoreCase(ans)) {
                            score++;
                        }
                        totalQue++;
                    } else {
                        System.out.println(line);
                    }
                }
            }

        } catch (IOException e) {
            System.out.println("An error occurred while reading the file.");
            e.printStackTrace();
        }
        
        return totalQue > 0 ? (score * 100.0f / totalQue) : 0;
    }
}
