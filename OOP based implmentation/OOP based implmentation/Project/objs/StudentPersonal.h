#pragma once

#include <string>
#include <fstream>

class StudentPersonal {
private:
    std::string name;
    int age;
    std::string gender;
    std::string address;
    std::string hobby;

public:
    StudentPersonal(const std::string &name, int age, const std::string &gender, const std::string &address, const std::string &hobby);
    std::string getName() const;
    int getAge() const;
    std::string getGender() const;
    std::string getAddress() const;
    std::string getHobby() const;
    void writeToCSV(std::ofstream &csv);
};


