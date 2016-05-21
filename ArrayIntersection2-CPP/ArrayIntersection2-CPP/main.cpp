//////////////////////////////////////////////////////////////////////
// Intersection of Two Arrays II
//
// Given two arrays, write a function to compute their intersection.
//
// Example:
// Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return[2, 2].
//
// Note :
//    Each element in the result should appear as many times as it shows in both arrays.
//    The result can be in any order.
// 
// Follow up :
//    What if the given array is already sorted ? How would you optimize your algorithm ?
//    What if nums1's size is small compared to num2's size ? Which algorithm is better ?
//    What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once ?


#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        // Build hash table
        unordered_map<int, int> hmap;
        for (int i = 0; i < nums1.size(); ++i)
        {
            unordered_map<int, int>::iterator got = hmap.find(nums1[i]);

            if (got == hmap.end()) 
            {
                hmap.insert(pair<int, int>(nums1[i], 1));
            }
            else
            {
                got->second++;
            }
        }

        // Find intersection
        vector<int> intersection;
        for (int i = 0; i < nums2.size(); ++i)
        {
            unordered_map<int, int>::iterator got = hmap.find(nums2[i]);

            if (got != hmap.end() && got->second > 0)
            {
                intersection.push_back(nums2[i]);
                got->second--;
            }
        }


        return intersection;

    }
};

int main()
{
    cout << "Array Intersection II" << endl;
    Solution sol;

    vector<int> nums1 = { 1,2,3,4,3,4,5,6,6,7,8,4,9 };
    vector<int> nums2 = { 2,2,4,5,5,10 ,4};

    vector<int> ret = sol.intersect(nums1, nums2);



    return 0;
}

