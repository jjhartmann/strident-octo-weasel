//////////////////////////////////////////////////////////////////////
// Majority Element
//
// Given an array of size n, find the majority element.The majority element is the element that appears more than n / 2 times.
//
// You may assume that the array is non - empty and the majority element always exist in the array.

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> hmap;

        int size = nums.size();
        for (int i = 0; i < size; ++i)
        {
            hmap[nums[i]]++;

            if (hmap[nums[i]] > floor(size / 2))
            {
                return hmap[nums[i]];
            }
        }

        return 0;
    }
};

int main()
{
    vector<int> nums = { 2,3,4,3,2,2,2,2 };
    Solution sol;
    sol.majorityElement(nums);


    return 0;
}

