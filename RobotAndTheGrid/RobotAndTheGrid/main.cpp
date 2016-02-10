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
        mY(y)
    {
        mRestircted.push_back(first);
        Grid(rest...);
    }



private:
    vector<Point> mRestircted;
    int mX;
    int mY;

    // Variadic overloads
    template<typename ... T>
    Grid(Point first, T ... rest)
    {
        mRestircted.push_back(first);
        Grid(rest...);
    }

    Grid()
    {
        return;
    }
};





int main()
{
    cout << "How many ways can a robot travel on a grid" << endl;
    Grid myGrid(10, 10, Point(2, 4), Point(2, 5));


    return 0;
}