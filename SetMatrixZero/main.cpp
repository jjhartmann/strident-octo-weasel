#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int height = matrix.size();
        int width = matrix.back().size();

        // Return if empty
        if (height == 0 || width == 0)
        {
            return;
        }

        vector<int> colNumbers;

        // Find zeros in matrix and set column and row to zero.
        for (int i = 0; i < height; ++i)
        {
            bool zero = false;
            for (int j = 0; j < width; ++j)
            {
                if (matrix[i][j] == 0)
                {
                    zero = true;
                    colNumbers.push_back(j);
                }

            }

            // Set col or row to zero;
            if (zero)
            {
                matrix[i] = vector<int>(width, 0);
            }
        }

        // Set all columns to zero
        for (int i = 0; i < height; ++i)
        {
            for (int j : colNumbers)
            {
                matrix[i][j] = 0;
            }
        }

    }
};


int main()
{
    Solution sol;

    vector<vector<int>> test1 =
            {
                    {1 , 1, 1, 2, 6, 1, 1, 9},
                    {3 , 4, 1, 0, 4, 1, 1, 4},
                    {2 , 4, 6, 5, 1, 1, 1, 3},
                    {5 , 1, 0, 1, 3, 1, 1, 3},
                    {6 , 1, 6, 7, 8, 1, 1, 9},
                    {8 , 1, 8, 8, 8, 1, 1, 0},
            };


    // test Sol
    sol.setZeroes(test1);

    cout << "FINISH" << endl;
    return 0;
}