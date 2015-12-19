#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool isPermutationSort(string str1, string str2)
    {
        if (str1.length() != str2.length()) return false;

        // Sort the strings
        sortString(str1);
        sortString(str2);

        // Check to see if strings are equal.
        for (int i = 0; i < str1.length(); ++i)
        {
            if (str1[i] != str2[i])
            {
                return false;
            }
        }

        return true;
    }

    bool isPermutation(string str1, string str2)
    {
        if (str1.length() != str2.length()) return false;

        vector<int> charmap(256); // Assuming that the strings are composed of ASCII
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

private:
    void sortString(string &str)
    {
        sort(str.begin(), str.end());
    }
};

int main()
{
    cout << "Check to see if two strings are permuations of eachother." << endl;

    Solution sol;
//    sol.isPermutation("abbede", "beedba");
    sol.isPermutationSort("abbede", "beedba");

    return 0;
}