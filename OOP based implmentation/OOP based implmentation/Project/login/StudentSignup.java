package login;
import objs.user;

public class StudentSignup extends user {
    private String rollNum;
    private String course;

    public StudentSignup(String rollNum, String course, String username, String password) {
        super(username, password, "student");
        this.rollNum = rollNum;
        this.course = course;

    }
   
    public String getRollNum()
    {
        return rollNum;
    }
    public String getCourse()
    {
        return course;
    }
}
