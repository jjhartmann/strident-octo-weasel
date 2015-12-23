#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    static int calcIterative(int n)
    {
        vector<int> cache = {1, 2, 4};
        for (int i = 3; i < n; ++i)
        {
            cache[i % 3] = cache[0] + cache[1] + cache[2];
        }

        return cache[(n-1) % 3];
    }

    static int calcRecursion(int n)
    {
        if (n < 0)
        {
            return 0;
        }
        else if (n == 0)
        {
            return 1;
        }
        else
        {
            return calcRecursion(n - 1) + calcRecursion(n - 2) + calcRecursion(n - 3);
        }
    }
};

int main()
{
    cout << "Stairs and Partitions" << endl;
    Solution::calcStairs(8);
    int res = Solution::clacRecursion(4);

    return 0;
}