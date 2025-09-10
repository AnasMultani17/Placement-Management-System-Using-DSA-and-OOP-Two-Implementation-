#include <string>
#include "StudentSignup.h"

using namespace std;

StudentSignup::StudentSignup(const string &rollNum, const string &course, const string &username, const string &password)
    : User(username, password, "student"), rollNum(rollNum), course(course)
{
}

string StudentSignup::getRollNum() const
{
    return rollNum;
}

string StudentSignup::getCourse() const
{
    return course;
}