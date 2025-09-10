#include <iostream>
#include <fstream>
#include <string>
#include "User.h"

using namespace std;

User::User(const string &username, const string &password, const string &userType)
{
    this->username = username;
    this->password = password;
    this->userType = userType;
    writeFile();
}

void User::writeFile()
{
    string filename = "resources/usermanager.txt";
    ofstream writer(filename, ios_base::app);
    if (!writer.is_open())
    {
        cout << "===============================================================" << endl;
        cout << "An error occurred while saving user credentials." << endl;
        cout << "===============================================================" << endl;
        return;
    }

    writer << getUsername() << ":" << getPassword() << "\n";
    cout << "===============================================================" << endl;
    cout << "User credentials saved successfully." << endl;
    cout << "===============================================================" << endl;
    writer.close();
}

string User::getUsername() const
{
    return username;
}

void User::setUsername(const string &username)
{
    this->username = username;
}

void User::setPassword(const string &password)
{
    this->password = password;
}

string User::getUserType() const
{
    return userType;
}

string User::getPassword() const
{
    return password;
}