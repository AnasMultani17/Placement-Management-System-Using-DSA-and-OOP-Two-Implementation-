#pragma once

#include <string>
#include "../login/CompanySignup.h"

class Company : public CompanySignup {
private:
    std::string name;
    std::string location;
    std::string type;
    int minCtc;
    int maxCtc;

public:
    Company(const std::string &username, const std::string &password, const std::string &name, const std::string &location, const std::string &type, int minCtc, int maxCtc);
    std::string getName() const;
    std::string getLocation() const;
    std::string getType() const;
    int getMinCtc() const;
    int getMaxCtc() const;
};


