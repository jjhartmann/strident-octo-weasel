//////////////////////////////////////////////////
// Main  - Stacking Boxes


#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>


using namespace std;

struct Box
{
    Box() :
        height(0),
        width(0),
        depth(0)
    {}

    Box(int h, int w, int d) :
        height(h),
        width(w),
        depth(d)
    {}

    int height;
    int width;
    int depth;
};

////////////////////////////////////////////////////////////////
// Create Random Boxes
void CreateRandomBoxes(vector<Box> &boxes, int n, int MAX)
{
    srand(time(0));

    for (int i = 0; i < n; ++i)
    {
        Box b(rand() % MAX, rand() % MAX, rand() % MAX);
        boxes.push_back(b);
    }
}

////////////////////////////////////////////////////////////////
// Solution Class
class Solution
{
public:
    template<typename T>
    static void StackBoxes(vector<Box> &boxes)
    {

    }

private:
};

int main()
{
    cout << "Stack boxes on top of each other with strictly larger boxes on top." << endl;
    


    return 0;
}