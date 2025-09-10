#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "JobShow.h"

using namespace std;

void JobShow::availableJob(const string &rollNum)
{
        string ans1 = "";
        bool jobFound = false;

        ifstream studentReader("resources/StudentTest.txt");
        if (!studentReader.is_open())
        {
            cout << "An error occurred while reading the StudentTest file." << endl;
            return;
        }

        string line;
        while (getline(studentReader, line))
        {
            size_t pos = line.find(':');
            if (pos != string::npos)
            {
                string key = line.substr(0, pos);
                if (key.find(rollNum) != string::npos)
                {
                    ans1 = line.substr(pos + 1);
                    // Trim whitespace
                    size_t first = ans1.find_first_not_of(" \t\n\r");
                    size_t last = ans1.find_last_not_of(" \t\n\r");
                    if (string::npos != first && string::npos != last)
                    {
                        ans1 = ans1.substr(first, (last - first + 1));
                    }
                    break;
                }
            }
        }
        studentReader.close();

        if (ans1.empty())
        {
            cout << "===============================================================" << endl;
            cout << "Roll number not found or score is missing." << endl;
            cout << "===============================================================" << endl;
            return;
        }

        ifstream jobReader("resources/JobOpenings.txt");
        if (!jobReader.is_open())
        {
            cout << "An error occurred while reading the JobOpenings file." << endl;
            return;
        }

        string ans = "";
        cout << "===============================================================" << endl;
        while (getline(jobReader, line))
        {
            if (line.rfind("Minimum Test Score: ", 0) == 0)
            {
                ans = line.substr(string("Minimum Test Score: ").length());
                size_t first = ans.find_first_not_of(" \t\n\r");
                size_t last = ans.find_last_not_of(" \t\n\r");
                if (string::npos != first && string::npos != last)
                {
                    ans = ans.substr(first, (last - first + 1));
                }
            }
            if (!ans.empty())
            {
                try
                {
                    if (stof(ans) <= stof(ans1))
                    {
                        cout << line << endl;
                        jobFound = true;
                    }
                }
                catch (const exception &e)
                {
                    // Handle conversion error if needed
                }
            }
        }
        jobReader.close();
        cout << "===============================================================" << endl;

        if (!jobFound)
        {
            cout << "===============================================================" << endl;
            cout << "No job available for you." << endl;
            cout << "===============================================================" << endl;
        }
}