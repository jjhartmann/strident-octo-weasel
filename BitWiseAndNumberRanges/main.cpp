#include <iostream>

using namespace std;
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int res = 0;
        int bitshift = 0;
        res = ~res;

        while (m <= n && m >= 0)
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
                m = m >> 1;
                n = n >> 1;
                ++bitshift;
            }

            ++m;
        }

        // reapply the bit shifting
        res = res << bitshift;

        return res;
    }

    // Using recursion, we can get the same desired results as above.
    int recursiveBitwiseAnd(int m, int n)
    {
        return (m < n) ? (recursiveBitwiseAnd(m/2, n/2) << 1) : m;
    }
};



int main()
{
    // Init
    Solution sol;
//    sol.rangeBitwiseAnd(600000000, 2147483645);
//    sol.rangeBitwiseAnd(2147483647, 2147483647);
//    sol.rangeBitwiseAnd(4, 6);
    sol.recursiveBitwiseAnd(4, 6);

    return 0;
}