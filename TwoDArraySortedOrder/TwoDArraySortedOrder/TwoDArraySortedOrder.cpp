// TwoDArraySortedOrder.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

void SortTwoDArray(vector< vector<int> > &mat)
{
    if (mat.size() == 0)
    {
        return;
    }
    else if (mat[1].size() == 0)
    {
        return;
    }

    // Get dimen
    int row = mat.size();
    int col = mat[1].size();

    vector<int> arr(row*col, 0);

    for (int i = 0; i < row; ++i)
    {
        int k = i * col;
        for (int j = 0; j < col; ++j)
        {
            arr[k + j] = mat[i][j];
        }
    }

    // Sort array
    sort(arr.begin(), arr.end());

    // Place back in mat col first
    int arrIndex = 0;
    for (int j = 0; j < col; ++j)
    {
        for (int i = 0; i < row; ++i)
        {
            mat[i][j] = arr[arrIndex];
            arrIndex++;
        }
    }
}



void PrintMatrix(vector<vector<int>> &mat)
{
    for (const auto &rowitr : mat)
    {
        for (const auto &colitr : rowitr)
        {
            cout << colitr << "\t";
        }

        cout << endl;
    }

    cout << endl;
}


int main()
{
    vector< vector<int> > matrix = {
        {2,4,5,6,5},
        {1,4,6,3,8},
        { 3,5,6,7,11 },
        { 7,5,4,5,2},
    }; 
    
    PrintMatrix(matrix);
    SortTwoDArray(matrix);
    PrintMatrix(matrix);

    return 0;
}

