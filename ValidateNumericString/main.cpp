#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    bool isNumber(string s)
    {
        if (s.empty())
            return false;

        // Get initial state
        switch (getType(s[0]))
        {
            case 0:
            {
                state = 0;
                break;
            }
            case 1:
            {
                state = 1;
                break;
            }
            case 2:
            {
                state = 2;
                break;
            }
            case 3:
            {
                state = 3;
                break;
            }
            default:
            {
                return false;
            }

        }

        // Loop over string until end
        char c = 0;
        for (int i = 1; i < s.length(), c = s[i]; ++i)
        {
            int currentType = getType(c);

          
        }

    }


private:
    // Returns the number associated with the type:
    //      0: Space
    //      1: Decimal Point
    //      2: Pos/Neg
    //      3: Integer
    //      4: e
    int getType(char c)
    {
        if (isBlank(c))
            return 0;

        if (isDecimal(c))
            return 1;

        if (isSign(c))
            return 2;

        if (isInteger(c))
            return 3;

        if (isE(c))
            return 4;
    }

    // check if c is an integer
    bool isInteger(char c)
    {
        return  c == '0' ||
                c == '1' ||
                c == '2' ||
                c == '3' ||
                c == '4' ||
                c == '5' ||
                c == '6' ||
                c == '7' ||
                c == '8' ||
                c == '9';
    }

    // check if c is a blank space.
    bool isBlank(char c)
    {
        return c == ' ';
    }

    // check if c is a decimal point
    bool isDecimal(char c)
    {
        return c == '.';
    }

    // check if c is the positive or negitive sign.
    bool isSign(char c)
    {
        return c == '-' || c == '+';
    }

    // check for e
    bool isE(char c)
    {
        return c == 'e';
    }

    ///////////////////////////////////////////
    // Private Vars.
    int state;

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