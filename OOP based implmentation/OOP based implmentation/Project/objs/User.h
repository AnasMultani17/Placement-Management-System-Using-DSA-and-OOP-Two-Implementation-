#pragma once

#include <string>

class User {
protected:
    std::string username;
    std::string password;
    std::string userType;

public:
    User(const std::string &username, const std::string &password, const std::string &userType);
    void writeFile();
    std::string getUsername() const;
    void setUsername(const std::string &username);
    void setPassword(const std::string &password);
    std::string getUserType() const;
    std::string getPassword() const;
};


