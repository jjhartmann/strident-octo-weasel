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
        int res = 0;
        for (int i = 0; i < y; ++i)
        {
            res += x;
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

};




int main()
{
    cout << "Implement Math operators (*, \\, -) with +" << endl;

    int results = 0;
    results = MathOpsWithAdd::Mutliple(3, 4);
    results = MathOpsWithAdd::Divide(32, 8);
    results = MathOpsWithAdd::Subtract(7, 3);


    return 0;
}