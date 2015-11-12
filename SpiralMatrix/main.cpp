#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        // Check empty matrix
        if(matrix.empty())
        {
            return vector<int>();
        }

        // Loop over i and j, keeping track of j_max, j_min, i_max and i_min
        int i = 0, j = 0, solIndex = 0,
            i_max = matrix.size(), i_min = 0,
            j_max = matrix[0].size(), j_min = 0;

        // Initialize vector (reduces reallocation cost if matrix is large)
        vector<int> sol(matrix.size() * matrix[0].size(), 0);

        int count = 0;
        const int maxCount = min(matrix.size(), matrix[0].size());
        while (count < maxCount)
        {
            if (count % 2 == 0)
            {
                // forward
                // J Loop Here for first loop
                for (j = j_min; j < j_max; ++j)
                {
                    sol[solIndex++] = matrix[i][j];
                }
                --j_max;
                --j; //reset to actual value;

                // I loop Here
                ++i_min;
                // Start loop
                for (i = i_min; i < i_max; ++i)
                {
                    // access vector
                    sol[solIndex++] = matrix[i][j];
                }
                --i; // reset to actual index
            }
            else
            {
                // reverse
                // J Loop Here for first loop
                for (j = j_max-1; j >= j_min; --j)
                {
                    // access vector
                    sol[solIndex++] = matrix[i][j];
                }
                ++j_min;
                ++j; // reset to actual value

                // I loop Here
                --i_max;
                // Start loop
                for (i = i_max-1; i >= i_min; --i)
                {
                    // access vector
                    sol[solIndex++] = matrix[i][j];
                }
                ++i; //reset to actual index
            }

            ++count;
        }

        return sol;

    }
};

int main()
{
    // Get a spiral vector from a matrix
    vector<vector<int>> test = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };

    Solution testSol;
    testSol.spiralOrder(test);



    return 0;
}