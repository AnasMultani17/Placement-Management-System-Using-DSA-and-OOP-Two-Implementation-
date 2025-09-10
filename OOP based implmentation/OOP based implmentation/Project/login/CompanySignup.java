package login;

import java.io.FileWriter;
import java.io.IOException;
import objs.user;

public class CompanySignup extends user {
    private String username;
    private String password;

    public CompanySignup(String username, String password) {
        super(username, password, "company");
        this.username = username;
        this.password = password;
    }

    public void saveToFile(String filename) {
        try (FileWriter writer = new FileWriter(filename, true)) {
            writer.write("UserType: " + this.userType + ", Username: " + this.username + ", Password: " + this.password + "\n");
            System.out.println("===============================================================");
            System.out.println("Company signup details saved successfully.");
            System.out.println("===============================================================");
        } catch (IOException e) {
            System.out.println("===============================================================");
            System.out.println("An error occurred while saving company signup details.");
            System.out.println("===============================================================");
            e.printStackTrace();
        }
    }
}
