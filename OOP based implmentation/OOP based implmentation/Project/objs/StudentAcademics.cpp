#include <iostream>
#include <fstream>
#include <string>
#include "StudentAcademics.h"
#include "../test/mcqs.h"

using namespace std;

void StudentAcademics::writeToStudentDetailsFile()
{
        ofstream writer("resources/StudentDetails.txt", ios_base::app);
        if (!writer.is_open())
        {
            cout << "An error occurred while writing to StudentDetails.txt." << endl;
            return;
        }
        writer << this->rollNum << "," << this->cgpa << "," << this->testScore << "," << this->skills << "," << this->expectedCTC << "\n";
        writer.close();
}

void StudentAcademics::writeToStudentTestFile()
{
        ofstream writer("resources/StudentTest.txt", ios_base::app);
        if (!writer.is_open())
        {
            cout << "An error occurred while writing to StudentTest.txt." << endl;
            return;
        }
        writer << this->rollNum << ":" << this->testScore << "\n";
        writer.close();
}

void StudentAcademics::writeToCSV()
{
        ofstream writer("resources/StudentAca.csv", ios_base::app);
        if (!writer.is_open())
        {
            cout << "An error occurred while writing to StudentAca.csv." << endl;
            return;
        }
        writer << this->rollNum << "," << this->cgpa << "," << this->testScore << "," << this->skills << "," << this->expectedCTC << "\n";
        writer.close();
}

StudentAcademics::StudentAcademics(const string &rollNum, float cgpa, const string &skills, float expectedCTC)
{
    this->rollNum = rollNum;
    this->cgpa = cgpa;
    this->skills = skills;
    this->expectedCTC = expectedCTC;
    this->testScore = MCQs::giveTest();

    writeToStudentDetailsFile();
    writeToStudentTestFile();
    writeToCSV();
}

string StudentAcademics::getRollNum() const
{
    return rollNum;
}

float StudentAcademics::getTestScore() const
{
    return testScore;
}

float StudentAcademics::getCgpa() const
{
    return cgpa;
}

string StudentAcademics::getSkills() const
{
    return skills;
}

float StudentAcademics::getExpectedCTC() const
{
    return expectedCTC;
}