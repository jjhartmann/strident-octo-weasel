///////////////////////////////////////////////////////////////
// Main - Robot travels the grid

#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> Point;

class Grid
{
public:
    Grid(int x, int y) :
        mX(x),
        mY(y)
    {}

    template<typename ... T>
    Grid(int x, int y, Point first, T ... rest) :
        mX(x),
        mY(y),
        DPBuffer(((x  + 1) * (y + 1)) , 0)
    {

        // Add restricted points to vector. 
        mRestircted.push_back(first);
        Grid(mRestircted, rest...);
    }


    ////////////////////////////////////
    // Get the total possible paths Robot can traverse in place. 
    int getAllPossiblePathsNoRestrict()
    {
        return  allPathsHelper(mX, mY, DPBuffer);
    }


private:
    vector<Point> mRestircted;
    vector<int> DPBuffer;
    int mX;
    int mY;

    // Variadic overloads
    template<typename ... T>
    Grid(vector<Point> &vec, Point first, T ... rest)
    {
        vec.push_back(first);
        Grid(vec, rest...);
    }

    Grid(vector<Point> &vec)
    {
        return;
    }

    // Get all paths helper
    int allPathsHelper(int x, int y, vector<int> &DP)
    {
        int tmpx = (x < y) ? x : y;
        int tmpy = (x < y) ? y : x;

        if (x == 1 || y == 1)
        {
            return x + y;
        }

        if (DP[tmpy*mY + tmpx])
        {
            return DP[tmpy*mY + tmpx];
        }

        DP[tmpy*mY + tmpx] = allPathsHelper(x - 1, y, DP) + allPathsHelper(x, y - 1, DP);
        return  DP[tmpy*mY + tmpx];
        
    }

    // Factorial
    int fact(int n)
    {
        if (n <= 1) return 1;

        n *= fact(n - 1);
        return n;
    }
       
};





int main()
{
    cout << "How many ways can a robot travel on a grid" << endl;
    Grid myGrid(20, 20, Point(2, 4));
    int ans = myGrid.getAllPossiblePathsNoRestrict();

    return 0;
}