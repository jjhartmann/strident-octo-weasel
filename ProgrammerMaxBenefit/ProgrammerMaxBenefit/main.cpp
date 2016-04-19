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
    while (k_tmp > 0)
    {
        int programmers = DP.front().second.second;
        if (k_tmp >= programmers)
        {
            cout << "Program Number: " << DP.front().second.first << "\tProgrammers: " << DP.front().second.second << "\tWeight: " << DP.front().first << endl;
            res += DP.front().first;
            k_tmp -= programmers;
        }
        
        pop_heap(DP.begin(), DP.end(), heapComp);
        DP.pop_back();
    }

    return res;
}


int MB(BMAP &b, int n, int k, int p)
{

    if (n < 0 || k < 0 || p <= 0)
    {
        return 0;
    }

    if (p < k)
    {
        return max(MB(b, n, k - 1, p), MB(b, n - 1, k, p));
    }

    return max(max(MB(b, n, k - 1, p - k - 1) + b[n][k], MB(b, n - 1, k, p - k - 1) + b[n][k]), max(MB(b, n, k - 1, p), MB(b, n - 1, k, p)));

}



int main()
{

    BMAP test = {
        {2,4,12,5,8,35},
        { 20,4,2,15,8,60 },
        { 2,4,20,5,8,19 },
        { 6,4,20,5,18,19 },
        { 2,20,3,7,8,23 },
    };

    int res = MB(test, 4, 5, 6);

    MaxBenefit(test, 6, 5);


    return 0;
}