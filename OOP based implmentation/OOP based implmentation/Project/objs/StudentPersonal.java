package objs;
import java.io.BufferedWriter;
import java.io.IOException;

public class StudentPersonal {
    private String name;
    private int age;
    private String gender;
    private String address;
    private String hobby;
   public StudentPersonal(String name, int age, String gender, String address, String hobby) 
   {
   
        this.name = name;
        this.age = age;
        this.gender = gender;
        this.address = address;
        this.hobby = hobby;
    }
    public String getName()
    {
        return name;
    }
    public int getAge()
    {
        return age;
    }
    public String getGender()
    {
        return gender;
    }
    public String getAddress()
    {
        return address;
    }
    public String getHobby()
    {
        return hobby;
    }
    public void writeToCSV(BufferedWriter csv) throws IOException {
        csv.write(name + "," + age + "," + gender + "," + address + "," + hobby + "\n");
    }
}
