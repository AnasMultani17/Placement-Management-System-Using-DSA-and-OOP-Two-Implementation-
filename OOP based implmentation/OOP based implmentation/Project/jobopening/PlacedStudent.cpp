#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "PlacedStudent.h"

using namespace std;

void PlacedStudent::genReport()
{
        ifstream reader("resources/hiredStudents.txt");
        if (!reader.is_open())
        {
            cout << "An error occurred while reading the file: hiredStudents.txt" << endl;
            return;
        }
        string line;
        cout << "===============================================================" << endl;
        cout << "----- Placed Students Report -----" << endl;

        while (getline(reader, line))
        {
            stringstream ss(line);
            string part;
            vector<string> details;
            while (getline(ss, part, '-'))
            {
                details.push_back(part);
            }

            if (details.size() >= 3)
            {
                string jobId = details[0].substr(details[0].find(':') + 1);
                string rollNumber = details[1].substr(details[1].find(':') + 1);
                string ctc = details[2].substr(details[2].find(':') + 1);

                // Trim leading/trailing spaces
                size_t first = jobId.find_first_not_of(" \t\n\r");
                size_t last = jobId.find_last_not_of(" \t\n\r");
                if (string::npos != first && string::npos != last)
                {
                    jobId = jobId.substr(first, (last - first + 1));
                }
                first = rollNumber.find_first_not_of(" \t\n\r");
                last = rollNumber.find_last_not_of(" \t\n\r");
                if (string::npos != first && string::npos != last)
                {
                    rollNumber = rollNumber.substr(first, (last - first + 1));
                }
                first = ctc.find_first_not_of(" \t\n\r");
                last = ctc.find_last_not_of(" \t\n\r");
                if (string::npos != first && string::npos != last)
                {
                    ctc = ctc.substr(first, (last - first + 1));
                }

                cout << "Job ID: " << jobId << " || Roll Number: " << rollNumber << " || CTC: " << ctc << endl;
            }
            else
            {
                cout << "Invalid entry found in the file: " << line << endl;
            }
        }
        reader.close();
        cout << "----- End of Report -----" << endl;
        cout << "===============================================================" << endl;
}