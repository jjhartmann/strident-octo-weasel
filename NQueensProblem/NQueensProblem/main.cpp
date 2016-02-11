//////////////////////////////////////////////////////////////
// Main - N Queens Problem

#include <iostream>
#include <vector>

using namespace std;

class ChessBoard
{
public:
    ChessBoard(int n) :
        mDim(n),
        mBoard(n*n, false)
    {
        ;
    }
private:
    vector<bool> mBoard;
    int mDim;
};

int main()
{
    cout << "The N-Queens Problem" << endl;




    return 0;
}