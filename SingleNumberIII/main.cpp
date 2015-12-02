#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> mapint;

        // Iterate over nums and find duplicate ints
        int numsSize = nums.size();
        for (int i = 0; i < numsSize; ++i)
        {
            pair<unordered_map<int, int>::iterator, bool> pairItr = mapint.insert(make_pair(nums[i], i));

            if (!pairItr.second)
            {
                mapint.erase(pairItr.first);

            }
        }

        vector<int> res;
        for (auto itr : mapint)
        {
            res.push_back(itr.first);
        }

        return res;
    }


};


int main()
{
    Solution sol;


    vector<int> test = { 1,2,1,2,3,4,5,4,6,7,6,7,9,8,8};
    sol.singleNumber(test);

    cout << "FINISH" << endl;
    return 0;
}