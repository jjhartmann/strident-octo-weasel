//////////////////////////////////////////////////////////////////////
// Excel Sheet COlumn Number
//
// Given a column title as appear in an Excel sheet, return its corresponding column number.
//
// For example :
//
// A -> 1
// B -> 2
// C -> 3
// ...
// Z -> 26
// AA -> 27
// AB -> 28


#include <iostream>

using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int len = s.length();
        if (len < 1) return 0;

        // convert to uppercase
        for (int i = 0; i < len; ++i)
        {
            s[i] = toupper(s[i]);
        }

        int ret = 0;
        for (int i = 0; i < len - 1; ++i)
        {
            ret += pow(26, ((len - 1) - i)) * ((s[i] - 'A') + 1);
        }

        ret += s[len - 1] - 'A' + 1;


        return ret;
    }

};

int main()
{
    cout << "Excel Sheet Column Number" << endl;
    Solution sol;
    string str = "AA";
    sol.titleToNumber("AA");



    return 0;
}

