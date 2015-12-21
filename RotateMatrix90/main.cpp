#include <iostream>
#include <vector>
#include <cmath>



using namespace std;
typedef vector< vector <int> > MATRIX;

class Solution
{
public:
    static void rotateNinety(MATRIX &matrix)
    {
        int N = matrix.size();
        int ring = ceil(N/2);
        for (int i = 0; i < ring; ++i)
        {
            int cap = N - i - 1;
            for (int j = i; j < cap; ++j)
            {
                int tmp1 = matrix[j][cap];
                matrix[j][cap] = matrix[i][j];

                int tmp2 = matrix[cap][cap - (j - i)]; // fix
                matrix[cap][cap - (j - i)] = tmp1;

                tmp1 = matrix[cap - (j - i)][i];
                matrix[cap - (j - i)][i] = tmp2;

                matrix[i][j] = tmp1;
            }
        }



    }
};


int main()
{
    cout << "Rotate NxN Matrix 90 Degrees in- place" << endl;

    MATRIX mat = {
            {1, 2, 3, 4},
            {5,6,7,8},
            {9,10,11,12},
            {13,14,15,16},

    };

    MATRIX mat2 = {
            {1,2,3,4,5,6,7},
            {8,9,10,11,12,13,14},
            {15,16,17,18,19,20,21},
            {22,23,24,25,26,27,28},
            {29,30,31,32,33,34,35},
            {36,37,38,39,40,41,42},
            {43,44,45,46,47,48,49},

    };

//    Solution::rotateNinety(mat);
    Solution::rotateNinety(mat2);


    return 0;
}