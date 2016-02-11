//////////////////////////////////////////////////////////////
// Main - Compute all string permutations

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    static vector<string> PrintAllPermutations(string str)
    {
        if (str.length() == 1)
        {
            vector<string> tmp(1, str);
            return tmp;
        }

        // Recurse string 
        vector<string> substrings = PrintAllPermutations(str.substr(0, str.length() - 1));

        // iterate through substrings and interweave next result. 
        int sStringSize = substrings.size();
        vector<string> newSubstrings;
        string element = str.substr(str.length() - 1, 1);
        for (int i = 0; i < sStringSize; ++i)
        {
            string tmpSubstr = substrings[i];
            int strSize = tmpSubstr.length();

            for (int j = 0; j < strSize + 1; ++j)
            {
                string lstr = (j == 0) ? "" : tmpSubstr.substr(0,j);
                string rstr = (j == strSize) ? "" : tmpSubstr.substr(j, tmpSubstr.length());

                newSubstrings.push_back(lstr + element + rstr);
            }
        }

        return newSubstrings;
    }
};

int main()
{
    cout << "Compute all permutations of a string" << endl;
    string srt =  "abcd12";
    vector<string> res = Solution::PrintAllPermutations(srt);


    return 0;
}