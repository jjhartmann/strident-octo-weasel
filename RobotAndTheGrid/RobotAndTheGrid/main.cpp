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
        Grid(mRestircted, rest...);
    }



private:
    vector<Point> mRestircted;
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
};





int main()
{
    cout << "How many ways can a robot travel on a grid" << endl;
    Grid myGrid(10, 10, Point(2, 4), Point(2, 5), Point(3,9));


    return 0;
}