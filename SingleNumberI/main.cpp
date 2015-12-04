#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums)
    {
        // Iterate through nums and use xor to find the single number in a array of duplicates.
        int res = 0;
        for (int num : nums)
        {
            res ^= num;
        }

        return res;
    }
};

int main()
{
    Solution sol;

    vector<int> test = {1,2,3,4,5,6,7,8,9,11,9,8,7,6,5,4,3,2,1};
    sol.singleNumber(test);

    return 0;
}