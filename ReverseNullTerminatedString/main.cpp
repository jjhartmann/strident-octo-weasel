#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void reverse(char *str)
    {
        char *enditer = str;
        char tmp;
        // Find end
        while(*(enditer))
        {
            enditer++;
        }
        --enditer;

        // Swap and reverse
        while (str < enditer)
        {
            tmp = *str;
            *str = *enditer;
            *enditer = tmp;
            ++str;
            --enditer;
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