#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void reverse(char *str)
    {
        char *stringiter = str;
        vector<char> strtemp;
        while(*(stringiter))
        {
            strtemp.push_back(*stringiter);
            stringiter++;
        }

        for (int i = strtemp.size() - 1, j = 0; i >= 0; --i, ++j)
        {
            str[j] = strtemp[i];
        }
    }
};

int main()
{
    cout << "Reverse Null Terminated String" << endl;

    Solution sol;
    char testStr[] = "What time is it?";
    sol.reverse(testStr);
    return 0;
}