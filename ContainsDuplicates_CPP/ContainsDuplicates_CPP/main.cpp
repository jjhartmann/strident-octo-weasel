/////////////////////////////////////////////////////////////////////////
// Contains Duplicates
//
// Given an array of integers, find if the array contains any duplicates.
// Your function should return true if any value appears at least twice 
// in the array, and it should return false if every element is distinct.

#include<iostream>
#include<vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // Can solve either with sorting or hashtable. 
        unordered_set<int> hmap;

        for (int i = 0; i < nums.size(); ++i)
        {
            unordered_set<int>::iterator got = hmap.find(nums[i]);
            if (got == hmap.end())
            {
                hmap.insert(nums[i]);
            }
            else
            {
                return true;
            }
        }

        return false;
    }

    bool containsDuplicate2(vector<int>& nums) {
        // Tick, usuing vector<bool> which is optimized for sapce
        vector<bool> bmap(2000000, false);

        for (int x : nums)
        {
            x += 1000000; // for negative signs
            if (bmap[x])
            {
                return true;
            }

            bmap[x] = true;
        }

        return false;
    }

};

int main()
{




    return 0;
}











