#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Solution
{
public:
    static string compress(string str)
    {
        string res;
        char cprev = '\0';
        int count = 0;

        for (char c : str)
        {
            if (c != cprev)
            {
                if (cprev != '\0')
                {
                    res += cprev;
                    res += cito(count);
                }

                cprev = c;
                count = 0;
            }

            count++;
        }

        // Last character
        res += cprev;
        res += cito(count);

        // check which string is longer
        if (res.length() < str.length())
        {
            return res;
        }

        return str;
    }

private:
    static string cito(int i)
    {
        ostringstream convert;
        convert << i;
        return convert.str();
    }
};

int main()
{
    cout << "String Compresion" << endl;
    Solution::compress("aaaaaaaaaabbcdbbbbbbbbbbbbbbbbbbbbbbbb");
    return 0;
}