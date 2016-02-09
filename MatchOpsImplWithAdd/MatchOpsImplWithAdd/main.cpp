///////////////////////////////////////////////////////////////////
// Main - Implement Math operators (*, /, -) with +

#include <iostream>

using namespace std;

//////////////////////////////////////////////////////////////////
// Math op class
class MathOpsWithAdd
{
public:
    // Multiply x * y
    static int Mutliple(int x, int y)
    {
        bool yNeg = false, xNeg = false;
        int maxitr = y;
        if (x < y)
        {
            // More efficient to iterate on small number
            return Mutliple(y, x);
        }

        if (y < 0)
        {
            yNeg = true;
            maxitr = Negate(y);
        }

        int res = 0;
        for (int i = 0; i < maxitr; ++i)
        {
            res += x;
        }

        if (yNeg)
        {
            res = Negate(res);
        }

        return res;
    }

    // Divide x / y
    static int Divide(int x, int y)
    {
        int res = 0;
        for (int i = 0; i < x; i += y)
        {
            ++res;
        }

        return res;
    }

    // Subtract x - y
    static int Subtract(int x, int y)
    {
        int res = 0;
        for (int i = y; i < x; ++i)
        {
            ++res;
        }

        return res;
    }

    // Negate numbers
    static int Negate(int x)
    {
        int SIGN = (x < 0) ? 1 : -1;
        int res = 0;
        while (x)
        {
            res += SIGN;
            x += SIGN;
        }

        return res;
    }

};




int main()
{
    cout << "Implement Math operators (*, \\, -) with +" << endl;

    int results = 0;
    results = MathOpsWithAdd::Mutliple(3, -4);
    results = MathOpsWithAdd::Divide(32, 8);
    results = MathOpsWithAdd::Subtract(7, -3);


    return 0;
}