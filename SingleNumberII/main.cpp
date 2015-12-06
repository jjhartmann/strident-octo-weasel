#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int sum = 0;

        // Iterate through vector over all integers.
        for (int num : nums)
        {
            string base3 = converttoBase3(num);

            // Sum all the numbers of base3 together
            int j = base3.size();
            for (int i = 0; i < base3.size(); ++i, --j)
            {
                sum += stringToNumber<int>(base3.substr(i, 0)) * 10 * j;
            }
        }

        // Take % 3 for every digit in sum.
        string tmp = numbertoString<int>(sum);
        string res;
        for (int i = 0; i < tmp.size(); ++i)
        {
            res = numbertoString<int>(stringToNumber<int>(tmp.substr(i, 0)) % 3) + res;
        }

        // Convert res back to base 10;




    }

private:
    // Convert base 3 to base 10;
    template <typename T>
    T convertToBase10(string str)
    {
        int res = 0;
        int j = str.size() - 1;
        for (int i = 0; i < str.size(); ++i, --j)
        {
            res = stringToNumber<int>(str.substr(i, 0)) * 3 ^ j;
        }
    }

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