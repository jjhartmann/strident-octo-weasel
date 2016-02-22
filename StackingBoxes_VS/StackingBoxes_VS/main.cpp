//////////////////////////////////////////////////
// Main  - Stacking Boxes


#include <iostream>
#include <vector>
#include <unordered_map>
#include <ctime>
#include <cstdlib>


using namespace std;

struct Box
{
    Box() :
        height(-1),
        width(-1),
        depth(-1)
    {}

    Box(int h, int w, int d) :
        height(h),
        width(w),
        depth(d),
        volumn(h*w*d)
    {}

    bool operator==(const Box &other) const
    {
        return this->depth == other.depth && this->height == other.height &&
            this->width == other.width && this->volumn == other.volumn;
    }

    bool empty()
    {
        return height < 0 && width < 0 && depth < 0;
    }

    bool canBeAbove(const Box &b)
    {
        return height < b.height && width < b.width && depth < b.depth;
    }

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

// Creating cutom hash function for Box class
namespace std {
    template<>
    struct hash <Box>
    {
        std::size_t operator() (Box const& k) const
        {
            using std::size_t;
            using std::hash;
            
            // Compute hash for Box Key
            return (((hash<int>()(k.depth) ^ (hash<int>()(k.height) << 1)) >> 1) ^ ((hash<int>()(k.depth) ^ (hash<int>()(k.volumn) << 1) >> 1)));
        }
    };
}

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



    // Alternative using DP and Recursion
    static vector<Box> StackBoxes(vector<Box> &boxes, unordered_map<Box, vector<Box>> &stack_map)
    {
        vector<Box> res;
        for (int i = 0; i < boxes.size(); ++i)
        {
            vector<Box> tmp;
            if (stack_map.find(boxes[i]) == stack_map.end())
            {
                tmp = StackBoxes(boxes, stack_map, boxes[i]);
            }
            else
            {
                tmp = stack_map[boxes[i]];
            }

            if (tmp.size() > res.size())
            {
                res = tmp;
            }
        }

        return res;
    }

    static vector<Box> StackBoxes(vector<Box> &boxes, unordered_map<Box, vector<Box>> &stack_map, Box bottom)
    {
        if (!bottom.empty() && stack_map.find(bottom) != stack_map.end())
        {
            return stack_map[bottom];
        }

        int MAX_Height = 0;
        vector<Box> max_stack;

        // Check every combination of box as bottom
        for (int i = 0; i < boxes.size(); ++i)
        {
            if (boxes[i].canBeAbove(bottom))
            {
                vector<Box> nBoxes = StackBoxes(boxes, stack_map, boxes[i]);
                int height = nBoxes.size();
                if (height > MAX_Height)
                {
                    MAX_Height = height;
                    max_stack = nBoxes;
                }
            }
        }

        if (!bottom.empty())
            max_stack.insert(max_stack.begin(), bottom);

        // Place bottom in hashmap
        stack_map[bottom] = max_stack;

        return max_stack;
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
    vector<Box> boxes2;
    CreateRandomBoxes(boxes, 50, 50);
    boxes2 = boxes;

    vector<Box> sol1 = Solution::StackBoxes(boxes);

    // Alt
    unordered_map<Box, vector<Box>> stack_map;
    vector<Box> sol2 = Solution::StackBoxes(boxes2, stack_map);

    return 0;
}