///////////////////////////////////////////////////////////////
// Main - Skipping steps


#include <iostream>
#include <vector>

using namespace std;

// Using recursion with DP
class Solution {
  
public:
    static int SkippingSteps(int n)
    {
        DP = new vector<int>(n + 1, 0);
        int ans = SkippingStepsHelper(n);
        delete DP;
        return ans;
    }

private:
    static vector<int> *DP;

    static int SkippingStepsHelper(int n)
    {
        // Base case, if 1 return 1.
        if (n <= 1) return 1;
        if (n == 2) return 2;
        if (n == 3) return 4;

        // DP
        if ((*DP)[n])
        {
            return (*DP)[n];
        }

        (*DP)[n] = SkippingStepsHelper(n - 1) + SkippingStepsHelper(n - 2) + SkippingStepsHelper(n - 3);
        return (*DP)[n];
    } 
};

// Static Initialization
vector<int> *Solution::DP = nullptr;

int main()
{

    cout << "Number of ways to climb n steps when skipping 1, 2, or 3 steps at a time" << endl;
    int ans = Solution::SkippingSteps(10);



    return 0;
}