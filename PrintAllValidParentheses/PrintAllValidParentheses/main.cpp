///////////////////////////////////////////////////////////////
// Main - Print all Valid Parentheses


#include <iostream>
#include <vector>

using namespace std;



class Solution
{
public:
    static vector<string> PrintAllValidParentheses(int npairs)
    {
        return PrintAllHelper(npairs);

    }


private:
    static vector<string> PrintAllHelper(int npairs)
    {
        if (npairs == 1)
        {
            vector<string> tmp(1, "()");
            return tmp;
        }

        vector<string> substrings = PrintAllHelper(npairs - 1);

        // Perpend, wrap and append all substings. 
        vector<string> resultStr;

        // perpend
        for (int j = 0; j < substrings.size(); ++j)
        {
            string tmp = "()" + substrings[j];
            resultStr.push_back(tmp);
        }

        // Wrap
        for (int j = 0; j < substrings.size(); ++j)
        {
            string tmp = "(" + substrings[j] + ")";
            resultStr.push_back(tmp);
        }

        // append except first
        for (int j = 1; j < substrings.size(); ++j)
        {
            string tmp = substrings[j] + "()";
            resultStr.push_back(tmp);
        }


        return resultStr;

    }
};



int main()
{
    cout << "Print all valid parentheses for n-pairs." << endl;
    vector<string> res = Solution::PrintAllValidParentheses(4);



    return 0;
}
