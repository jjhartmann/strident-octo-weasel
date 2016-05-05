///////////////////////////////////////////////////////////////////////
// Nim Game Leet Code

#include <iostream>

using namespace std; 

class Solution {
public:
    bool canWinNim(int n) {
        // Since both players are playing optimally, 
        // then any player going first will lose if 
        // the stack is divisible by 4
        return !(n % 4 == 0);
    }
};


int main()
{
    cout << "Nim Game" << endl;

    Solution sol;

    bool res = sol.canWinNim(4);


    return 0;
}