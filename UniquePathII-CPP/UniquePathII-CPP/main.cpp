//
//  main.cpp
//  UniquePathII-CPP
//
//  Created by Jeremy Hartmann on 2016-06-13.
//  Copyright © 2016 Jeremy Hartmann. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        // Can use dynamic programming to determine the answer.
        if (obstacleGrid.size() <= 0) return 0;
        if (obstacleGrid[0].size() <= 0) return 0;
        
        int height = obstacleGrid.size();
        int width = obstacleGrid[0].size();
        
        if (obstacleGrid[0][0] == 1) return 0;
        
        obstacleGrid[0][0] = 1;
        
        for (int i = 0; i < height; ++i)
        {
            for (int j = 0; j < width; ++j)
            {
                int previousx = (j - 1 < 0) ? 0 : obstacleGrid[i][j-1];
                int previousy = (i - 1 < 0) ? 0 : obstacleGrid[i - 1][j];
                
                int currval = obstacleGrid[i][j];
                
                if (currval == 1 && (i != 0 || j != 0) )
                {
                    obstacleGrid[i][j] = 0;
                }
                else if (i != 0 || j != 0) {
                    obstacleGrid[i][j] = previousx + previousy;
                }
            }
        }
        
        return obstacleGrid[height - 1][width - 1];
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Unque Path II/n";
    
    vector<vector<int>> mat = {
        {0,0,0,0,0,0},
        {0,0,0,0,0,0},
        {0,0,0,0,0,0},
        {0,0,0,0,0,0},
        {0,0,0,0,0,0},
        {0,0,0,0,0,0},
        {0,0,0,0,0,0},
        {0,0,0,0,0,0}
    };
    
    vector<vector<int>> mat2 = {{0,1}};
    
    Solution sol;
    int res = sol.uniquePathsWithObstacles(mat);
    
    return 0;
}
