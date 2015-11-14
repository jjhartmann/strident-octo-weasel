#include <iostream>
#include <vector>

using namespace std;

/////////////////////////////////////////////////////////////////////
// The question regarding range of a 2D matrix can be solved using
// Dynamic programming. By taking the w * h combinations of the sum
// of the matrix, we can use smaller sub-regions to calculate more
// complex bounds.
// Constructor: O(w*h) Time Complexity
//              O(w*h) Space Complexity
// Method: sumRegion: O(1)
//////////////////////////////////////////////////////////////////////
class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) :
        m_MatWidth(0)
    {
        // Check if empty
        if (matrix.empty())
            return ;

        if (matrix[0].empty())
            return ;

        // Size
        int h = matrix.size();
        m_MatWidth = matrix[0].size();
        int sum = 0;

        // allocate array
        m_DP = new int[m_MatWidth*h];

        for (int i = 0; i < h; ++i)
        {
            sum = matrix[i][0];
            for (int j = 1; j < m_MatWidth+1; ++j)
            {
                int subSum = 0;
                if (i > 0)
                    subSum += m_DP[(i - 1) * m_MatWidth + (j - 1)];

                m_DP[i * m_MatWidth + (j - 1)] = sum + subSum;

                if (j < m_MatWidth)
                    sum += matrix[i][j];
            }
        }
    }

    ~NumMatrix(){
        // Delete array.
        if (m_MatWidth != 0)
            delete[] m_DP;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {

        // Check m_DP for elements
        if (m_MatWidth == 0)
            return 0;

        int sub1 = m_DP[row2 * m_MatWidth + col2];
        int sub2 = (row1 > 0) ? m_DP[(row1 - 1) * m_MatWidth + col2] : 0;
        int sub3 = (col1 > 0) ? m_DP[row2 * m_MatWidth + col1 - 1] : 0;
        int sub4 = (row1 > 0 && col1 > 0) ? m_DP[(row1 - 1) * m_MatWidth + col1 - 1] : 0;

        return sub1 - sub2 - sub3 + sub4;
    }

private:
    // Map Var
    int *m_DP; // Own.
    int m_MatWidth;

};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);


int main()
{

    vector<vector<int>> testMatrix = {
            {3, 0, 1, 4, 2},
            {5, 6, 3, 2, 1},
            {1, 2, 0, 1, 5},
            {4, 1, 0, 1, 7},
            {1, 0, 3, 0, 5}
    };


    // Testing Sol
    NumMatrix test(testMatrix);

    cout << test.sumRegion(0, 0, 2, 2) << endl;
    cout << test.sumRegion(1,2,3,4) << endl;
    cout << test.sumRegion(0,0,0,0) << endl;
    cout << test.sumRegion(3,3,3,3) << endl;
    cout << test.sumRegion(2,2,3,4) << endl;

    vector<vector<int>> testMatrix2;
    NumMatrix test2(testMatrix2);
    test2.sumRegion(1, 2, 4, 5);

    return 0;
}