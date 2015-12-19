#include <iostream>

using namespace std;

static string WHITESPACE = "%20";

class Solution
{
public:
    static void replaceWhiteSpace(string &str)
    {
        for (int i = 0; i < str.length(); ++i)
        {
            if (str[i] == ' ')
            {
                str.replace(i, 1, WHITESPACE);
            }
        }
    }
};


int main()
{
    cout << "Replace string white space with %20" << endl;

    string teststr = "This is a test.";
    Solution::replaceWhiteSpace(teststr);
    return 0;
}