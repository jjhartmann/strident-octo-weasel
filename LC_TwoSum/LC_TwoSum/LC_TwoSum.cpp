// LC_TwoSum.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <algorithm>
#include <map>
using namespace std;


vector<int> twoSum(vector<int> numbers, int target) {
    int i = 0, j = numbers.size() - 1;
    while (i < j) {
        if (numbers[i] + numbers[j] > target) {
            --j;
        }
        else if (numbers[i] + numbers[j] < target) {
            ++i;
        }
        else {
            return{ i + 1, j + 1 };
        }
    }

    return {};
}


vector<int> twoSum2(vector<int> nums, int target) {
    map<int, int> numMap;
    for (int i = 0; i < nums.size(); ++i) {
        numMap[target - nums[i]] = i;
    }

    for (int i = 0; i < nums.size(); ++i) {
        map<int, int>::iterator it = numMap.find(nums[i]);
        if (it != numMap.end() && it->second != i)
        {
            return { i, it->second };
        }
    }

    return {};
}

int BSearch(vector<int> nums, int start, int key) {
    int L = start;
    int R = nums.size() - 1;
    while (L < R) {
        int M = (L + R) / 2;
        if(nums[M] < key) {
            L = M + 1;
        }
        else {
            R = M;
        }
    }

    return (L == R && nums[L] == key) ? L : -1;
}

vector<int> twoSumBS(vector<int> numbers, int target) {
    for (int i = 0; i < numbers.size(); ++i) {
        int res = BSearch(numbers, i + 1, target - numbers[i]);
        if (res >= 0 && i != res) {
            return { i + 1, res + 1 };
        }
    }

    return {};
}


int main() {
    std::vector<int> test = {3,2,4 };
    std::vector<int> res = twoSumBS({0,0,3,4}, 0);

    return 0;
}


