//////////////////////////////////////////////////////////////
// Cut two squares in Half

#include <iostream>

using namespace std;

// Square Class, describes a square object. 
class Square
{
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



int main()
{

    cout << "Cut Two Squares In Half with One Line" << endl;
    Square sq1(1, 7, 5, 4);
    Square sq2(4, 5, 8, 0);



    return 0;
}
