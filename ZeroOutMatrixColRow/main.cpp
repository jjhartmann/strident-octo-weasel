#include <iostream>
#include <vector>
#include <set>

using namespace std;
typedef vector< vector<int> > MATRIX;

enum MAT_TYPE
{
    ROW = 0,
    COL,
};


class MatrixProcessor
{
public:
    void operator() (MATRIX &mat, int location, int replacement, MAT_TYPE type)
    {
        if (type == ROW)
        {
            processRow(mat, location, replacement);
        }
        else
        {
            processCol(mat, location, replacement);
        }
    }

private:
    void processRow(MATRIX &mat, int location, int replacement)
    {
        for (int &i : mat[location])
        {
            i = replacement;
        }
    }

    void processCol(MATRIX &mat, int location, int replacement)
    {
        for (vector<int> &row : mat)
        {
            row[location]  = replacement;
        }
    }
};

template <class FuncType>
class Solution
{
public:
    void processMatrix(MATRIX & mat, int match, FuncType &processor)
    {
        set<int> row;
        set<int> col;
        for (int i = 0; i < mat.size(); ++i)
        {
            for (int j = 0; j < mat[i].size(); ++j)
            {
                if (mat[i][j] == match)
                {
                    row.insert(i);
                    col.insert(j);
                }
            }
        }


        // Process matrix
        for (int i : row)
        {
            processor(mat, i, match, ROW);
        }

        for (int i : col)
        {
            processor(mat, i, match, COL);
        }
    }
};

int main()
{
    cout << "Zero out the row and col that have zeros in them." << endl;
    MatrixProcessor process;
    MATRIX mat = {
            {1,2,3,4},
            {7,6,0,8},
            {0,10,11,12},
            {13,14,15,16},
            {0,18,19,0},
    };

    Solution<MatrixProcessor> sol;
    sol.processMatrix(mat, 0, process);
    return 0;
}