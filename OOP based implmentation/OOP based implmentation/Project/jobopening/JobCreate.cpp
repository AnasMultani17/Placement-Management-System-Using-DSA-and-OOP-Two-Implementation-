#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "JobCreate.h"

using namespace std;

JobCreate::JobCreate(int jobid, string jobname, string jobdetails, float mintest, int offeredctc)
{
    this->jobid = jobid;
    this->jobname = jobname;
    this->jobdetails = jobdetails;
    this->mintest = mintest;
    this->offeredctc = offeredctc;
    saveJobDetails();
}

void JobCreate::applyToJob(int jobid1, const string &rollNumber)
{
    ofstream writer("resources/JobApplications.txt", ios_base::app);
    if (!writer.is_open())
    {
        cerr << "Error opening file: JobApplications.txt" << endl;
        return;
    }
    writer << jobid1 << ":" << rollNumber << "\n";
    cout << "===============================================================" << endl;
    cout << "Application saved successfully." << endl;
    cout << "===============================================================" << endl;
    writer.close();
}

void JobCreate::dispDetail(int jobid)
{
    vector<string> applicants;
    ifstream reader("resources/JobApplications.txt");
    if (!reader.is_open())
    {
        cout << "===============================================================" << endl;
        cout << "An error occurred while reading the JobApplications file." << endl;
        cout << "===============================================================" << endl;
        return;
    }
    string line;
    while (getline(reader, line))
    {
        stringstream ss(line);
        string jobIdInFile, rollNumber;
        getline(ss, jobIdInFile, ':');
        getline(ss, rollNumber);
        if (!jobIdInFile.empty() && stoi(jobIdInFile) == jobid)
        {
            applicants.push_back(rollNumber);
        }
    }
    reader.close();

    if (applicants.empty())
    {
        cout << "===============================================================" << endl;
        cout << "No applicants found for Job ID " << jobid << endl;
        cout << "===============================================================" << endl;
        return;
    }

    ifstream studentReader("resources/StudentDetails.txt");
    if (!studentReader.is_open())
    {
        cout << "===============================================================" << endl;
        cout << "An error occurred while reading the StudentDetails file." << endl;
        cout << "===============================================================" << endl;
        return;
    }

    while (getline(studentReader, line))
    {
        for (const string &rollNumber : applicants)
        {
            if (line.rfind(rollNumber, 0) == 0)
            {
                stringstream ss(line);
                vector<string> details;
                string item;
                while (getline(ss, item, ','))
                {
                    details.push_back(item);
                }
                if (details.size() >= 5)
                {
                    cout << "===============================================================" << endl;
                    cout << "Roll Number: " << details[0] << endl;
                    cout << "CGPA: " << details[1] << endl;
                    cout << "Test Score: " << details[2] << endl;
                    cout << "Skills: " << details[3] << endl;
                    cout << "Expected CTC: " << details[4] << endl;
                    cout << endl;
                    cout << "===============================================================" << endl;
                }
                else
                {
                    cout << "===============================================================" << endl;
                    cout << "Incomplete data for roll number: " << rollNumber << endl;
                    cout << "===============================================================" << endl;
                }
            }
        }
    }
    studentReader.close();
}

void JobCreate::shortlistStudents(int jobId, int n)
{
    ofstream writer("resources/shortlisted.txt", ios_base::app);
    if (!writer.is_open())
    {
        cerr << "An error occurred while writing to the shortlisted file." << endl;
        return;
    }
    writer << "Job ID: " << jobId << "\n";
    writer << "Shortlisted Students: \n";
    cout << "===============================================================" << endl;
    for (int i = 0; i < n; i++)
    {
        string rollNumber;
        cout << "Enter Roll Number for Student " << (i + 1) << ": ";
        cin >> rollNumber;
        writer << rollNumber << "\n";
    }
    cout << "===============================================================" << endl;
    writer << "\n";
    cout << "===============================================================" << endl;
    cout << "Students shortlisted successfully." << endl;
    cout << "===============================================================" << endl;
    writer.close();
}

void JobCreate::viewShortlisted(int jobId)
{
    ifstream reader("resources/shortlisted.txt");
    if (!reader.is_open())
    {
        cerr << "An error occurred while reading the shortlisted file." << endl;
        return;
    }
    string line;
    bool jobFound = false;

    while (getline(reader, line))
    {
        if (line.rfind("Job ID: " + to_string(jobId), 0) == 0)
        {
            jobFound = true;
            cout << "===============================================================" << endl;
            cout << "----- Shortlisted Students for Job ID: " << jobId << " -----" << endl;
            cout << line << endl;
            while (getline(reader, line) && !line.empty())
            {
                cout << line << endl;
            }
            cout << "===============================================================" << endl;
            break;
        }
    }
    reader.close();

    if (!jobFound)
    {
        cout << "===============================================================" << endl;
        cout << "No shortlisted students found for Job ID " << jobId << endl;
        cout << "===============================================================" << endl;
    }
}

void JobCreate::hireStudent(int jobId, const string &rollNumber, double ctc)
{
    ofstream writer("resources/hiredStudents.txt", ios_base::app);
    if (!writer.is_open())
    {
        cerr << "An error occurred while writing to the hired students file." << endl;
        return;
    }
    writer << "Job ID: " << jobId << " - Hired Roll Number: " << rollNumber << " - CTC: " << ctc << "\n";
    cout << "===============================================================" << endl;
    cout << "Student " << rollNumber << " has been hired for Job ID " << jobId << " with CTC: " << ctc << endl;
    cout << "===============================================================" << endl;
    writer.close();
}

void JobCreate::saveJobDetails()
{
    ofstream writer("resources/JobOpenings.txt", ios_base::app);
    if (!writer.is_open())
    {
        cerr << "Error opening file: JobOpenings.txt" << endl;
        return;
    }
    writer << "Minimum Test Score: " << mintest << "\n";
    writer << "Job ID: " << jobid << "\n";
    writer << "Job Title: " << jobname << "\n";
    writer << "Description: " << jobdetails << "\n";
    writer << "Salary: " << offeredctc << "\n";
    writer << "\n";
    writer.close();
}