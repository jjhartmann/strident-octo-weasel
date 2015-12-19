#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isPermutation(string str1, string str2)
    {
        vector<int> charmap(256);
        for (char c : str1)
        {
            ++charmap[(int) c];
        }

        for (char c : str2)
        {
            if (!charmap[(int) c]) return false;
            --charmap[(int) c];
        }

        return true;
    }
};

int main()
{
    cout << "Check to see if two strings are permuations of eachother." << endl;

    Solution sol;
    sol.isPermutation("abbede", "beedba");

    return 0;
}