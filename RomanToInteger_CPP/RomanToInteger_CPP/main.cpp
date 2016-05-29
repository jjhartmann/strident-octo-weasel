//////////////////////////////////////////////////////
// Roman to Integer
//
// Given a roman numeral, convert it to an integer.
//
// Input is guaranteed to be within the range from 1 to 3999.

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int max = 1;
        int res = 0;
        for (int i = s.length() - 1; i >= 0; --i)
        {
            int val = convert(toupper(s[i]));
            if (val < max)
            {
                res -= val;
            }
            else
            {
                res += val;
            }

            max = val > max ? val : max;
        }

        return res;

    }

    int convert(char c)
    {
        if (c == 'I')
        {
            return 1;
        }
        else if (c == 'V')
        {
            return 5;
        }
        else if (c == 'X')
        {
            return 10;
        }
        else if (c == 'L')
        {
            return 50;
        }
        else if (c == 'C')
        {
            return 100;
        }
        else if (c == 'D')
        {
            return 500;
        }
        else if (c == 'M')
        {
            return 1000;
        }
        
        
        return -1;
    }
};

int main()
{
    cout << "Roman to Integer" << endl;
    Solution sol;
    string test = "DCXXIIV";

    int ret = sol.romanToInt(test);




    return 0;
}
