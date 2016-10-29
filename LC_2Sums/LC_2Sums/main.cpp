//
//  main.cpp
//  LC_2Sums
//
//  Created by Jeremy Hartmann on 2016-10-29.
//  Copyright © 2016 Jeremy Hartmann. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        
        if (nums.empty() || nums.size() == 1) { return res; }
        
        
        vector<pair<int, int>> numsPlus(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            numsPlus[i] = pair<int, int>(nums[i], i);
        }
        
        sort(numsPlus.begin(), numsPlus.end(),
             [](const pair<int, int> l, const pair<int, int> r) -> bool
        {
            return l.first < r.first;
        });
        
        int i = 0;
        int j = nums.size() - 1;
        while(res.empty() && i < nums.size() && j >= 0) {
            if (numsPlus[i].first + numsPlus[j].first == target){
                res.push_back(numsPlus[i].second);
                res.push_back(numsPlus[j].second);
            } else if (numsPlus[i].first + numsPlus[j].first > target) {
                --j;
            } else {
                ++i;
            }
        }
        
        return res;
    }
};



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Two Sums Problem!\n";
    
    
    vector<int> N = {0,4,3,0};
    
    Solution sol;
    vector<int> r = sol.twoSum(N, 0);
    
    
    
    
    return 0;
}
