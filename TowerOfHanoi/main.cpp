#include <iostream>
#include <stack>

using namespace std;

enum {
    AB = 0,
    AC,
    BA,
    BC,
    CA,
    CB,
};

class Solution
{
public:
    static void solveHanoi(int n)
    {
        stack<int> towerA;
        stack<int> towerB;
        stack<int> towerC;

        // Build the tower A.
        for ( int i = n; i > 0; --i)
        {
            towerA.push(i);
        }

        // First move
        if (n % 2 == 0)
        {
            towerB.push(towerA.top());
            towerA.pop();
        }
        else
        {
            towerC.push(towerA.top());
            towerA.pop();
        }

        // Solve the tower iteratively
        while (!towerA.empty() || !towerB.empty())
        {


        }

    }
};

int main()
{
    cout << "Solve the tower of Hanoi by using 3 stacks." << endl;

    return 0;
}