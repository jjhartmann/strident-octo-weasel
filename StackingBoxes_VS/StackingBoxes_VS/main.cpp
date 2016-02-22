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

enum BOXDIM
{
    HEIGHT = 0,
    WIDTH,
    DEPTH
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
    static vector<Box> StackBoxes(vector<Box> &boxes)
    {
        // Sort on the w, h, and d. Merge sort. 

    }

private:
    static void StackBoxes(vector<Box> &boxes, int a, int b, BOXDIM dim)
    {

        if (a - b <= 0) return;

        int mid = ceil((a - b) / 2);
        StackBoxes(boxes, a, mid, dim);
        StackBoxes(boxes, mid + 1, b, dim);

        // Merge results
        merge(boxes, a, mid, mid + 1, b, dim);
    }

    static void merge(vector<Box> &boxes, int a, int b, int c, int d, BOXDIM dim)
    {
        int tmpmin = a;
        int tmpmax = d;

        int vala = 0;
        int valb = 0;
        vector<Box> buffer;

        while (a <= b && c <= d)
        {
            switch (dim)
            {
            case 0: // HEIGHT
                vala = boxes[a].height;
                valb = boxes[c].height;

                break;

            case 1: // WIDTH
                vala = boxes[a].width;
                valb = boxes[c].width;
                break;

            case 2: // DEPTH
                vala = boxes[a].depth;
                valb = boxes[c].depth;
                break;
            }

            // Build sorted vec
            if (vala < valb)
            {
                buffer.push_back(boxes[a]);
                a++;
            }
            else
            {
                buffer.push_back(boxes[b]);
                b++;
            }
        }

        // Fill rest of buffer. 
        while (a <= b)
        {
            buffer.push_back(boxes[a]);
            a++;
        }

        while (c <= d)
        {
            buffer.push_back(boxes[b]);
            b++;
        }

        // Place Sorted Vec into boxes array.
        int index = 0;
        while (tmpmin <= tmpmax)
        {
            boxes[tmpmin] = buffer[index];
            ++tmpmin;
            ++index;
        }

    }

};

int main()
{
    cout << "Stack boxes on top of each other with strictly larger boxes on top." << endl;
    vector<Box> boxes;
    CreateRandomBoxes(boxes, 10, 10);



    return 0;
}