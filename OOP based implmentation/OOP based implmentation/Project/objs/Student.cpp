#include <iostream>
#include <fstream>
#include <string>
#include "Student.h"
#include <limits>

using namespace std;

Student::Student(StudentSignup &signupDetails, StudentPersonal &personalDetails, StudentAcademics &academicDetails)
    : signupDetails(signupDetails), personalDetails(personalDetails), academicDetails(academicDetails)
{
}

void Student::saveAllDetailsToFile(const string &filename)
{
    ofstream writer(filename, ios_base::app);
    if (!writer.is_open())
    {
        cout << "An error occurred while saving student details." << endl;
        return;
    }

    writer << "Username: " << signupDetails.getUsername() << ", ";
    writer << "Password: " << signupDetails.getPassword() << ", ";
    writer << "Roll Number: " << signupDetails.getRollNum() << ", ";
    writer << "Course: " << signupDetails.getCourse() << "\n";

    writer << "Name: " << personalDetails.getName() << ", ";
    writer << "Age: " << personalDetails.getAge() << ", ";
    writer << "Gender: " << personalDetails.getGender() << ", ";
    writer << "Address: " << personalDetails.getAddress() << ", ";
    writer << "Hobby: " << personalDetails.getHobby() << "\n";

    writer << "CGPA: " << academicDetails.getCgpa() << ", ";
    writer << "Skills: " << academicDetails.getSkills() << ", ";
    writer << "Test Score: " << academicDetails.getTestScore() << ", ";
    writer << "Expected CTC: " << academicDetails.getExpectedCTC() << ", ";

    writer << "--------------------------------------------------\n";
    cout << "All student details saved successfully." << endl;
    writer.close();
}