#include <iostream>
#include <fstream>
#include <string>
#include "UserLogin.h"

using namespace std;

bool UserLogin::validateLogin(const string &username, const string &password)
{
        ifstream reader("resources/usermanager.txt");
        if (!reader.is_open())
        {
            cout << "An error occurred while reading the file." << endl;
            return false;
        }

        string line;
        while (getline(reader, line))
        {
            size_t usernameEnd = line.find(':');
            if (usernameEnd == string::npos)
            {
                continue;
            }
            string usr = line.substr(0, usernameEnd);
            string psw = line.substr(usernameEnd + 1);

            if (username == usr && password == psw)
            {
                reader.close();
                return true;
            }
        }
        reader.close();
        return false;
}