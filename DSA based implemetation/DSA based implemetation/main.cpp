#include <bits/stdc++.h>
using namespace std;

struct student
{
    string roll;
    string course;
    string usr;
    string psw;
    string name;
    int age;
    string gender;
    string address;
    string hobby;
    float cgpa;
    string skills;
    float ctc;
    student *next;
};

struct company
{
    string cname;
    string usr;
    string psw;
    string loc;
    string type;
    int minctc;
    int maxctc;
    company *next;
};

struct tnode
{
    string question;
    string a;
    string b;
    string c;
    string d;
    char ans;
    tnode *next;
};

struct job
{
    int jid;
    string title;
    string description;
    float minscore;
    int salary;
    tnode *test;
    job *next;
};

struct jobapplication
{
    string studentusr;
    int jid;
    float expectedctc;
    string skills;
    float cgpa;
    jobapplication *next;
};

struct hiredstudent
{
    string studentusr;
    int jid;
    string title;
    float finalctc;
    hiredstudent *next;
};

unordered_map<string, string> userdetails;
student *studentstart = nullptr;
company *companystart = nullptr;
job *jobstart = nullptr;
jobapplication *application = nullptr;
hiredstudent *hiredstart = nullptr;
tnode *bydefault = nullptr;

bool loggedin = false;
void pl()
{
    cout << "===============================================================" << endl;
}

bool isusertaken(string usr1)
{
    student *tempstudent = studentstart;
    while (tempstudent)
    {
        if (tempstudent->usr == usr1)
            return true;
        tempstudent = tempstudent->next;
    }
    company *tempcompany = companystart;
    while (tempcompany)
    {
        if (tempcompany->usr == usr1)
            return true;
        tempcompany = tempcompany->next;
    }
    return false;
}
tnode *maketest()
{
    pl();
    cout << "Enter number of questions to be added: ";
    int n;
    cin >> n;
    pl();

    tnode *start = nullptr;
    tnode *temp = nullptr;

    for (int i = 0; i < n; ++i)
    {
        tnode *n1 = new tnode;

        cout << "Enter the question: ";
        cin.ignore();
        getline(cin, n1->question);

        cout << "Enter option A: ";
        getline(cin, n1->a);

        cout << "Enter option B: ";
        getline(cin, n1->b);

        cout << "Enter option C: ";
        getline(cin, n1->c);

        cout << "Enter option D: ";
        getline(cin, n1->d);
        cout << "Enter the correct answer (a, b, c, or d): ";
        cin >> n1->ans;
        n1->next = nullptr;
        if (start == nullptr)
        {
            start = n1;
        }
        else
        {
            temp->next = n1;
        }
        temp = n1;
    }

    return start;
}
void createjob()
{
    pl();
    cout << "Enter Job ID: ";
    int jid;
    cin >> jid;
    cout << "Enter Job Title: ";
    string title;
    cin.ignore();
    getline(cin, title);
    cout << "Enter Job Description: ";
    string description;
    getline(cin, description);
    cout << "Enter Minimum Test Score: ";
    float minscore;
    cin >> minscore;
    cout << "Enter Salary: ";
    int salary;
    cin >> salary;

    job *nj = new job;
    nj->jid = jid;
    nj->title = title;
    nj->description = description;
    nj->minscore = minscore;
    nj->salary = salary;

    cout << "Do you want to create your own test? (y/n): ";
    char l;
    cin >> l;
    if (l == 'n')
    {
        nj->test = bydefault;
    }
    else
    {
        nj->test = maketest();
    }

    nj->next = jobstart;
    jobstart = nj;

    cout << "Job created successfully." << endl;
}

float givetest(tnode *start)
{
    int que = 0;
    int c = 0;

    while (start != nullptr)
    {
        que++;
        cout << "Question " << que << ": " << start->question << endl;
        cout << "A. " << start->a << endl;
        cout << "B. " << start->b << endl;
        cout << "C. " << start->c << endl;
        cout << "D. " << start->d << endl;

        cout << "Enter your answer (a, b, c, or d): ";
        char answer;
        cin >> answer;

        if (answer == start->ans)
        {
            c++;
        }

        start = start->next;
    }
    if (que > 0)
    {
        return ((float)(c) / que) * 100;
    }
    else
    {
        return 0;
    }
}

bool validatelogin(string usr, string psw)
{
    if (userdetails.find(usr) != userdetails.end() && userdetails[usr] == psw)
    {
        return true;
    }
    return false;
}

bool loggedinstudent = false;

