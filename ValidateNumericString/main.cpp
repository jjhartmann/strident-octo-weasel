#include <iostream>

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
        char next;

        int earselen = 0;
        for (int i = 1; i <= len; ++i)
        {
            if (s[i] == ' ')
            {

            }
            else
            {
                i = len + 1;
            }
        }

        for (char c : s)
        {
            if (s.length()-1 >= count+1)
            {
                next = s[count + 1];
            }
            else
            {
                next = 0;
            }

            if (!IsNumericOrE(c, next))
                return false;

            ++count;
        }

        return true;
    }

    bool IsNumericOrE(char c, char s)
    {
        if (IsNumeric(c))
        {
            return true;
        }

        if (intcount == 0 && decimal > 0)
        {
            return false;
        }

        if (c == '.' && decimal == 0 && expo == 0 && len > 0 && (intcount > 0 || IsNumeric(s)))
        {
            ++decimal;
            return true;
        }

        if (c == 'e' && expo == 0 && decimal == 0 && len > 0 && intcount > 0 && IsNumeric(s))
        {
            ++expo;
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
};

int main()
{
    Solution sol;
    string test = "                                             .";

    bool res = sol.isNumber(test);

    cout << res << endl;
    return 0;
}