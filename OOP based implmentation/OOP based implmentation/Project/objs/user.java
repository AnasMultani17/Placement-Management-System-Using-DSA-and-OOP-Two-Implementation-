package objs;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;

public class user {
    protected String username;
    protected String password;
    protected String userType;

    public user(String username, String password, String userType) {
        this.username = username;
        this.password = password;
        this.userType = userType;
        writeFile();
    }
    public void writeFile() {
        String filename = "src/resources/usermanager.txt"; 
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(filename, true))) {
            writer.write(getUsername() + ":" + getPassword() + "\n");
            System.out.println("===============================================================");
            System.out.println("User credentials saved successfully.");
            System.out.println("===============================================================");
        } catch (IOException e) {
            System.out.println("===============================================================");
            System.out.println("An error occurred while saving user credentials.");
            System.out.println("===============================================================");
            e.printStackTrace();
        }
    }

    public String getUsername() {
        return username;
    }

    public void setUsername(String username){ 
        this.username = username;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public String getUserType() {
        return userType;
    }
    public String getPassword() {
        return password;
    }
}
