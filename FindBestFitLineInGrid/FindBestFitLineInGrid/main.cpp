/////////////////////////////////////////////////////////////////
// Main - Find best fit line in grid. 
#define _USE_MATH_DEFINES

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>


using namespace std;

typedef unordered_map<int, pair<int, int>> GRID; // Id, <x, y>; id = y*xdim + x
typedef unordered_map<int, unordered_map<double, int>> ACCUMULATOR; // degree, <distance, bin>

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

    // Get Grid
    GRID getGrid()
    {
        return mGrid;
    }

private:
    GRID mGrid;
    int xDim;
    int yDim;
};


////////////////////////////////////////////////
// Hough Class - 
class Hough
{
public:
    Hough(Graph g) :
        mGraph(g)
    {
        // process all points. 
        for (auto itr : mGraph.getGrid())
        {
            int x = itr.second.first;
            int y = itr.second.second;
            addToAccumulator(x, y);
        }

        // Find candidate lines
    }


private:
    // Hash map, mapping theta to r, and r to bin location. 
    ACCUMULATOR mAccumulator; // <\theta, <r, bin> pair. 
    Graph mGraph;
    double epsilon = 0.5;


    // Private Methods. 
    void addToAccumulator(int x, int y)
    {
        // For each angel calculate distance. 
        for (int i = 0; i < 360; ++i)
        {
            // Round to nearst tenth
            double rad = round(10 * degToRad(i)) / 10;
            double r = x * cos(rad) + y * sin(rad);

            // Round r to nearst tenth
            double rr = round(r) + epsilon;
            double deltar = abs(r - rr);
            if (deltar < epsilon)
            {
                if (deltar <= epsilon / 2.0)
                {
                    r = floor(r);
                }
                else
                {
                    r = floor(r) + (epsilon / 2.0);
                }
            }
            else if (deltar > epsilon)
            {
                if (deltar <= (epsilon + epsilon / 2.0))
                {
                    r = floor(r) + epsilon;
                }
                else
                {
                    r = floor(r) + epsilon + epsilon / 2.0;
                }
            }
            

            mAccumulator[i][r]++;
        }
    }

    // Convert Degrees to radians
    double degToRad(int deg)
    {
        return deg * (M_PI / 180);
    }

    // Convert Radians to Degree
    int radToDeg(double rad)
    {
        return rad * (180 / M_PI);
    }

};


int main()
{

    cout << "Find Best Fit Line in a Grid of Data Points" << endl;
    Graph myGrid({ 1, 3, 6, 7, 9 }, { 3, 5, 5, 7, 8 }, 10, 10);
    myGrid.PrintGrid();

    // Hough
    Hough houghTransform(myGrid);

    return 0;
}