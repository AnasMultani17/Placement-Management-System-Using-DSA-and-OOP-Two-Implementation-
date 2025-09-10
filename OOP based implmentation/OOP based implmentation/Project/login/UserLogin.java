package login;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class UserLogin {
    public boolean validateLogin(String username, String password) 
    {
        try (BufferedReader reader = new BufferedReader(new FileReader("src/resources/usermanager.txt"))) 
        {
            String line;
            while ((line = reader.readLine()) != null) 
            {
                String usr = line.split(":")[0];
                String psw = line.split(":")[1];

                if (username.equals(usr) && password.equals(psw)) {
                    return true;
                }
            }
        } 
        catch (IOException e) 
        {
            System.out.println("An error occurred while reading the file.");
            e.printStackTrace();
        }
        return false;
    }
}
