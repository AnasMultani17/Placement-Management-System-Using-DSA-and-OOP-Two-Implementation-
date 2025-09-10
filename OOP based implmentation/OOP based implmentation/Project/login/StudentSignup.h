#pragma once

#include <string>
#include "../objs/User.h"

class StudentSignup : public User {
private:
    std::string rollNum;
    std::string course;

public:
    StudentSignup(const std::string &rollNum, const std::string &course, const std::string &username, const std::string &password);
    std::string getRollNum() const;
    std::string getCourse() const;
};


