/////////////////////////////////////////////////////////////////
// Main - Find the number of ways to represent n cents using 
// 25c, 10c, 5c, 1c

#include <iostream>

using namespace std;

int MakeChange(int n, int denomination)
{
    int next_denom = 0;
    switch (denomination)
    {
    case 25:
        next_denom = 10;
        break;
    case 10:
        next_denom = 5;
        break;
    case 5:
        next_denom = 1;
        break;
    case 1:
    default:
        return 1;
        break;
    }

    int nWays = 0;
    for (int i = 0; i <= n; i += denomination)
    {
        nWays += MakeChange(n - i, next_denom);
    }

    return nWays;
}


int main()
{
    cout << "Determine the number of ways to represent n cents using quarters, nickels, dimes, and cents." << endl;
    int res = MakeChange(100, 25);



    return 0;
}