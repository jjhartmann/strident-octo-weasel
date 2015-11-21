#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    bool isNumber(string s)
    {

    }
};

int main()
{
    Solution sol;
    string test = "+42e+76125";
    sol.isNumber(test);

    vector<bool> resultarray;

    fstream file("testcases.txt");

    string line;
    while(getline(file, line))
    {
        stringstream stream(line);

        string test;
        getline(stream, test, '\t');

        string result;
        getline(stream, result);

        bool res = sol.isNumber(test);

        if (res)
        {
            resultarray.push_back(true);
        }
        else
        {
            resultarray.push_back(false);
        }

        cout << line << endl;
        cout << test << endl;
        cout << result << endl;

    }

    cout << "FINISH" << endl;
    return 0;
}