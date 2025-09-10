package objs;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import test.mcqs;

public class StudentAcademics {
    private String rollNum;
    private float cgpa;
    private String skills;
    private float expectedCTC;
    private float testScore;

    // Constructor
    public StudentAcademics(String rollNum, float cgpa, String skills,float expectedCTC) {
        this.rollNum = rollNum;
        this.cgpa = cgpa;
        this.skills = skills;
        this.expectedCTC = expectedCTC;
        this.testScore = mcqs.giveTest(); 

        writeToStudentDetailsFile();
        writeToStudentTestFile();
        writeToCSV();
    }

    private void writeToStudentDetailsFile() {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter("A:\\oop\\Project\\objs\\StudentDetails.txt", true))) {
            writer.write(this.rollNum + "," + this.cgpa + "," + this.testScore + "," + this.skills + "," + this.expectedCTC +"\n");
        } catch (IOException e) {
            System.out.println("An error occurred while writing to StudentDetails.txt.");
            e.printStackTrace();
        }
    }

    private void writeToStudentTestFile() {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter("A:\\oop\\Project\\objs\\StudentTest.txt", true))) {
            writer.write(this.rollNum + ":" + this.testScore + "\n");
        } catch (IOException e) {
            System.out.println("An error occurred while writing to StudentTest.txt.");
            e.printStackTrace();
        }
    }

    private void writeToCSV() {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter("A:\\oop\\Project\\objs\\StudentAca.csv", true))) {
            writer.write(this.rollNum + "," + this.cgpa + "," + this.testScore + "," + this.skills + "," + this.expectedCTC +  "\n");
        } catch (IOException e) {
            System.out.println("An error occurred while writing to StudentAca.csv.");
            e.printStackTrace();
        }
    }

    public String getRollNum() {
        return rollNum;
    }

    public double getTestScore() {
        return testScore;
    }

    public float getCgpa() {
        return cgpa;
    }

    public String getSkills() {
        return skills;
    }
    public float getExpectedCTC() {
        return expectedCTC;
    }
}
