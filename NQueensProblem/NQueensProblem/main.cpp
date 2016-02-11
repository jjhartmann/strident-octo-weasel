//////////////////////////////////////////////////////////////
// Main - N Queens Problem

#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> Point;

////////////////////////////////////////////////////////////////
// Chessboard Class
class ChessBoard
{
public:
    ChessBoard(int n) :
        mDim(n),
        mBoard(n*n, false)
    {
        ;
    }

    int getDimensions()
    {
        return mDim;
    }

    void mark(Point p)
    {
        if (p.first >= mDim || p.second >= mDim) return;

        mBoard[p.second * mDim + p.first] = true;
    }

private:
    vector<bool> mBoard;
    int mDim;
};

////////////////////////////////////////////////////////////////
// Queen Class
class Queen
{
public:
    Queen() :
        mPlacement(-1, -1)
    {}
    bool isPlaced()
    {
        if (mPlacement.first > 0)
            return true;

        return false;
    }

    // Place and mark chess board
    void place(Point p, ChessBoard b)
    {
        mPlacement = p;

        int dim = b.getDimensions();

        Point diag2(p.first, p.second);
        for (int i = 0; i < dim; i++)
        {
            if (diag2.first - 1 < 0  || diag2.second >= dim)
                break;

            diag2.first--;
            diag2.second++;
        }
       
        for (int i = 0; i < dim; ++i)
        {
            // Column
            b.mark(Point(p.first, i));
            
            // Row
            b.mark(Point(i, p.second));

            // Diagonal one
            int orientation = p.first < p.second;
            int dx = (p.first + i) % dim;
            int dy = (p.second + i) % dim;
            if (orientation == dx < dy);
            {
                b.mark(Point(dx, dy));
            }


            // Diagonal two
            if (diag2.first + 1 < dim && diag2.second >= 0)
            {
                b.mark(diag2);
                diag2.first++;
                diag2.second--;
            }


        }


    }


private:
    Point mPlacement;

};

int main()
{
    cout << "The N-Queens Problem" << endl;




    return 0;
}