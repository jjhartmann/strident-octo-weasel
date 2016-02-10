///////////////////////////////////////////////////////////////
// Main - Robot travels the grid

#include <iostream>
#include <vector>
#include <unordered_map>

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


    // Find a path, avoiding restricted points. 
    bool findPath(vector<Point> &path)
    {
        unordered_map<int, bool> DP;
        return findPathHelper(mX, mY, path, DP);
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

    // Find Path Helper
    bool findPathHelper(int x, int y, vector<Point> &path, unordered_map<int, bool> &DP)
    {

        Point p(x, y);

        // Check it point is cached
        if (DP.find(y*mX + x) != DP.end())
        {
            return DP[y*mX + x];
        }

        // Check if end coordinates
        if (x == 1 && y == 1) return true;

        bool success = false;
        if (x >= 1 && isOK(x - 1, y))
        {
            success = findPathHelper(x - 1, y, path, DP);
        }

        if (!success && y >= 1 && isOK(x, y - 1))
        {
            success = findPathHelper(x, y - 1, path, DP);
        }

        if (success)
        {
            path.push_back(p);
        }

        DP[y*mY + x] = success;
        return success;

    }

    // Check if nodes is ok
    bool isOK(int x, int y)
    {
        if (x > mX || y > mY || x < 0 || y < 0) return false;

        for (auto ip : mRestircted)
        {
            if (x == ip.first && y == ip.second)
                return false;
        }

        return true;
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
    Grid myGrid(10, 10, Point(2, 4), Point(5, 3), Point(8, 6), Point(3, 6), Point(9, 7), Point(8, 8), Point(1, 2), Point(10, 4));
    int ans = myGrid.getAllPossiblePathsNoRestrict();

    vector<Point> myPath;
    bool success = myGrid.findPath(myPath);

    return 0;
}