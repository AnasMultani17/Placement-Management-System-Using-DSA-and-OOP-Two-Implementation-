#include <iostream>
#include <fstream>
#include <string>
#include "CompanySignup.h"

using namespace std;

CompanySignup::CompanySignup(const string &username, const string &password)
    : User(username, password, "company"), username(username), password(password)
{
}

void CompanySignup::saveToFile(const string &filename)
{
    ofstream writer(filename, ios_base::app);
    if (!writer.is_open())
    {
        cout << "===============================================================" << endl;
        cout << "An error occurred while saving company signup details." << endl;
        cout << "===============================================================" << endl;
        return;
    }

    writer << "UserType: " << this->userType << ", Username: " << this->username << ", Password: " << this->password << "\n";
    cout << "===============================================================" << endl;
    cout << "Company signup details saved successfully." << endl;
    cout << "===============================================================" << endl;
    writer.close();
}