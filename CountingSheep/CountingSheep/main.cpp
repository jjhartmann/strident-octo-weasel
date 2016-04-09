/////////////////////////////////////////////////////////////////////
// Counting Sheep

#include <iostream>
#include <fstream>
#include <string>


#define MAX_RUN 1000

using namespace std;

int main()
{
    ifstream file("A-small-attempt1.in");
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


        if (N != 0)
        {
            for (int j = 0; j < MAX_RUN; ++j)
            {

            }

        }

        
        cout << N << "\tCase #" << i << ": ";
        if (res > 0)
        {
             cout << res << endl;
        }
        else
        {
            cout << "INSOMNIA" << endl;
        }
    }
    
    file.close();
    return 0;
}