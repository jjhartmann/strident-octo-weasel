///////////////////////////////////////////////////////////////////////
// Move Zeros
// Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
//
// For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be[1, 3, 12, 0, 0].
//
// Note:
//     You must do this in - place without making a copy of the array.
//     Minimize the total number of operations.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // Inplace move
        int size = nums.size();
        for (int i = 0; i < size; ++i)
        {
            if (nums[i] == 0)
            {
                nums.erase(nums.begin() + i);
                nums.push_back(0);
                --i;
                --size;
            }
        }
    }
};


int main()
{
    cout << "Move Zeros" << endl;
    vector<int> nums = { 2, 3,4,5,1,0,2,1,0,3,4,5,0,0,3,2,4,0,0 };
    Solution sol;

    sol.moveZeroes(nums);


    return 0;
}



