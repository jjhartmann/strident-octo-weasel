// LC_TwoSum.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<int> twoSum(std::vector<int>& nums, int target) {

    // Sort vector
    std::sort(nums.begin(), nums.end());

    auto begin = nums.begin();
    auto end = nums.end();
    --end;

    int i = 0, j = nums.size() - 1;
    while (begin != end) {
        if (*begin + *end > target) {
            --end;
            --j;
        }
        else if (*begin + *end < target) {
            ++begin;
            ++i;
        }
        else {
            return { i, j };
        }

    }
}

vector<int> twoSum2(vector<int> nums, int target) {
    map<int, int> numMap;
    for (int i = 0; i < nums.size(); ++i) {
        numMap[target - nums[i]] = i;
    }

    for (int i = 0; i < nums.size(); ++i) {
        map<int, int>::iterator it = numMap.find(nums[i]);
        if (it != numMap.end())
        {
            return { i, it->second };
        }
    }

    return {};
}



int main() {
    std::vector<int> test = { 2, 3, 6, 8, 1, 4, 9 };
    std::vector<int> res = twoSum2(test, 14);
}


