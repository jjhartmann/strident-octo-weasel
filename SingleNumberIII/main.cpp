#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> mapint;

        // Iterate over nums and find duplicate ints
        int numsSize = nums.size();
        for (int i = 0; i < numsSize; ++i)
        {
            pair<unordered_map<int, int>::iterator, bool> pairItr = mapint.insert(make_pair(nums[i], i));

            if (!pairItr.second)
            {
                mapint.erase(pairItr.first);

            }
        }

        vector<int> res;
        for (auto itr : mapint)
        {
            res.push_back(itr.first);
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
    sol.singleNumber(test);

    // Test find single number
    Solution2 sol2;
    vector<int> test2 = {1, 1, 2, 3, 4, 3, 2, 4, 5, 6, 5, 12, 6, 7, 8, 9, 8, 7, 9 };
    int singleNum = sol2.findSingleNumber(test2);

    cout << "FINISH" << endl;
    return 0;
}