void studentlogin()
{
    pl();
    cout << "Enter username (Roll Number): ";
    string usr;
    cin >> usr;
    cout << "Enter password: ";
    string psw;
    cin >> psw;

    if (validatelogin(usr, psw))
    {
        cout << "Login successful! Welcome, " << usr << endl;
        loggedinstudent = true;
        cout << "Available Jobs:" << endl;
        job *job = jobstart;
        while (job != nullptr)
        {
            cout << "Job ID: " << job->jid << ", Title: " << job->title << ", Salary: " << job->salary << endl;
            job = job->next;
        }
    }
    else
    {
        cout << "Invalid username or password." << endl;
    }
}

void studentsignup()
{
    pl();
    cout << "Enter Roll Number: ";
    string roll;
    cin >> roll;
    cout << "Enter Course: ";
    string course;
    cin >> course;
    cout << "Username is same as Roll Number" << endl;

    if (isusertaken(roll))
    {
        cout << "Username already taken. Please choose another." << endl;
        return;
    }

    cout << "Create password: ";
    string psw;
    cin >> psw;

    student *ns = new student;
    ns->roll = roll;
    ns->course = course;
    ns->usr = roll;
    ns->psw = psw;
    ns->next = studentstart;
    studentstart = ns;
    userdetails[roll] = psw;
    loggedinstudent = true;
    cout << "Signup successful! You can now log in." << endl;
}

bool companylogin()
{
    pl();
    cout << "Enter Company Username: ";
    string usr;
    cin >> usr;
    cout << "Enter Password: ";
    string psw;
    cin >> psw;

    if (validatelogin(usr, psw))
    {
        cout << "Login successful! Welcome, " << usr << endl;
        return true;
    }
    else
    {
        cout << "Invalid username or password." << endl;
        return false;
    }
}

void companysignup()
{
    pl();
    cout << "Enter Company Name: ";
    string cname;
    cin.ignore();
    getline(cin, cname);

    cout << "Enter Username: ";
    string usr;
    cin >> usr;

    if (isusertaken(usr))
    {
        cout << "Username already taken. Please choose another." << endl;
        return;
    }

    cout << "Create Password: ";
    string psw;
    cin >> psw;

    cout << "Enter Location: ";
    string loc;
    cin.ignore();
    getline(cin, loc);

    cout << "Enter Company Type (e.g., IT, Finance): ";
    string type;
    getline(cin, type);

    cout << "Enter Minimum CTC: ";
    int minctc;
    cin >> minctc;

    cout << "Enter Maximum CTC: ";
    int maxctc;
    cin >> maxctc;

    company *nc = new company;
    nc->cname = cname;
    nc->usr = usr;
    nc->psw = psw;
    nc->loc = loc;
    nc->type = type;
    nc->minctc = minctc;
    nc->maxctc = maxctc;
    nc->next = companystart;
    companystart = nc;
    userdetails[usr] = psw;
    cout << "Signup successful! You can now log in." << endl;
}

void applyforjob()
{
    pl();
    cout << "Available Jobs:" << endl;
    job *job = jobstart;
    while (job != nullptr)
    {
        cout << "Job ID: " << job->jid << ", Title: " << job->title << ", Salary: " << job->salary << endl;
        job = job->next;
    }

    cout << "Enter Job ID to apply: ";
    int jid;
    cin >> jid;

    cout << "Enter Roll Number (Student username): ";
    string roll;
    cin >> roll;

    job = jobstart;
    while (job && job->jid != jid)
    {
        job = job->next;
    }

    if (job == nullptr)
    {
        cout << "Job not found." << endl;
        return;
    }

    if (job->test != nullptr)
    {
        cout << "You need to take a test to apply for this job." << endl;
        float score = givetest(job->test);

        cout << "Your score: " << score << endl;
        if (score < job->minscore)
        {
            cout << "Job application failed due to low test score." << endl;
            return;
        }
    }

    cout << "Enter expected CTC: ";
    float expectedctc;
    cin >> expectedctc;

    cout << "Enter your skills (comma-separated): ";
    string skills;
    cin.ignore();
    getline(cin, skills);

    cout << "Enter your CGPA: ";
    float cgpa;
    cin >> cgpa;

    jobapplication *newapp = new jobapplication;
    newapp->studentusr = roll;
    newapp->jid = jid;
    newapp->expectedctc = expectedctc;
    newapp->skills = skills;
    newapp->cgpa = cgpa;
    newapp->next = application;
    application = newapp;

    cout << "Job application submitted successfully!" << endl;
}
void hirestudent()
{
    pl();
    cout << "Enter Job ID for which to hire a student: ";
    int jid;
    cin >> jid;

    cout << "Enter Roll Number (Student username) of the student to be hired: ";
    string roll;
    cin >> roll;

    job *job = jobstart;
    while (job && job->jid != jid)
    {
        job = job->next;
    }

    if (job == nullptr)
    {
        cout << "Job not found." << endl;
        return;
    }

    jobapplication *prev = nullptr;
    jobapplication *curr = application;

    while (curr != nullptr)
    {
        if (curr->studentusr == roll && curr->jid == jid)
        {
            cout << "Enter final CTC for the student: ";
            float finalctc;
            cin >> finalctc;
            if (prev != nullptr)
            {
                prev->next = curr->next;
            }
            else
            {
                application = curr->next;
            }

            hiredstudent *newhire = new hiredstudent;
            newhire->studentusr = roll;
            newhire->jid = jid;
            newhire->title = job->title;
            newhire->finalctc = finalctc;
            newhire->next = hiredstart;
            hiredstart = newhire;

            delete curr;
            cout << "Student hired successfully with a CTC of " << finalctc << "!" << endl;
            return;
        }
        prev = curr;
        curr = curr->next;
    }

    cout << "No application found for this student and job ID." << endl;
}

