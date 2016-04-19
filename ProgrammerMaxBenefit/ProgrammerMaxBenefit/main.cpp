//////////////////////////////////////////////////////////////////////
// Programmer Benefit
//
// Find the max benefit in assigning k programmers to n jobs. 

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define BMAP vector<vector<int>>
#define DPAIR pair<int, pair<int, int>>


// This is wrong, greedy doesn't work. 
int MaxBenefit(BMAP b, int k, int N)
{
    // 1: build a ratio map with ratio = benefit/programmers
    vector<DPAIR> DP;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 1; j <= k; ++j)
        {
            DP.push_back(make_pair(b[i][j-1] / j, make_pair(i, j)));
        }
    }

    // 2: Use greedy algorithm to find the max possible values that fulfill k programmers 
    auto heapComp = [](const DPAIR a, const DPAIR b)->bool {
        return a.first < b.first;
    };

    make_heap(DP.begin(), DP.end(), heapComp);

    int k_tmp = k;
    int res = 0;
    vector<int> programcount;
    while (k_tmp > 0)
    {
        int programmers = DP.front().second.second;
        int programNumber = DP.front().second.first;
        if (k_tmp >= programmers && find(programcount.begin(), programcount.end(), programNumber) == programcount.end())
        {
            cout << "Program Number: " << programNumber << "\tProgrammers: " << DP.front().second.second << "\tWeight: " << DP.front().first << endl;
            res += (DP.front().first * programmers);
            k_tmp -= programmers;
            programcount.push_back(programNumber);
        }
        
        pop_heap(DP.begin(), DP.end(), heapComp);
        DP.pop_back();
    }

    return res;
}





// Recursive solution: NO DP
int MB(BMAP &b, int n, int k, int p)
{

    if (n < 0 || p <= 0)
    {
        return 0;
    }

    // For when we don't choose this program
    int currMax = MB(b, n - 1, k, p);

    for (int i = 0; i <= k; ++i)
    {
        int tmp = MB(b, n - 1, k - i - 1, p - i - 1) + b[n][i];
        if (tmp > currMax)
        {
            currMax = tmp;
        }
    }

    return currMax;
}





int main()
{

    BMAP test = {
        {2,4,12,5,8,35},
        { 40,40,30,15,8,45 },
        { 2,11,21,5,8,19 },
        { 6,4,21,5,18,19 },
        { 2,4,3,7,8,23 },
    };

    BMAP test2 = {
        { 2,4,12 },
        { 30,4, 2 },
        { 2,4,20}
    };

    int res = MB(test, 4, 5, 6);

    int res2 = MaxBenefit(test, 6, 5);


    return 0;
}