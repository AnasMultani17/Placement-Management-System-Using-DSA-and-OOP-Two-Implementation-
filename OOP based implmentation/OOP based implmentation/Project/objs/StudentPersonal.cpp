#include <string>
#include <iostream>
#include <fstream>
#include "StudentPersonal.h"

using namespace std;

StudentPersonal::StudentPersonal(const string &name, int age, const string &gender, const string &address, const string &hobby)
{
    this->name = name;
    this->age = age;
    this->gender = gender;
    this->address = address;
    this->hobby = hobby;
}

string StudentPersonal::getName() const
{
    return name;
}

int StudentPersonal::getAge() const
{
    return age;
}

string StudentPersonal::getGender() const
{
    return gender;
}

string StudentPersonal::getAddress() const
{
    return address;
}

string StudentPersonal::getHobby() const
{
    return hobby;
}

void StudentPersonal::writeToCSV(ofstream &csv)
{
    csv << name << "," << age << "," << gender << "," << address << "," << hobby << "\n";
}