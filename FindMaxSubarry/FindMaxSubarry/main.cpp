///////////////////////////////////////////////////////////////
// Main

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> FindMaximumSubarray(vector<int> &A)
{
    int max_here = 0;
    int max_total = 0;

    vector<int> resultA(3, 0);
    int index = 0;
    for (int i : A)
    {
        if (max_here == 0)
        {
            resultA[0] = index;
        }

        max_here = max(0, max_here + i);


        if (max_here > max_total)
        {
            resultA[1] = index;
        }

        max_total = max(max_total, max_here);
        ++index;
    }

    resultA[2] = max_total;
    return resultA;

}

int main()
{

    cout << "Find the maximum subarray in a given array." << endl;

    vector<int> test = { 5,4,-2,1,-8,6,5,-3,5,8,-9,4,2,1 };
    vector<int> res = FindMaximumSubarray(test);


    return 0;
}