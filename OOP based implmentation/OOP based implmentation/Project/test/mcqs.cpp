#include <iostream>
#include <fstream>
#include <string>
#include "mcqs.h"

using namespace std;

float MCQs::giveTest()
{
        int score = 0;
        int totalQue = 0;

        ifstream reader("resources/dsa_mcq_placement_test.txt");
        if (!reader.is_open())
        {
            cout << "An error occurred while reading the file." << endl;
            return 0.0f;
        }

        string line;
        string ans = "";

        while (getline(reader, line))
        {
            if (!line.empty())
            {
                if (line.rfind("Answer:", 0) == 0)
                {
                    ans = line.substr(line.find(":") + 1);
                    size_t first = ans.find_first_not_of(" \t\n\r");
                    size_t last = ans.find_last_not_of(" \t\n\r");
                    if (string::npos != first && string::npos != last)
                    {
                        ans = ans.substr(first, (last - first + 1));
                    }
                    cout << "Give your answer: ";
                    string answer;
                    cin >> answer;

                    if (answer == ans)
                    {
                        score++;
                    }
                    totalQue++;
                }
                else
                {
                    cout << line << endl;
                }
            }
        }
        reader.close();

        return totalQue > 0 ? (static_cast<float>(score) * 100.0f / totalQue) : 0.0f;
}