package jobopening;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class JobCreate {
    private int jobid;
    private String jobname;
    private String jobdetails;
    private float mintest;
    private int offeredctc;

    public JobCreate(int jobid, String jobname, String jobdetails, float mintest, int offeredctc) {
        this.jobid = jobid;
        this.jobname = jobname;
        this.jobdetails = jobdetails;
        this.mintest = mintest;
        this.offeredctc = offeredctc;
        saveJobDetails();
    }

    public static void applyToJob(int jobid1, String rollNumber) 
    {
        try (FileWriter writer = new FileWriter("A:\\oop\\Project\\jobopening\\JobApplications.txt", true)) 
        {
            writer.write(jobid1 + ":" + rollNumber + "\n");
            System.out.println("===============================================================");
            System.out.println("Application saved successfully.");
            System.out.println("===============================================================");
        } 
        catch (IOException e) 
        {
            e.printStackTrace();
        }
    }

    public static void dispDetail(int jobid){

     List<String> applicants = new ArrayList<>(); //list will store the eligible students roll number 
        try (BufferedReader reader = new BufferedReader(new FileReader("A:\\oop\\Project\\jobopening\\JobApplications.txt"))) {
            String line;
            while ((line = reader.readLine()) != null) {
                String jobIdInFile = line.split(":")[0].trim();
                if (Integer.parseInt(jobIdInFile) == jobid) {
                    applicants.add(line.split(":")[1].trim());
                }
            }
        } catch (IOException e) {
            System.out.println("===============================================================");
            System.out.println("An error occurred while reading the JobApplications file.");
            System.out.println("===============================================================");
            e.printStackTrace();
            return;
        }

        if (applicants.isEmpty()) {
            System.out.println("===============================================================");
            System.out.println("No applicants found for Job ID " + jobid);
            System.out.println("===============================================================");
            return;
        }
        try (BufferedReader reader = new BufferedReader(new FileReader("A:\\oop\\Project\\objs\\StudentDetails.txt"))) 
        {
            String line;
            while ((line = reader.readLine()) != null)
            {
                for (String rollNumber : applicants) 
                {
                    if (line.startsWith(rollNumber)) 
                    {
                        String[] details = line.split(",");
                        if (details.length >= 5) 
                        {

                            System.out.println("===============================================================");
                            System.out.println("Roll Number: " + details[0].trim());
                            System.out.println("CGPA: " + details[1].trim());
                            System.out.println("Test Score: " + details[2].trim());
                            System.out.println("Skills: " + details[3].trim());
                            System.out.println("Expected CTC: " + details[4].trim());
                            System.out.println();
                            System.out.println("===============================================================");
                        } 
                        else 
                        {
                            System.out.println("===============================================================");
                            System.out.println("Incomplete data for roll number: " + rollNumber);
                            System.out.println("===============================================================");
  
                        }
                    }
                }
            }
        } 
        catch (IOException e) 
        {
            System.out.println("===============================================================");
            System.out.println("An error occurred while reading the StudentDetails file.");
            System.out.println("===============================================================");

            e.printStackTrace();
        }
    }
    public static void shortlistStudents(int jobId, int n) {
    try (FileWriter writer = new FileWriter("A:\\oop\\Project\\jobopening\\shortlisted.txt", true)) 
    {
        Scanner sc = new Scanner(System.in);
        writer.write("Job ID: " + jobId + "\n");
        writer.write("Shortlisted Students: \n");
        System.out.println("===============================================================");
        for (int i = 0; i < n; i++) 
        {
            
            System.out.print("Enter Roll Number for Student " + (i + 1) + ": ");
            String rollNumber = sc.nextLine();
            writer.write(rollNumber + "\n");
        }
            System.out.println("===============================================================");

        writer.write("\n");
        System.out.println("===============================================================");
        System.out.println("Students shortlisted successfully.");
        System.out.println("===============================================================");
    } 
    catch (IOException e) 
    {
        System.out.println("An error occurred while writing to the shortlisted file.");
        e.printStackTrace();
    }
}

    public static void viewShortlisted(int jobId) {
    try (BufferedReader reader = new BufferedReader(new FileReader("A:\\oop\\Project\\jobopening\\shortlisted.txt"))) {
        String line;
        boolean jobFound = false;

        while ((line = reader.readLine()) != null) {
            line = line.trim();

            if (line.equals("Job ID: " + jobId)) {
                jobFound = true;
                System.out.println("===============================================================");
                System.out.println("----- Shortlisted Students for Job ID: " + jobId + " -----");
                System.out.println(line);
                while ((line = reader.readLine()) != null) {
                    line = line.trim();
                    if (line.isEmpty()) {
                        break; 
                    }
                    System.out.println(line);
                }
                System.out.println("===============================================================");
                break;
            }
        }

        if (!jobFound) {
            System.out.println("===============================================================");
            System.out.println("No shortlisted students found for Job ID " + jobId);
            System.out.println("===============================================================");
        }
    } catch (IOException e) {
        System.out.println("An error occurred while reading the shortlisted file.");
        e.printStackTrace();
    }
}


    
   public static void hireStudent(int jobId, String rollNumber, double ctc) {
    try (FileWriter writer = new FileWriter("A:\\oop\\Project\\jobopening\\hiredStudents.txt", true)) {
        writer.write("Job ID: " + jobId + " - Hired Roll Number: " + rollNumber + " - CTC: " + ctc + "\n");
        System.out.println("===============================================================");
        System.out.println("Student " + rollNumber + " has been hired for Job ID " + jobId + " with CTC: " + ctc);
        System.out.println("===============================================================");
    } catch (IOException e) {
        System.out.println("An error occurred while writing to the hired students file.");
        e.printStackTrace();
    }        
}
    public void saveJobDetails() {
        try (FileWriter writer = new FileWriter("A:\\oop\\Project\\jobopening\\JobOpenings.txt", true)) {
            writer.write("Minimum Test Score: " + mintest + "\n");
            writer.write("Job ID: " + jobid + "\n");
            writer.write("Job Title: " + jobname + "\n");
            writer.write("Description: " + jobdetails + "\n");
            writer.write("Salary: " + offeredctc + "\n");
            writer.write("\n");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
