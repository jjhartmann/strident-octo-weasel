#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // Find exactly two single numbers in a vector of duplicate numbers.
    vector<int> singleNumber(vector<int>& nums)
    {
        // First find the XOR of the two single numbers
        int xornum = 0;
        for (auto num : nums)
        {
            xornum ^= num;
        }

        // Then find single bit;
        int test = -xornum;
        xornum &= -xornum;

        // Get result use bit
        vector<int> res = {0, 0};
        for (auto num: nums)
        {
            if ((num & xornum) == 0)
            {
                res[0] ^= num;
            }
            else
            {
                res[1] ^= num;
            }
        }

        return res;

    }


};


class Solution2
{
public:
    int findSingleNumber(vector<int> nums)
    {
        // To find a single number in a string of duplicates.
        // There is only one number that has a single element, all others numbers come in pairs.
        // Can use XOR to find the single number. Using O(n) time and O(1) space

        int res = 0;
        for (auto i : nums)
        {
            res ^= i;
        }


        return res;

    }
};


int main()
{
    Solution sol;

    // Test Find two single numbers
    vector<int> test = { 1,2,1,2,3,4,5,4,6,7,6,7,9,8,8};
    vector<int> test3 = { 1, 2, 1, 3, 2, 5};
    sol.singleNumber(test3);

    // Test find single number
    Solution2 sol2;
    vector<int> test2 = {1, 1, 2, 3, 4, 3, 2, 4, 5, 6, 5, 12, 6, 7, 8, 9, 8, 7, 9 };
    int singleNum = sol2.findSingleNumber(test2);

    cout << "FINISH" << endl;
    return 0;
}