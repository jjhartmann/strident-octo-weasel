///////////////////////////////////////////////////////////////
// Main - Fill surrounding area with same value. 

#include <iostream>
#include <initializer_list>
#include <vector>

using namespace std;

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

private:
    vector<int> mGrid;
    int mXdim;
    int mYdim;
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


    return 0;
}