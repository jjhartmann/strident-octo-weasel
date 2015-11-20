#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    bool isNumber(string s)
    {
        decimal = 0;
        expo = 0;
        count = 0;
        len = s.length() - 1;
        intcount = 0;
        neg = 0;
        pos = 0;
        deciFirst = false;
        char next;
        char prev;

        int lindex = 0;
        int rindex = len;
        bool boundsfound = false;
        while (!boundsfound)
        {
            if (s[lindex] == ' ')
            {
                ++lindex;
            }

            if (s[rindex] == ' ')
            {
                --rindex;
            }

            if (s[lindex] != ' ' && s[rindex] != ' ')
            {
                boundsfound = true;
            }
        }

        if (lindex > rindex)
        {
            return false;
        }

        count = lindex;
        firsti = lindex;
        for (int i = lindex; i <= rindex; ++i)
        {
            if (s.length()-1 >= count+1)
            {
                next = s[count + 1];
            }
            else
            {
                next = 0;
            }

            if (!IsNumericOrE(s[i], prev, next))
                return false;

            ++count;
            prev = s[i];
        }

        return true;
    }

    bool IsNumericOrE(char c, char p, char s)
    {
        if (IsNumeric(c))
        {
            return true;
        }

        if (intcount == 0 && decimal > 0)
        {
            return false;
        }

        if (c == '.' && decimal == 0 && expo == 0 && len > 0 && (intcount > 0 || IsNumeric(s) || s == 'e'))
        {
            if (firsti == count || p == '-' || p == '+')
            {
                deciFirst = true;
            }
            ++decimal;
            return true;
        }

        if (c == 'e' && expo == 0 && (decimal == 0 || p == '.' || deciFirst) && len > 0 && intcount > 0 && IsNumeric(s))
        {
            ++expo;
            return true;
        }

        if (c == '-' && neg == 0 && len > 0 && intcount == 0 && (IsNumeric(s) || s == '.'))
        {
            ++neg;
            return true;
        }

        if (c == '+' && pos == 0 && len > 0 && intcount == 0 && (IsNumeric(s) || s == '.'))
        {
            ++pos;
            return true;
        }

        if (c == ' ' && count == 0 && len > 0)
            return true;

        if (c == ' ' && count == len && len > 0 && intcount > 0)
            return true;



        return false;

    }

    bool IsNumeric(char c)
    {
        if (
                c == '0' ||
                c == '1' ||
                c == '2' ||
                c == '3' ||
                c == '4' ||
                c == '5' ||
                c == '6' ||
                c == '7' ||
                c == '8' ||
                c == '9'
                )
        {
            ++intcount;
            return true;
        }

        return false;
    }

private:
    int decimal;
    int intcount;
    int expo;
    int count;
    int len;
    int neg;
    int pos;
    int firsti;
    bool deciFirst;
};

int main()
{
    Solution sol;
    string test = "-.125e33";
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

    return 0;
}