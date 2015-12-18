#include <iostream>

using namespace std;
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int res = 0;
        int bitshit = 0;
        res = ~res;

        while (m <= n)
        {
            res = res & m;

            if (res == 0)
            {
                return res;
            }

            // apply bitshiting to remove odd '0' at the end.
            while (res % 2 == 0)
            {
                res = res >> 1;
            }

            ++m;
        }

        return res;
    }
};



int main()
{
    // Init
    Solution sol;
    sol.rangeBitwiseAnd(600000000, 2147483645);

    return 0;
}