///////////////////////////////////////////////////////////////
// Main - Bit Twiddling

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

/////////////////////////////////////////////////////////////
// Given two 32 bit ints, and two value range. Merge the integers. 
int MergeInt(int N, int M, int i, int j)
{
    int len = j - i + 1;
    int mmask = ~(~0 << len);
    
    // Clear all MSBs
    M = M & mmask;

    // Clear N range
    N = N & ~(mmask << i);

    // merge values
    return N | (M << i);

}


////////////////////////////////////////////////////////////
// Print binary representation of Decimal Fraction. 
void DecimalFracToBin(double num)
{
    string buffer = "0.";
    int i = 0;
    while (num != 0)
    {
        if (i >= 32)
        {
            buffer = "ERROR";
            break;
        }

        num *= 2;
        buffer += to_string((int)floor(num));

        num = (num >= 1.0) ? double(num - (double) 1.0) : num;
        ++i;
    }

    cout << buffer;
}


/////////////////////////////////////////////////////////
// Print Binary from Decimal Fraction alternative
void DecimalFracToBinAlt(double num)
{
    string buffer = "0.";
    int i = 0;
    double mfrac = 0.5;
    while (num != 0)
    {
        if (i >= 32)
        {
            buffer = "ERROR";
            break;
        }

        if (num >= mfrac)
        {
            buffer += "1";
            num = num - mfrac;
        }
        else
        {
            buffer += "0";
        }

        mfrac = mfrac / 2;
        ++i;
    }

    cout << buffer;
}


int main()
{
    cout << "Collection of Bit Twiddling Hacks" << endl;
    
    //int res = MergeInt(23, 11, 2, 6);
    DecimalFracToBinAlt(0.625);

    return 0;
}