void viewhiredstudents()
{
    pl();
    cout << "Hired Students:" << endl;

    hiredstudent *curr = hiredstart;
    while (curr != nullptr)
    {
        cout << "Student Username: " << curr->studentusr << ", Job ID: " << curr->jid
             << ", Job Title: " << curr->title << ", Final CTC: " << curr->finalctc << endl;
        curr = curr->next;
    }
}

void viewapplications()
{
    pl();
    cout << "Enter Job ID to view applications: ";
    int jid;
    cin >> jid;

    bool found = false;
    jobapplication *curr = application;
    while (curr != nullptr)
    {
        if (curr->jid == jid)
        {
            cout << "Student Username: " << curr->studentusr << ", Job ID: " << curr->jid
                 << ", Expected CTC: " << curr->expectedctc << ", Skills: " << curr->skills
                 << ", CGPA: " << curr->cgpa << endl;
            found = true;
        }
        curr = curr->next;
    }

    if (!found)
    {
        cout << "No applications found for Job ID: " << jid << endl;
    }
}

void studentmenu()
{
    while (true)
    {
        pl();
        cout << "1. Login" << endl;
        cout << "2. Signup" << endl;
        if (loggedinstudent)
        {
            cout << "3. Apply for Job" << endl;
        }
        cout << "-1. Back" << endl;

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
            studentlogin();
            break;
        case 2:
            studentsignup();
            break;
        case 3:
            if (loggedinstudent)
            {
                applyforjob();
            }
            else
            {
                cout << "Please login or signup first to apply for jobs." << endl;
            }
            break;
        case -1:
            return;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    }
}

void companymenu()
{
    while (true)
    {
        pl();
        if (!loggedin)
        {
            cout << "1. Login" << endl;
            cout << "2. Signup" << endl;
            cout << "-1. Back" << endl;
        }
        else
        {
            cout << "3. Create Job" << endl;
            cout << "4. View Applicants" << endl;
            cout << "5. Hire Student" << endl;
            cout << "-1. Back" << endl;
        }

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
            loggedin = companylogin();
            break;
        case 2:
            companysignup();
            break;
        case 3:
            createjob();
            break;
        case 4:
            viewapplications();
            break;
        case 5:
            hirestudent();
            break;
        case -1:
            return;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    }
}

void preport()
{
    pl();
    cout << "Placement Report" << endl;
    hiredstudent *curr = hiredstart;
    if (!curr)
    {
        cout << "No students hired yet." << endl;
        return;
    }

    while (curr != nullptr)
    {
        cout << "Student Username: " << curr->studentusr << ", Job ID: " << curr->jid
             << ", Job Title: " << curr->title << ", Final CTC: " << curr->finalctc << endl;
        curr = curr->next;
    }
}
void adminmenu()
{
    while (true)
    {
        pl();
        cout << "Admin Section" << endl;
        cout << "1. Print Placement Report" << endl;
        cout << "2. Create Default Test" << endl;
        cout << "-1. Back" << endl;

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
            preport();
            break;
        case 2:
            bydefault = maketest();
            cout << "Default test created successfully." << endl;
            break;
        case -1:
            return;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    }
}

int main()
{
    while (true)
    {
        pl();
        cout << "1. Student" << endl;
        cout << "2. Company" << endl;
        cout << "3. Admin" << endl;
        cout << "-1. Exit" << endl;
        pl();

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
            studentmenu();
            break;
        case 2:
            companymenu();
            break;
        case 3:
            adminmenu();
            break;
        case -1:
            cout << "Exiting..." << endl;
            return 0;
        default:
            cout << "Invalid choice. Try again." << endl;
        }
    }
}
