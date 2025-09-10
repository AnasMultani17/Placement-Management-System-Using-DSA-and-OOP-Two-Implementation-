#pragma once

#include <string>
#include "../objs/User.h"

class CompanySignup : public User {
private:
    std::string username;
    std::string password;

public:
    CompanySignup(const std::string &username, const std::string &password);
    void saveToFile(const std::string &filename);
};


