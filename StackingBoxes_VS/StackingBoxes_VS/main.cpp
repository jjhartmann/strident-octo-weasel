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
        depth(d),
        volumn(h*w*d)
    {}

    int height;
    int width;
    int depth;
    int volumn;
};

enum BOXDIM
{
    HEIGHT = 0,
    WIDTH,
    DEPTH,
    VOLUMN
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
        int a = 0;
        int b = boxes.size() - 1;

        // Sort Via MergeSort (Stable)
        StackBoxes(boxes, a, b, HEIGHT);
        StackBoxes(boxes, a, b, WIDTH);
        StackBoxes(boxes, a, b, DEPTH);
        StackBoxes(boxes, a, b, VOLUMN);

        // Create array of strictly smaller boxes in increasing order. 
        vector<Box> stacked;
        stacked.push_back(boxes.back());
        for (int i = boxes.size() - 2; i >= 0; --i)
        {
            if (stacked.back().height > boxes[i].height &&
                stacked.back().width > boxes[i].width &&
                stacked.back().depth > boxes[i].depth)
            {
                stacked.push_back(boxes[i]);
            }
        }

        return stacked;
    }

private:
    static void StackBoxes(vector<Box> &boxes, int a, int b, BOXDIM dim)
    {

        if (b - a <= 0) return;

        int mid = a + ceil((b - a) / 2);
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

            case 3: // VOLUMN
                vala = boxes[a].volumn;
                valb = boxes[c].volumn;
                break;
            }

            // Build sorted vec
            if (vala <= valb)
            {
                buffer.push_back(boxes[a]);
                a++;
            }
            else
            {
                buffer.push_back(boxes[c]);
                c++;
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
            buffer.push_back(boxes[c]);
            c++;
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
    CreateRandomBoxes(boxes, 10000, 50);

    Solution::StackBoxes(boxes);

    return 0;
}