/////////////////////////////////////////////////////////////////////
// House of Pancakes

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define MAX_RUN 1000

using namespace std;

int lenofNum(int x)
{
    int count = 0;
    while (x > 0)
    {
        x = floor(x / 2);
        count++;
    }

    return count;
}

int main()
{
    ofstream ofilet("test.txt");
    int K = 255;
    int C = 2;
    int length = lenofNum(K);
    for (int i = 0; i <= K; i++)
    {
        string org;
        string gorg;
        int num = i;
        for (int j = 0; j < length; ++j)
        {
            int val = num % 2;
            if (val)
            {
                org = 'G' + org;
            }
            else
            {
                org = 'L' + org;
            }

            gorg += 'G';
            num = floor(num / 2);
        }
        
        num = i;
        string res;
        for (int j = 1; j < C; ++j)
        {
            for (int k = 0; k < length; ++k)
            {
                int val = num % 2;
                if (val)
                {
                    res = gorg + res;
                }
                else
                {
                    res = org + res;
                }

                num = floor(num / 2);
            }
        }

        ofilet << res << endl;

    }
    ofilet.close();

     


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