///////////////////////////////////////////////////////
// Hamming Weight
//
//Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).
//
//For example, the 32 - bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.


#include <iostream>



using namespace std;


class Solution {
public:
    int hammingWeight(uint32_t n) {
         int len = sizeof(uint32_t) * 8;
        uint32_t mask = 1;
        int weight = 0;
        for (int i = 0; i < len; ++i)
        {
            weight = ((n >> i) & mask) >= 1 ? weight + 1 : weight;
        }

        return weight;
    }
};

int main()
{
    cout << "Calculate the Hamming Weight" << endl;

    uint32_t test = 23234;

    Solution sol;

    int ret = sol.hammingWeight(test);


    return 0;
}