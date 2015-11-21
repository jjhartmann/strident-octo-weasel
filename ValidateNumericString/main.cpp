#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    Solution() :
        stateMatrix(55, -1)
    {
        // create StateType Map row = = 11 and col = 5
        //State 0
        stateMatrix[0*5 + 0] = 0;
        stateMatrix[0*5 + 1] = 1;
        stateMatrix[0*5 + 2] = 2;
        stateMatrix[0*5 + 3] = 3;

        // State 1
        stateMatrix[1*5 + 3] = 4;

        // State 2
        stateMatrix[2*5 + 1] = 1;
        stateMatrix[2*5 + 3] = 3;

        // State 3
        stateMatrix[3*5 + 0] = 10;
        stateMatrix[3*5 + 1] = 5;
        stateMatrix[3*5 + 3] = 3;
        stateMatrix[3*5 + 4] = 6;

        // State 4
        stateMatrix[4*5 + 0] = 10;
        stateMatrix[4*5 + 3] = 4;
        stateMatrix[4*5 + 4] = 6;

        // State 5
        stateMatrix[5*5 + 0] = 10;
        stateMatrix[5*5 + 3] = 9;
        stateMatrix[5*5 + 4] = 6;

        // State 6
        stateMatrix[6*5 + 2] = 7;
        stateMatrix[6*5 + 3] = 8;

        // State 7
        stateMatrix[7*5 + 3] = 8;

        // State 8
        stateMatrix[8*5 + 0] = 10;
        stateMatrix[8*5 + 3] = 8;

        // State 9
        stateMatrix[9*5 + 0] = 10;
        stateMatrix[9*5 + 3] = 9;
        stateMatrix[9*5 + 4] = 6;

        // State 10
        stateMatrix[10*5 + 0] = 10;

    }

    // Main Algorithm
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
            // Get the type of character identifier
            int currentType = getType(c);

            // if Invalid Type return false
            if (currentType == -1)
                return false;

            // Get next state
            int nextState = stateMatrix[state * 5 + currentType];

            // return false if next state is invalid
            if (nextState == -1)
            {
                return false;
            }

            // Set the next state as current
            state = nextState;
        }

        // Check it state is exit valid state
        if (isExitState(state))
            return true;

        return false;
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

        // Default
        return -1;
    }

    // Check if state is a valid exit state. 
    bool isExitState(int in_state)
    {
        return in_state == 3 ||
               in_state == 4 ||
               in_state == 5 ||
               in_state == 8 ||
               in_state == 9 ||
               in_state == 10;
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
    vector<int> stateMatrix;
    int state;

};

int main()
{
    Solution sol;
    string test = " T3";
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

    file.close();

    cout << "FINISH" << endl;
    return 0;
}