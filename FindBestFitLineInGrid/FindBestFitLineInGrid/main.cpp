/////////////////////////////////////////////////////////////////
// Main - Find best fit line in grid. 


#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

typedef unordered_map<int, pair<int, int>> GRID;

// 2D Graph
class Graph
{
public:
    Graph(vector<int> xarray, vector<int> yarray, int xDimension, int yDimension) :
        xDim(xDimension),
        yDim(yDimension)
    {
        // Build grid. 
        int size = xarray.size();
        for (int i = 0; i < size; ++i)
        {
            int x = xarray[i];
            int y = yarray[i];

            mGrid[y*xDim + x] = pair<int, int>(x, y);
        }
    }


    // Print the Grid
    void PrintGrid()
    {
        for (int i = yDim - 1; i >= 0 ; --i)
        {
            for (int j = 0; j < xDim; ++j)
            {
                GRID::iterator itr = mGrid.find(i * xDim + j);
                if (itr == mGrid.end())
                {
                    cout << " - ";
                }
                else
                {
                    cout << " + ";
                }
            }

            cout << endl;
        }
    }


private:
    GRID mGrid;
    int xDim;
    int yDim;
};


int main()
{

    cout << "Find Best Fit Line in a Grid of Data Points" << endl;
    Graph myGrid({ 1, 3, 6, 7, 9 }, { 3, 5, 5, 7, 8 }, 10, 10);
    myGrid.PrintGrid();

    return 0;
}