#pragma once

#include <string>

class StudentAcademics {
private:
    std::string rollNum;
    float cgpa;
    std::string skills;
    float expectedCTC;
    float testScore;

    void writeToStudentDetailsFile();
    void writeToStudentTestFile();
    void writeToCSV();

public:
    StudentAcademics(const std::string &rollNum, float cgpa, const std::string &skills, float expectedCTC);

    std::string getRollNum() const;
    float getTestScore() const;
    float getCgpa() const;
    std::string getSkills() const;
    float getExpectedCTC() const;
};


