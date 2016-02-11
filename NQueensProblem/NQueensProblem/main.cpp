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
        mBoard(n*n, "-")
    {
        ;
    }

    int getDimensions()
    {
        return mDim;
    }

    void mark(Point p, string id = "+")
    {
        if (p.first >= mDim || p.second >= mDim) return;

        mBoard[p.second * mDim + p.first] = id;
    }

    void printBoard()
    {
        for (int i = 0; i < mDim; ++i)
        {
            for (int j = 0; j < mDim; ++j)
            {
                string tmp = mBoard[i * mDim + j] + " ";
                cout << tmp.c_str();
            }
            cout << endl;
        }
        cout << endl;
    }

    bool isFree(Point p)
    {
        if (p.first >= mDim || p.second >= mDim) return false;

        return mBoard[p.second * mDim + p.first] == "-";
    }

    // Is in range
    bool isInRange(Point p)
    {
        return p.first < mDim && p.second < mDim;
    }

private:
    vector<string> mBoard;
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
    void place(Point p, ChessBoard &b)
    {
        mPlacement = p;

        int dim = b.getDimensions();


        Point diag1(p.first, p.second);
        for (int i = 0; i < dim; i++)
        {
            if (diag1.first - 1 < 0 || diag1.second - 1 < 0)
                break;

            diag1.first--;
            diag1.second--;
        }

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
            if (diag1.first < dim && diag1.second < dim);
            {
                b.mark(diag1);
                diag1.first++;
                diag1.second++;
            }

            // Diagonal two
            if (diag2.first< dim && diag2.second >= 0)
            {
                b.mark(diag2);
                diag2.first++;
                diag2.second--;
            }
        }

        // Mark Queen
        string id = "X";
        b.mark(mPlacement, id);

    }


private:
    Point mPlacement;

};

/////////////////////////////////////////////////////////////
// Game: 
class Game
{
public:
    Game(int mDim, int nQueens) :
        mQueen(nQueens),
        mBoard(mDim)
    {
        ;
    }

    ~Game()
    {
        ;
    }

    // Find Configurations for n Queens
    bool Process()
    {
        Point start(0, 0);
        int qIndex = 0;
        while (mBoard.isInRange(start))
        {
            
            for (int i = 0; i < mQueen.size(); ++i)
            {
                Point p(0, 0);
                bool placed = false;
                while(mBoard.isInRange(p) && !placed)
                {
                    // Set col to 0
                    p.first = 0;
                    while (mBoard.isInRange(p) && !placed)
                    {
                        if (mBoard.isFree(p))
                        {
                            mQueen[i].place(p, mBoard);
                        }

                        // INcrement col
                        p.first++;
                    }

                    // Increment row
                    p.second++;
                }

            }

        }
    }



private:
    vector<Queen> mQueen;
    ChessBoard mBoard;

};

int main()
{
    cout << "The N-Queens Problem" << endl;
    ChessBoard b(20);
    b.printBoard();

    Queen firstQ;
    firstQ.place(Point(10, 3), b);
    b.printBoard();


    return 0;
}