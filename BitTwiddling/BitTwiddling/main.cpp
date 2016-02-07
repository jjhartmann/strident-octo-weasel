///////////////////////////////////////////////////////////////
// Main - Bit Twiddling

#include <iostream>


using namespace std;

/////////////////////////////////////////////////////////////
// Given two 32 bit ints, and two value range. Merge the integers. 
int MergeInt(int N, int M, int i, int j)
{
    int len = j - i + 1;
    int mmask = ~(~0 << len);
    
    // Clear all MSBs
    M = M & mmask;

    // Clear N range
    N = N & ~(mmask << i);

    // merge values
    return N | (M << i);

}



int main()
{
    cout << "Collection of Bit Twiddling Hacks" << endl;
    
    int res = MergeInt(23, 11, 2, 6);

    return 0;
}