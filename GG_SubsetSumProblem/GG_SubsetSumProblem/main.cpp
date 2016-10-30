//
//  main.cpp
//  GG_SubsetSumProblem
//
//  Created by Jeremy Hartmann on 2016-10-29.
//  Copyright © 2016 Jeremy Hartmann. All rights reserved.
//
//  Given a a set of n integers, find a continguous subset S that sums up to
//  a given interger x

#include <iostream>
#include <vector>

using namespace std;

class Solution {

public:
    vector<int> subset(vector<int> nums, int x) {
        
        if (nums.empty()) {
            return vector<int>();
        }
        
        vector<int> ret;
        vector<int> DP(nums.size() + 1);
        
        DP[0] = 0;
        DP[1] = nums[0];
        for (int i = 1; i < DP.size(); ++i) {
            DP[i + 1] = nums[i] + DP[i];
        }
        
        
        int i = 0, j = 1;
        bool found = false;
        while(!found && j < DP.size() && i < j && j > i) {
            
            int sum = DP[j] - DP[i];
            
            if (sum == x){
                ret = getSubset(nums, i, j);
                found = true;
            }
            
            if (sum > x) {
                ++i;
            } else {
                ++j;
            }
        }
    
        return ret;
    }
    
private:
    
    vector<int> getSubset(vector<int> nums, int i, int j){
        vector<int> ret;
        while(i < j){
            ret.push_back(nums[i]);
            ++i;
        }
        
        return ret;
    }
};

int main(int argc, const char **argv) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    
    vector<int> nums = {2,3,1,5,7,6,8};
    Solution sol;
    
    vector<int> result = sol.subset(nums, 12);
    
    
    return 0;
}
