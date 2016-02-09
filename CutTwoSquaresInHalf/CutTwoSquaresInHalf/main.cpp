//////////////////////////////////////////////////////////////
// Cut two squares in Half

#include <iostream>
#include <limits>

using namespace std;

// Square Class, describes a square object. 
class Square
{
public:
    // Static Functions: cut square in half with another
    // Return: Pair< m, b> ==> mx + b
    static pair<float, float> CutSquaresInHalf(Square sq1, Square sq2)
    {
        pair<float, float> line;

        // If the centers have the same x val. 
        if (sq1.mCenter.first == sq2.mCenter.first)
        {
            line.first = numeric_limits<float>::infinity();
            line.second = sq2.mCenter.second;

            return line;
        }

        // Compute slope
        line.first = (sq1.mCenter.second - sq2.mCenter.second) / (sq1.mCenter.first - sq2.mCenter.first);
        
        // Compute y-intercept
        line.second = sq1.mLuxy.second - (line.first * sq1.mLuxy.first);

        return line;

    }

public:
    Square(int leftUpperX, int leftUpperY, int rightBottomX, int rightBottomY) :
        mLuxy(leftUpperX, leftUpperY),
        mRbxy(rightBottomX, rightBottomY)
    {
        // Determine over corners. 
        mLbxy = pair<int, int>(leftUpperX, rightBottomY);
        mRuxy = pair<int, int>(rightBottomX, leftUpperY);

        // Find center of square
        float cx = (float)(rightBottomX + leftUpperX) / 2;
        float cy = (float)(leftUpperY + rightBottomY) / 2;
        
        mCenter = pair<float, float>(cx, cy);

        // Compute area
        mArea = abs((rightBottomX - leftUpperX) * (rightBottomY - leftUpperY));
    }


private:
    pair<int, int> mLuxy; // left upper corner
    pair<int, int> mLbxy; // left bottom corner
    pair<int, int> mRuxy; // right upper corner
    pair<int, int> mRbxy; // right bottom corner
    pair<float, float> mCenter; // Center pos
    int mArea; // in cm^2
};

// 



int main()
{

    cout << "Cut Two Squares In Half with One Line" << endl;
    Square sq1(1, 7, 5, 4);
    Square sq2(4, 5, 8, 0);
    pair<float, float> line = Square::CutSquaresInHalf(sq1, sq2);


    return 0;
}
