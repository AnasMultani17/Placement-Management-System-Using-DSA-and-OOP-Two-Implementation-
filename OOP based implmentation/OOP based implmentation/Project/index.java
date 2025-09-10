import java.io.*;
import java.util.*;
import jobopening.*;
import login.*;
import objs.*;

public class index {
    static Scanner sc = new Scanner(System.in);
    private static boolean studentLoggedIn = false;

    public static void main(String[] args) {
        System.out.println("===============================================================");
        System.out.println("              Welcome to Placement Manager                    ");
        System.out.println("===============================================================");

        while (true) {
            System.out.println("1. Student");
            System.out.println("2. Company");
            System.out.println("3. Placement Data");
            System.out.println("-1. Exit");
            System.out.println("===============================================================");

            int ch = sc.nextInt();
            System.out.println("===============================================================");

            switch (ch) {
                case 1:
                    sm();
                    break;
                case 2:
                    cm();
                    break;
                case 3:
                    PlacedStudent.genReport();
                    break;
                case -1:
                    System.out.println("Exiting...");
                    sc.close();
                    return;
                default:
                    System.out.println("===============================================================");
                    System.out.println("Invalid choice. Please try again.");
                    System.out.println("===============================================================");
            }
        }
    }

    private static void sm() {
        while (true) {
            System.out.println("===============================================================");
            System.out.println("1. Login");
            System.out.println("2. Signup");
            if (studentLoggedIn) {
                System.out.println("3. Apply for Job");
            }
            System.out.println("-1. Back");
            System.out.println("===============================================================");

            int ch = sc.nextInt();
            switch (ch) {
                case 1:
                    sLogin();
                    break;
                case 2:
                    sSignup();
                    break;
                case 3:
                    if (studentLoggedIn) {
                        sApply();
                    } else {
                        System.out.println("You need to login or signup first.");
                    }
                    break;
                case -1:
                    return;
                default:
                    System.out.println("===============================================================");
                    System.out.println("Invalid choice. Try again.");
                    System.out.println("===============================================================");
            }
        }
    }

    private static void sLogin() {
        System.out.print("Username same as Roll number: ");
        String u = sc.next();
        System.out.print("Password: ");
        String p = sc.next();
        UserLogin ul = new UserLogin();
        if (ul.validateLogin(u, p)) {
            System.out.println("Login successful! Welcome, " + u);
            studentLoggedIn = true;
            JobShow.availableJob(u);
        } else {
            System.out.println("Invalid username or password.");
        }
    }

    private static void sSignup() {
        System.out.print("Enter roll number: ");
        String roll = sc.next();
        System.out.print("Enter course: ");
        String crs = sc.next();
        System.out.println("Your username is your roll number....");
        String uname = roll;
        if (isUsernameTaken(uname)) {
            System.out.println("Username already taken. Please choose another.");
            return;
        }

        System.out.print("Create password: ");
        String pwd = sc.next();
        StudentSignup ss = new StudentSignup(roll, crs, uname, pwd);

        System.out.print("Enter name: ");
        sc.nextLine();
        String name = sc.nextLine();
        System.out.print("Enter age: ");
        int age = sc.nextInt();
        System.out.print("Enter gender: ");
        sc.nextLine();
        String gen = sc.next();
        System.out.print("Enter address: ");
        sc.nextLine();
        String addr = sc.nextLine();
        System.out.print("Enter hobby: ");
        String hb = sc.nextLine();

        System.out.print("Enter CGPA: ");
        float cgpa = sc.nextFloat();
        System.out.print("Enter skills (*-separated): ");
        sc.nextLine();
        String skl = sc.nextLine();
        System.out.print("Enter expected CTC: ");
        float ctc = sc.nextFloat();
        StudentPersonal sp = new StudentPersonal(name, age, gen, addr, hb);
        StudentAcademics sa = new StudentAcademics(roll, cgpa, skl, ctc);

        Student stu = new Student(ss, sp, sa);
        stu.saveAllDetailsToFile("src/resources/StudentDetailsMain.txt");
        System.out.println("Signup successful! You can now log in.");
        studentLoggedIn = true;
    }

    private static boolean isUsernameTaken(String uname) {
        try (BufferedReader br = new BufferedReader(new FileReader("src/resources/usermanager.txt"))) {
            String line;
            while ((line = br.readLine()) != null) {
                if (line.split(":")[0].trim().equals(uname)) {
                    return true;
                }
            }
        } catch (IOException e) {
            System.out.println("Error reading user data.");
        }
        return false;
    }

