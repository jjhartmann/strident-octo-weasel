#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int sum = 0;
        


    }

private:
    // Convert int to a base 3 representation.
    string converttoBase3(int x)
    {
        string res;
        while (x > 0)
        {
            res = numbertoString(x % 3) + res;
            x = x / 3;
        }

        return res;
    }

    // Convert a number to string
    template <typename T>
    string numbertoString(T num)
    {
        ostringstream ss;
        ss << num;
        return ss.str();
    }

    // Convert a string to a number
    template <typename T>
    T stringToNumber(string str)
    {
        istringstream ss(str);
        T res;
        return ss >> res ? res : 0;
    }
};

int main()
{
    Solution sol;
    vector<int> test = {1,2,3,4,5,1,2,3,12,4,5,1,2,3,4,5,};

    // TEst
    sol.singleNumber(test);
    return 0;
}