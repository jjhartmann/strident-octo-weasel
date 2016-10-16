//
//  main.cpp
//  MatrixSearchII
//
//  Created by Jeremy Hartmann on 2016-06-13.
//  Copyright © 2016 Jeremy Hartmann. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Error
        
        
        if (matrix.size() <= 0) return false;
        if (matrix[0].size() <= 0) return false;
        
        int height = matrix.size();
        int width = matrix[0].size();
        
        int i = 0;
        int j = width - 1;
        
        while (i < height && j >= 0)
        {
            int val = matrix[i][j];
            if (val == target) return true;
            
            if (val < target)
            {
                ++i;
            }
            else
            {
                --j;
            }
            
        }
        
        return false;
        
    }
};



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    vector< vector< int >> mat = {
        {1,   4,  7, 11, 15, 20},
        {2,   5,  8, 12, 19, 25},
        {3,   6,  9, 16, 22, 26},
        {10, 13, 14, 17, 24, 27},
        {18, 21, 23, 26, 30, 31}
    
    };
    
    Solution sol;
    bool res = sol.searchMatrix(mat, 31);
    
    return 0;
}
