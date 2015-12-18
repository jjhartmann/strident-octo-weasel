#include <iostream>
#include <cmath>

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

    // Optimized
    int optimizedBitwiseAnd(int m, int n)
    {
        int bitshift = 1;

        int mop = ~m & n;
        if (mop > n)
        {
            return 0;
        }

        while (m < n && m != 0)
        {
            m = m/2;
            n = n/2;
            bitshift *= 2;
        }

        m *= bitshift;

        return m;
    }


    int optimizedBitwiseAnd2(int m, int n)
    {
        int xlog = static_cast<int>(floor(log2(m ^ n)));

        // set the bits
        int mask = 0;
        while (xlog >= 0)
        {
            mask |= 1 << xlog;
            --xlog;
        }

        m &= ~mask;

        return m;
    }
};



int main()
{
    // Init
    Solution sol;
//    sol.rangeBitwiseAnd(600000000, 2147483645);
//    sol.rangeBitwiseAnd(2147483647, 2147483647);
//    sol.rangeBitwiseAnd(4, 6);
//    sol.recursiveBitwiseAnd(4, 6);
//    sol.optimizedBitwiseAnd(4, 6);
    sol.optimizedBitwiseAnd2(49, 54);

    return 0;
}