#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height)
    {
        
        // Scan left to right right to left
        // Store maximal heights, 
        // O(2n)
        vector<int> heightLeft(height.size(), 0);
        vector<int> heightRight(height.size(), 0);
        int maxHLeft = 0;
        int maxHRight = 0;
        for (int i= 0, j = height.size()-1;
             i < height.size(); ++i, --j)
        {
            // For left to right
            int &currentHeightL = height[i];
            if (currentHeightL > maxHLeft)
            {
                maxHLeft = currentHeightL;
                heightLeft[i] = currentHeightL;
            }
            else
            {
                heightLeft[i] = maxHLeft;
            }  
            
            // For right to left
            int &currentHeightR = height[j];
            if (currentHeightR > maxHRight)
            {
                maxHRight = currentHeightR;
                heightRight[j] = currentHeightR;
            }
            else
            {
                heightRight[j] = maxHRight;
            }
        }

        // Get Solution
        int res = 0;
        for (int i = 0; i < height.size(); ++i)
        {
            res += min(heightLeft[i], heightRight[i]) - height[i];
        }

        return res;
    }
};


int main()
{
    vector<int> test = {0,1,0,2,1,0,1,3,2,1,2,1};

    Solution sol;
    cout << sol.trap(test);
    return 0;
}