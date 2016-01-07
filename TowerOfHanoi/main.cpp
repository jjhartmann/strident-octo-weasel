#include <iostream>
#include <stack>
#include <vector>

using namespace std;
typedef pair<string, stack<int> > TOWER_STACK;


enum MOVE {
    AB = 3,
    AC = 5,
    BC = 6,
};

enum TOWER_TYPE
{
    A = 0,
    B = 1,
    C = 2,
};


class Solution
{
public:
    // Iterative Solution to the tower of hanoi
    static int solveHanoi(int n)
    {
        vector< stack<int> > tower(3);
        int MAX = n + 1;
        // Build the tower A.
        for ( int i = n; i > 0; --i)
        {
            tower[A].push(i);
        }

        // First move
        if (n % 2 == 0)
        {
            tower[B].push(tower[A].top());
            tower[A].pop();
            mPrevMove = AB;
            cout << "MOVE: A --> B" << endl;
        }
        else
        {
            tower[C].push(tower[A].top());
            tower[A].pop();
            mPrevMove = AC;
            cout << "MOVE: A --> C" << endl;
        }

        // Solve the tower iteratively
        bool opt = false;
        while (!tower[A].empty() || !tower[B].empty())
        {
            int a = !(tower[A].empty()) ? tower[A].top() : MAX;
            int b = !(tower[B].empty()) ? tower[B].top() : MAX;
            int c = !(tower[C].empty()) ? tower[C].top() : MAX;
            bool aEven = a % 2 == 0;
            bool bEven = b % 2 == 0;
            bool cEven = c % 2 == 0;
            bool aEmpty = tower[A].empty();
            bool bEmpty = tower[B].empty();
            bool cEmpty = tower[C].empty();


            // Check moves A <-->B
            if (mPrevMove != AB  && (aEven != bEven || b == MAX || a == MAX) && ((!aEmpty && !bEmpty) || opt))
            {
                if (a < b)
                {
                    tower[B].push(a);
                    tower[A].pop();
                    cout << "MOVE: A --> B" << endl;
                }
                else
                {
                    tower[A].push(b);
                    tower[B].pop();
                    cout << "MOVE: B --> A" << endl;
                }

                mPrevMove = AB;
                opt = false;
                ++mSize;
                continue;
            }

            //Check moves A <--> C
            if (mPrevMove != AC && (aEven != cEven || c == MAX || a == MAX) && ((!aEmpty && !cEmpty) || opt))
            {
                if (a < c)
                {
                    tower[C].push(a);
                    tower[A].pop();
                    cout << "MOVE: A --> C" << endl;
                }
                else
                {
                    tower[A].push(c);
                    tower[C].pop();
                    cout << "MOVE: C --> A" << endl;

                }

                mPrevMove = AC;
                opt = false;
                ++mSize;
                continue;
            }

            //Check moves B <--> C
            if (mPrevMove != BC && (bEven != cEven || b == MAX || c == MAX) && ((!bEmpty && !cEmpty) || opt))
            {
                if (b < c )
                {
                    tower[C].push(b);
                    tower[B].pop();
                    cout << "MOVE: B --> C" << endl;
                }
                else
                {
                    tower[B].push(c);
                    tower[C].pop();
                    cout << "MOVE: C --> B" << endl;
                }

                mPrevMove = BC;
                opt = false;
                ++mSize;
                continue;
            }

            opt = true;
        }

        return mSize;

    }


    // Recursive solution to the tower of hanoi
    static void solveHanoiRecursive(int n)
    {
        TOWER_STACK towerA("A", stack<int>());
        TOWER_STACK towerB("B", stack<int>());
        TOWER_STACK towerC("C", stack<int>());

        int MAX = n + 1;
        // Build the tower A.
        for ( int i = n; i > 0; --i)
        {
            towerA.second.push(i);
        }

        hanoiRecursive(n, towerA, towerC, towerB);

        cout << "FINISH" << endl;
    }

private:
    static void hanoiRecursive(int n, TOWER_STACK &towerA, TOWER_STACK &towerC, TOWER_STACK &towerB)
    {
        // Base case
        if (n <= 0) return;

        // Move the n-1 disk from towerA to towerB
        hanoiRecursive(n - 1, towerA, towerB, towerC);

        //Move top of A to C
        moveTop(towerA, towerC);

        // move n-1 disk from towerB to towerC
        hanoiRecursive(n - 1, towerB, towerC, towerA);
    }

    static void moveTop(TOWER_STACK &origin, TOWER_STACK &dest)
    {
        dest.second.push(origin.second.top());
        origin.second.pop();

        cout << "MOVE: " << origin.first << " --> " << dest.first << endl;
    }

    // Vars
    static MOVE mPrevMove;
    static int mSize;
};

// Initialize static variable
MOVE Solution::mPrevMove = (MOVE) 0;
int Solution::mSize = 0;

int main()
{
    cout << "Solve the tower of Hanoi by using 3 stacks." << endl;

    Solution::solveHanoiRecursive(4);

//    int res = Solution::solveHanoi(5);
//    cout << "TOTAL STEPS: " << res << endl;
    return 0;
}