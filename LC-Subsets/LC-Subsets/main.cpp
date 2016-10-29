//
//  main.cpp
//  LC-Subsets
//
//  Created by Jeremy Hartmann on 2016-10-28.
//  Copyright © 2016 Jeremy Hartmann. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        
        for (int i = 0; i < pow(2, nums.size()); ++i){
            ret.push_back(createFromBits(i, nums));
        }
        
        return ret;
    }
    
    
    
private:
    vector<int> createFromBits(int x, vector<int> nums) {
    
        vector<int> ret;
        int i = 0;
        while (x > 0) {
            
            if(x % 2) {
                ret.push_back(nums[i]);
            }
            
            ++i;
            x = x/2;
        }
        
        
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    
    vector<int> q = {1,2,3};
    Solution sol;
    sol.subsets(q);
    
    
    return 0;
}
