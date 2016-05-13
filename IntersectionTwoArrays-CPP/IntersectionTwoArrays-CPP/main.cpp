/////////////////////////////////////////////////////////////////////
// Intersection of Two Arrays
//
//Given two arrays, write a function to compute their intersection.
//
//Example:
//Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return[2].
//
//Note :
//    Each element in the result must be unique.
//    The result can be in any order.


#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // Store nums1 in hashmap (map) 

        unordered_set<int> hmap;

        for (int i = 0; i < nums1.size(); ++i)
        {
            hmap.insert(nums1[i]);
        }

        // Compare nums2 against and store in vector. 
        vector<int> res;
        std::unordered_set<int>::const_iterator got;
        for (int i = 0; i < nums2.size(); ++i)
        {
            if ((got = hmap.find(nums2[i])) != hmap.end())
            {
                res.push_back(nums2[i]);
                hmap.erase(got);
            }
        }


        return res;

    }
};

int main()
{

    cout << "INtersection of two arrays." << endl;
    vector<int> num1 = { 1,2,3,3,4,6,7,8 };
    vector<int> num2 = { 3, 3, 4, 8 };

    Solution sol;
    vector<int> ret = sol.intersection(num1, num2);

    return 0;
}
