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
    ifstream file("A-large.in");
    ofstream ofile("sol.txt");
    if (!file.is_open()) return 1;

    string line;
    getline(file, line);

    cout << "Input\tOutput\n" << endl;
    int trails = atoi(line.c_str());
    for (int i = 0; i < trails; ++i)
    {
        getline(file, line);
        int N = atoi(line.c_str());
        int res = -1;

        vector<bool> map(10, 0);
        int mapcount = 0;

        if (N != 0)
        {
            for (int j = 1; j < MAX_RUN; ++j)
            {

                int curr = j * N;
                res = curr;

                while (curr > 0)
                {
                    int index = curr % 10;
                    curr = floor(curr / 10);

                    if (!map[index])
                    {
                        map[index] = true;
                        mapcount++;
                    }
                }

                if (mapcount >= 10)
                {
                    break;
                }
            }
        }


        cout << "Case #" << i + 1 << ": ";
        ofile << "Case #" << i + 1 << ": ";
        if (res > 0)
        {
            cout << res << endl;
            ofile << res << endl;
        }
        else
        {
            cout << "INSOMNIA" << endl;
            ofile << "INSOMNIA" << endl;
        }
    }

    file.close();
    return 0;
}