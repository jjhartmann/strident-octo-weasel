#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        string sum;

        // Iterate through vector over all integers.
        for (int num : nums)
        {
            string base3 = converttoBase3(num);

            // Sum all the numbers of base3 together
            int j = base3.size() - 1;
            for (int i = 0; i < base3.size(); ++i, --j)
            {
                int x = stringToNumber<int>(base3.substr(i, 1)) * pow(10.0, j);

                if (sum.size() > i)
                {
                    int y = stringToNumber<int>(sum.substr(i, 1));

                    if (x + y < 10 && y != 0)
                    {
                        string str = numbertoString<int>(x + y);
                        sum.replace(i, i + str.size(), str);
                    }
                }
                else
                {
                    sum = numbertoString<int>(x) + sum;
                }
            }
        }

        // Take % 3 for every digit in sum.
        string res;
        for (int i = 0; i < sum.size(); ++i)
        {
            res = numbertoString<int>(stringToNumber<int>(sum.substr(i, 1)) % 3) + res;
        }

        // Convert res back to base 10;
        int base10 = convertToBase10<int>(res);

        return base10;



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
            res = stringToNumber<int>(str.substr(i, 1)) * 3 ^ j;
        }
    }

    // Convert int to a base 3 representation.
    string converttoBase3(int x)
    {
        string res;
        while (x > 0)
        {
            res = numbertoString<int>(x % 3) + res;
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