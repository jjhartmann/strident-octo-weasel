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

    return 0;
}



int main()
{

    BMAP test = {
        {2,4,12,5,8,29},
        { 4,4,2,15,8,19 },
        { 2,4,12,5,8,19 },
        { 5,4,1,5,18,19 },
        { 2,4,3,7,8,23 },
    };

    MaxBenefit(test, 6, 5);


    return 0;
}