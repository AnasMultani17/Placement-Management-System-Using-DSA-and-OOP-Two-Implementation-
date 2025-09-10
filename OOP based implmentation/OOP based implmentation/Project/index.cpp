#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include "jobopening/PlacedStudent.h"
#include "jobopening/JobShow.h"
#include "jobopening/JobCreate.h"
#include "login/UserLogin.h"
#include "login/StudentSignup.h"
#include "objs/Student.h"
#include "objs/Company.h"
#include "objs/StudentPersonal.h"
#include "objs/StudentAcademics.h"

using namespace std;

void sm();
void sLogin();
void sSignup();
bool isUsernameTaken(const string &uname);
void sApply();
void cm();
bool cLogin();
bool cSignup();
void cCreateJob();
void cViewApps();
void cShortlist();
void cViewShortlisted();
void cHire();

bool studentLoggedIn = false;

int main()
{
    cout << "===============================================================" << endl;
    cout << "              Welcome to Placement Manager                    " << endl;
    cout << "===============================================================" << endl;

    int ch;
    while (true)
    {
        cout << "1. Student" << endl;
        cout << "2. Company" << endl;
        cout << "3. Placement Data" << endl;
        cout << "-1. Exit" << endl;
        cout << "===============================================================" << endl;

        cin >> ch;
        cout << "===============================================================" << endl;

        switch (ch)
        {
        case 1:
            sm();
            break;
        case 2:
            cm();
            break;
        case 3:
            PlacedStudent::genReport();
            break;
        case -1:
            cout << "Exiting..." << endl;
            return 0;
        default:
            cout << "===============================================================" << endl;
            cout << "Invalid choice. Please try again." << endl;
            cout << "===============================================================" << endl;
        }
    }
    return 0;
}

void sm()
{
    int ch;
    while (true)
    {
        cout << "===============================================================" << endl;
        cout << "1. Login" << endl;
        cout << "2. Signup" << endl;
        if (studentLoggedIn)
        {
            cout << "3. Apply for Job" << endl;
        }
        cout << "-1. Back" << endl;
        cout << "===============================================================" << endl;

        cin >> ch;
        switch (ch)
        {
        case 1:
            sLogin();
            break;
        case 2:
            sSignup();
            break;
        case 3:
            if (studentLoggedIn)
            {
                sApply();
            }
            else
            {
                cout << "You need to login or signup first." << endl;
            }
            break;
        case -1:
            return;
        default:
            cout << "===============================================================" << endl;
            cout << "Invalid choice. Try again." << endl;
            cout << "===============================================================" << endl;
        }
    }
}

void sLogin()
{
    string u, p;
    cout << "Username same as Roll number: ";
    cin >> u;
    cout << "Password: ";
    cin >> p;

    UserLogin ul;
    if (ul.validateLogin(u, p))
    {
        cout << "Login successful! Welcome, " << u << endl;
        studentLoggedIn = true;
        JobShow::availableJob(u);
    }
    else
    {
        cout << "Invalid username or password." << endl;
    }
}

void sSignup()
{
    string roll, crs, uname, pwd, name, gen, addr, hb, skl;
    int age;
    float cgpa, ctc;

    cout << "Enter roll number: ";
    cin >> roll;
    cout << "Enter course: ";
    cin >> crs;
    cout << "Your username is your roll number...." << endl;
    uname = roll;

    if (isUsernameTaken(uname))
    {
        cout << "Username already taken. Please choose another." << endl;
        return;
    }

    cout << "Create password: ";
    cin >> pwd;
    StudentSignup ss(roll, crs, uname, pwd);
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the buffer

    cout << "Enter name: ";
    getline(cin, name);
    cout << "Enter age: ";
    cin >> age;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter gender: ";
    getline(cin, gen);
    cout << "Enter address: ";
    getline(cin, addr);
    cout << "Enter hobby: ";
    getline(cin, hb);

    cout << "Enter CGPA: ";
    cin >> cgpa;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter skills (*-separated): ";
    getline(cin, skl);
    cout << "Enter expected CTC: ";
    cin >> ctc;

    StudentPersonal sp(name, age, gen, addr, hb);
    StudentAcademics sa(roll, cgpa, skl, ctc);

    Student stu(ss, sp, sa);
    stu.saveAllDetailsToFile("resources/StudentDetailsMain.txt");
    cout << "Signup successful! You can now log in." << endl;
    studentLoggedIn = true;
}

bool isUsernameTaken(const string &uname)
{
    ifstream br("resources/usermanager.txt");
    if (!br.is_open())
    {
        cout << "Error reading user data." << endl;
        return false;
    }

    string line;
    while (getline(br, line))
    {
        size_t pos = line.find(':');
        if (pos != string::npos)
        {
            string user = line.substr(0, pos);
            if (user == uname)
            {
                br.close();
                return true;
            }
        }
    }
    br.close();
    return false;
}

