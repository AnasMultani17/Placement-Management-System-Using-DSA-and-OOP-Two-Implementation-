package objs;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import login.StudentSignup;

public class Student {
    private StudentSignup signupDetails;
    private StudentPersonal personalDetails;
    private StudentAcademics academicDetails;

    public Student(StudentSignup signupDetails, StudentPersonal personalDetails, StudentAcademics academicDetails) {
        this.signupDetails = signupDetails;
        this.personalDetails = personalDetails;
        this.academicDetails = academicDetails;
    }

    public void saveAllDetailsToFile(String filename) {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(filename, true))) {
            writer.write("Username: " + signupDetails.getUsername() + ", ");
            writer.write("Password: " + signupDetails.getPassword() + ", ");
            writer.write("Roll Number: " + signupDetails.getRollNum() + ", ");
            writer.write("Course: " + signupDetails.getCourse() + "\n");
            
            writer.write("Name: " + personalDetails.getName() + ", ");
            writer.write("Age: " + personalDetails.getAge() + ", ");
            writer.write("Gender: " + personalDetails.getGender() + ", ");
            writer.write("Address: " + personalDetails.getAddress() + ", ");
            writer.write("Hobby: " + personalDetails.getHobby() + "\n");

            writer.write("CGPA: " + academicDetails.getCgpa() + ", ");
            writer.write("Skills: " + academicDetails.getSkills() + ", ");
            writer.write("Test Score: " + academicDetails.getTestScore() + ", ");
            writer.write("Expected CTC: " + academicDetails.getExpectedCTC() + ", ");
      
            writer.write("--------------------------------------------------\n");
            System.out.println("All student details saved successfully.");
        } catch (IOException e) {
            System.out.println("An error occurred while saving student details.");
            e.printStackTrace();
        }
    }
}
