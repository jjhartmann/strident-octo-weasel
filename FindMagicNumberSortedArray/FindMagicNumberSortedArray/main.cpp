///////////////////////////////////////////////////////////////
// Main - Find Magic Number in Sorted Array

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    static int FindMagicNumber(vector<int> &vec)
    {
        return findMagicHelper(vec, 0, vec.size() - 1);
    }


private:
    static int findMagicHelper(vector<int> &vec, int sPos, int ePos)
    {
        int offset = (ePos - sPos);
        int index = sPos + offset/2;

        // Check offset. 
        if (offset < 0) return -1;
        

        // check for magic number
        int num = vec[index];
        if (num == index) return index;

        // Check equality
        if (num > index)
            return findMagicHelper(vec, index + 1, ePos);

        // Check lower half
        return findMagicHelper(vec, sPos, index - 1);
    }
};


int main()
{
    cout << "Find the magic number (A[i] == i) in a sorted array" << endl;
    vector<int> test = { 1,3,4,6,7,8,10,10,14,15,16,17 };
    Solution::FindMagicNumber(test);


    return 0;
}