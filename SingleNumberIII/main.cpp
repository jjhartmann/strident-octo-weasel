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


    vector<int> generlizedFindSingleNumber(vector<int> nums, int n_numbers)
    {
        vector<int> xor_vec(n_numbers, 0);

        // Iterate through the number of single numbers and find differential xors.
        for (int i = 0; i < xor_vec.size(); ++i)
        {
            int andDiff = 0;
            // Iterate through each vector of numbers to determine differential xor
            for (int num : nums)
            {
                // flag to determine if number is part of a different xor set
                bool flag = false;
                for (int k = 0; k < i; ++k)
                {
                    if ((xor_vec[k] & num) != 0)
                    {
                        flag = true;
                        k = i;
                    }
                }

                // if number is not part of xor set, add to current set.
                if (!flag)
                {
                    xor_vec[i] ^= num;
//                    xor_vec[i] = strongxor(xor_vec[i], num, andDiff);
                }
            }

            // Create differential bit, to determine single number
            xor_vec[i] &= -xor_vec[i];
        }


        // Iterate through nums and find all sort using differential bits.
        vector<int> res(n_numbers, 0);
        for (int num : nums)
        {
            for (int i = 0; i < xor_vec.size(); ++i)
            {
                if ((xor_vec[i] & num) == 0)
                {
                    res[i] ^= num;
                }
            }
        }


        return res;
    }

    // Stronger XOR
    // Need to exclude any duplicate bits, odd or even.
    int strongxor(int i, int j, int &anddiff)
    {
        // Get the xor of i and j
        int xor_tmp = i ^ j;

        // set anddiff with new value
        anddiff |= i & j;

        // Then mask agains the ones complement of anddiff
        xor_tmp &= ~anddiff;


        return xor_tmp;

    }

private:

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
    vector<int> test3 = { 1, 2, 1, 3, 2, 5};
    sol.singleNumber(test3);

    // Test find single number
    Solution2 sol2;
    vector<int> test2 = {1, 1, 2, 3, 4, 3, 2, 4, 5, 6, 5, 12, 6, 7, 8, 9, 8, 7, 9 };
    int singleNum = sol2.findSingleNumber(test2);

    vector<int> test4 = { 1,2,1,2,3,4,5,4,6,7,6,7,9,10,8,8};
    sol.generlizedFindSingleNumber(test4, 4);

    cout << "FINISH" << endl;
    return 0;
}