    private static void sApply() {
        System.out.print("Enter roll number: ");
        String roll = sc.next();
        System.out.print("Enter Job ID: ");
        int jid = sc.nextInt();
        JobCreate.applyToJob(jid, roll);
        System.out.println("Application submitted for Job ID " + jid);
    }

    private static void cm() {
        boolean loggedIn = false;
        while (true) {
            if (!loggedIn) {
                System.out.println("===============================================================");
                System.out.println("1. Login");
                System.out.println("2. Signup");
                System.out.println("-1. Back");
                System.out.println("===============================================================");
            } else {
                System.out.println("===============================================================");
                System.out.println("3. Create Job");
                System.out.println("4. View Applicants");
                System.out.println("5. Shortlist Students");
                System.out.println("6. View Shortlisted Students");
                System.out.println("7. Hire a Student");
                System.out.println("-1. Back");
                System.out.println("===============================================================");
            }
            sc.nextLine();
            int ch = sc.nextInt();
            switch (ch) {
                case 1:
                    loggedIn = cLogin();
                    break;
                case 2:
                    loggedIn = cSignup();
                    break;
                case 3:
                    if (loggedIn) cCreateJob();
                    else System.out.println("Login or signup first.");
                    break;
                case 4:
                    if (loggedIn) cViewApps();
                    else System.out.println("Login or signup first.");
                    break;
                case 5:
                    if (loggedIn) cShortlist();
                    else System.out.println("Login or signup first.");
                    break;
                case 6:
                    if (loggedIn) cViewShortlisted();
                    else System.out.println("Login or signup first.");
                    break;
                case 7:
                    if (loggedIn) cHire();
                    else System.out.println("Login or signup first.");
                    break;
                case -1:
                    return;
                default:
                    System.out.println("Invalid choice. Try again.");
            }
        }
    }

    private static boolean cLogin() {
        System.out.print("Enter username: ");
        String u = sc.next();
        System.out.print("Enter password: ");
        String p = sc.next();
        UserLogin ul = new UserLogin();
        if (ul.validateLogin(u, p)) {
            System.out.println("Login successful! Welcome, " + u);
            return true;
        } else {
            System.out.println("Invalid username or password.");
            return false;
        }
    }

    private static boolean cSignup() {
        System.out.print("Enter company name: ");
        sc.nextLine();
        String cname = sc.nextLine();
        System.out.print("Enter username: ");
        String uname = sc.nextLine();

        if (isUsernameTaken(uname)) {
            System.out.println("Username already taken. Please choose another.");
            return false;
        }

        System.out.print("Enter password: ");
        String pwd = sc.nextLine();
        System.out.print("Enter location: ");
        String loc = sc.nextLine();
        System.out.print("Enter type (e.g., IT): ");
        String type = sc.nextLine();
        System.out.print("Enter min CTC: ");
        int minCtc = sc.nextInt();
        System.out.print("Enter max CTC: ");
        int maxCtc = sc.nextInt();

        Company c = new Company(uname, pwd, cname, loc, type, minCtc, maxCtc);
        System.out.println("Signup successful! You can now access all options.");
        return true;
    }

    private static void cCreateJob() {
        System.out.print("Enter Job ID: ");
        int jid = sc.nextInt();
        sc.nextLine();
        System.out.print("Enter Job Title: ");
        String title = sc.nextLine();
        System.out.print("Enter Description: ");
        String desc = sc.nextLine();
        System.out.print("Enter Min Test Score: ");
        float mts = sc.nextFloat();
        System.out.print("Enter Salary: ");
        int sal = sc.nextInt();
        JobCreate jc = new JobCreate(jid, title, desc, mts, sal);
        System.out.println("Job created successfully.");
    }

    private static void cViewApps() {
        System.out.print("Enter Job ID: ");
        int jid = sc.nextInt();
        JobCreate.dispDetail(jid);
    }

    private static void cShortlist() {
        System.out.print("Enter Job ID: ");
        int jid = sc.nextInt();
        System.out.print("Enter number of student you want to hire: ");
        int q= sc.nextInt();
        JobCreate.shortlistStudents(jid, q);
    }

    private static void cViewShortlisted() {
        System.out.print("Enter Job ID: ");
        int jid = sc.nextInt();
        JobCreate.viewShortlisted(jid);
    }

    private static void cHire() {
        System.out.print("Enter Job ID: ");
        int jid = sc.nextInt();
        System.out.print("Enter Student Roll Number: ");
        String roll = sc.next();
        System.out.print("Enter ctc you want to offer: ");
        int ctc = sc.nextInt();
        JobCreate.hireStudent(jid, roll,ctc);
    }
}
