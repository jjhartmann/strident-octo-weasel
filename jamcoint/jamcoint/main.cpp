/////////////////////////////////////////////////////////////////////
// House of Pancakes

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define MAX_RUN 1000

using namespace std;

int main()
{
    ifstream file("B-large.in");
    ofstream ofile("sol.txt");
    if (!file.is_open()) return 1;

    string line;
    getline(file, line);

    cout << "Input\tOutput\n" << endl;
    int trails = atoi(line.c_str());
    for (int i = 0; i < trails; ++i)
    {
        getline(file, line);
        int numberofFlips = 0;
        int NumofPancakes = line.length();
        vector<bool> stack(NumofPancakes, false);

        int happycnt = 0;
        for (int j = 0; j < NumofPancakes; ++j)
        {
            if (line[j] == '+')
            {
                stack[j] = true;
                happycnt++;
            }
        }

        bool happy = (happycnt == NumofPancakes);
        while (!happy)
        {
            happycnt = 0;
            for (int j = 0; j < NumofPancakes; ++j)
            {
                if (stack[j]) happycnt++;
            }

            if (happycnt == NumofPancakes)
            {
                happy = true;
            }
            else
            {
                int index = 0;
                bool topP = stack[0];
                while (index < NumofPancakes && stack[index] == topP)
                {
                    stack[index] = !stack[index];
                    index++;
                }

                if (index) numberofFlips++;
            }
        }



        cout << "Case #" << i + 1 << ": " << numberofFlips << endl;
        ofile << "Case #" << i + 1 << ": " << numberofFlips << endl;
    }

    file.close();
    return 0;
}