#pragma once

#include <string>
#include "../login/StudentSignup.h"
#include "StudentPersonal.h"
#include "StudentAcademics.h"

class Student {
private:
    StudentSignup &signupDetails;
    StudentPersonal &personalDetails;
    StudentAcademics &academicDetails;

public:
    Student(StudentSignup &signupDetails, StudentPersonal &personalDetails, StudentAcademics &academicDetails);
    void saveAllDetailsToFile(const std::string &filename);
};


