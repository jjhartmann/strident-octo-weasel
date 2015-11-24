#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows <= 0)
            return vector<vector<int>>();

        vector<vector<int>> res(numRows);

        // First row
        res[0] = vector<int>(1, 1);
        for (int i = 1; i < numRows; ++i)
        {
            int next = 1;
            res[i].push_back(next);
            for (int j = 1; j < i + 1; ++j)
            {
                if (j < i)
                    next += res[i-1][j];

                res[i].push_back(next);

                if (j-1 < i)
                    next -= res[i-1][j-1];
            }
        }

        return res;
    }
};

int main()
{
    Solution sol;
    sol.generate(5);
    return 0;
}