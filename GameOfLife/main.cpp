#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        height = board.size();
        width = board.back().size();

        // If empty, return nothing
        if (height == 0 || width == 0)
        {
            return;
        }

        rowP = vector<int>(width, 0);
        rowC = board[0];

        // Process each row
        for (int i = 1; i < height+1; ++i)
        {
            if (i < height)
                rowN = board[i];
            else
                rowN = vector<int>(width, 0);


            // Process each column
            for (int j = 0; j < width; ++j)
            {
                // Preform Game of life logic.
                int neighbours = getLiveNeighbours(j);
                if (neighbours < 2 || neighbours > 3)
                {
                    // Cell dies
                    board[i-1][j] = 0;
                }
                else if (neighbours == 3)
                {
                    // Lives or spawns
                    board[i-1][j] = 1;
                }

                // Else, it will remain either 0 or 1.
            }

            // Set prev rows
            rowP = rowC;
            rowC = rowN;
        }


    }

private:
    // Calculate the live neighbours.
    int getLiveNeighbours(int start_j)
    {
        int total = 0;

        // Get the number of neighbours by counting box region
        int count = 0;
        for (int j = start_j - 1; j <  start_j + 2; ++j, ++count)
        {
            if (j >= 0 && j < width)
            {
                total = total + rowP[j] + rowN[j];

                // check for cell
                if (count != 1)
                {
                    total += rowC[j];
                }
            }
        }

        return total;
    }

    /////////////////////////////////////////
    // Private Vars
    int height, width;
    vector<int> rowP, rowC, rowN;

};

int main()
{
    Solution sol;

    vector<vector<int>> test1 =
            {
                    {0 , 1, 1, 0, 0, 1, 1, 0},
                    {0 , 0, 1, 0, 0, 1, 1, 0},
                    {0 , 1, 0, 0, 1, 1, 1, 0},
                    {0 , 1, 0, 1, 0, 1, 1, 0},
                    {0 , 1, 0, 0, 0, 1, 1, 0},
                    {0 , 1, 0, 0, 0, 1, 1, 0},
            };


    // test Sol
    sol.gameOfLife(test1);

    cout << "FINISH" << endl;

    return 0;
}