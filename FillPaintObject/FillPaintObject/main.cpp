///////////////////////////////////////////////////////////////
// Main - Fill surrounding area with same value. 

#include <iostream>
#include <initializer_list>
#include <vector>

using namespace std;

typedef pair<int, int> Point;

class Image
{
public:
    Image(initializer_list< initializer_list<int>> v) :
        mYdim(v.size()),
        mXdim((v.size()) ? v.begin()->size() : 0),
        mGrid(((v.size()) ? v.begin()->size() : 0) * v.size())
    {
        // COnstruct image array
        int indexY = 0;
        for (auto i : v)
        {
            int indexX = 0;
            for (auto k : i)
            {
                mGrid[indexY * mXdim + indexX] = k;
                ++indexX;
            }
            ++indexY;
        }
    }

    // Print the image to screen
    void printToScreen()
    {

        for (int i = 0; i < mYdim; ++i)
        {
            for (int j = 0; j < mXdim; ++j)
            {
                cout << mGrid[i*mXdim + j] << " ";
            }
            cout << endl;
        }
    }


    // Change and replace value with another (Fill)
    void fill(Point p, int value)
    {
        int cVal = mGrid[p.second * mXdim + p.first];
        fill(mGrid, p, value, cVal);
    }

private:
    // Private Vars
    vector<int> mGrid;
    int mXdim;
    int mYdim;

    // Methods. 
    void fill(vector<int> &grid, Point p, int nVal, int cVal)
    {
        // Replace value;
        grid[p.second * mXdim + p.first] = nVal;

        // Check and replace adjacent values. 
        // Check right
        if (p.first < (mXdim - 1) && cVal == grid[p.second * mXdim + (p.first + 1)])
        {
            
            fill(grid, Point(p.first + 1, p.second), nVal, cVal);
        }

        // check left
        if (p.first > 0 && cVal == grid[p.second * mXdim + (p.first - 1)])
        {
            fill(grid, Point(p.first - 1, p.second), nVal, cVal);
        }

        // check up
        if (p.second < (mYdim - 1) && cVal == grid[(p.second + 1) * mXdim + p.first])
        {
            fill(grid, Point(p.first, p.second + 1), nVal, cVal);
        }

        // check up
        if (p.second > 0 && cVal == grid[(p.second - 1) * mXdim + p.first])
        {
            fill(grid, Point(p.first, p.second - 1), nVal, cVal);
        }
    }

};

int main()
{
    cout << "Fill all adjacent values with another value in surrounding areas" << endl;
    Image img = {
        { 55,55,55,55,55,55,55,55,55,55 },
        { 55,55,55,55,55,55,55,55,55,55 },
        { 55,55,55,11,55,55,55,55,55,55 },
        { 55,55,11,11,11,11,55,55,55,55 },
        { 55,55,11,11,11,11,55,55,55,55 },
        { 55,55,55,11,11,11,11,55,55,55 },
        { 55,55,11,11,11,11,55,55,55,55 },
        { 55,55,11,11,55,55,55,55,55,11 },
        { 55,55,55,55,55,55,55,55,11,11 },
        { 55,55,55,55,55,55,55,55,11,11 },
    };


    // Print to screen 
    img.printToScreen();

    // Fill in from (4, 4)
    img.fill(Point(4, 4), 88);

    img.printToScreen();


    return 0;
}