void sApply()
{
    string roll;
    int jid;
    cout << "Enter roll number: ";
    cin >> roll;
    cout << "Enter Job ID: ";
    cin >> jid;
    JobCreate::applyToJob(jid, roll);
    cout << "Application submitted for Job ID " << jid << endl;
}

void cm()
{
    bool loggedIn = false;
    int ch;
    while (true)
    {
        if (!loggedIn)
        {
            cout << "===============================================================" << endl;
            cout << "1. Login" << endl;
            cout << "2. Signup" << endl;
            cout << "-1. Back" << endl;
            cout << "===============================================================" << endl;
        }
        else
        {
            cout << "===============================================================" << endl;
            cout << "3. Create Job" << endl;
            cout << "4. View Applicants" << endl;
            cout << "5. Shortlist Students" << endl;
            cout << "6. View Shortlisted Students" << endl;
            cout << "7. Hire a Student" << endl;
            cout << "-1. Back" << endl;
            cout << "===============================================================" << endl;
        }
        cin >> ch;
        switch (ch)
        {
        case 1:
            loggedIn = cLogin();
            break;
        case 2:
            loggedIn = cSignup();
            break;
        case 3:
            if (loggedIn)
                cCreateJob();
            else
                cout << "Login or signup first." << endl;
            break;
        case 4:
            if (loggedIn)
                cViewApps();
            else
                cout << "Login or signup first." << endl;
            break;
        case 5:
            if (loggedIn)
                cShortlist();
            else
                cout << "Login or signup first." << endl;
            break;
        case 6:
            if (loggedIn)
                cViewShortlisted();
            else
                cout << "Login or signup first." << endl;
            break;
        case 7:
            if (loggedIn)
                cHire();
            else
                cout << "Login or signup first." << endl;
            break;
        case -1:
            return;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    }
}

bool cLogin()
{
    string u, p;
    cout << "Enter username: ";
    cin >> u;
    cout << "Enter password: ";
    cin >> p;
    UserLogin ul;
    if (ul.validateLogin(u, p))
    {
        cout << "Login successful! Welcome, " << u << endl;
        return true;
    }
    else
    {
        cout << "Invalid username or password." << endl;
        return false;
    }
}

bool cSignup()
{
    string cname, uname, pwd, loc, type;
    int minCtc, maxCtc;

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the buffer
    cout << "Enter company name: ";
    getline(cin, cname);
    cout << "Enter username: ";
    getline(cin, uname);

    if (isUsernameTaken(uname))
    {
        cout << "Username already taken. Please choose another." << endl;
        return false;
    }

    cout << "Enter password: ";
    getline(cin, pwd);
    cout << "Enter location: ";
    getline(cin, loc);
    cout << "Enter type (e.g., IT): ";
    getline(cin, type);
    cout << "Enter min CTC: ";
    cin >> minCtc;
    cout << "Enter max CTC: ";
    cin >> maxCtc;

    Company c(uname, pwd, cname, loc, type, minCtc, maxCtc);
    cout << "Signup successful! You can now access all options." << endl;
    return true;
}

void cCreateJob()
{
    int jid, sal;
    float mts;
    string title, desc;

    cout << "Enter Job ID: ";
    cin >> jid;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter Job Title: ";
    getline(cin, title);
    cout << "Enter Description: ";
    getline(cin, desc);
    cout << "Enter Min Test Score: ";
    cin >> mts;
    cout << "Enter Salary: ";
    cin >> sal;

    JobCreate jc(jid, title, desc, mts, sal);
    cout << "Job created successfully." << endl;
}

void cViewApps()
{
    int jid;
    cout << "Enter Job ID: ";
    cin >> jid;
    JobCreate::dispDetail(jid);
}

void cShortlist()
{
    int jid, q;
    cout << "Enter Job ID: ";
    cin >> jid;
    cout << "Enter number of student you want to hire: ";
    cin >> q;
    JobCreate::shortlistStudents(jid, q);
}

void cViewShortlisted()
{
    int jid;
    cout << "Enter Job ID: ";
    cin >> jid;
    JobCreate::viewShortlisted(jid);
}

void cHire()
{
    int jid, ctc;
    string roll;
    cout << "Enter Job ID: ";
    cin >> jid;
    cout << "Enter Student Roll Number: ";
    cin >> roll;
    cout << "Enter ctc you want to offer: ";
    cin >> ctc;
    JobCreate::hireStudent(jid, roll, ctc);
}