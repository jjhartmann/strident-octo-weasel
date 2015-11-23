#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int hieght = board.size();
        int width = board.back().size();


        vector<int> rowPrev(width, 0);
        vector<int> rowCurrent = board[0];
        vector<int> rowNext = board[1];

        // Process each row
        for (int i = 0; i < hieght; ++i)
        {
            rowCurrent = board[i];

            if (i + 1 < hieght)
                rowNext = board[i+1];

            // Process each column
            for (int j = 0; j < width; ++j)
            {






            }

            // Set prev rows
            rowPrev =  board[i];
        }


    }
};

int main()
{
    return 0;
}