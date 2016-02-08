///////////////////////////////////////////////////////////////
// Main - Bit Twiddling

#include <iostream>
#include <string>
#include <cmath>

using namespace std;
typedef unsigned int UINT;

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



/////////////////////////////////////////////////////////////////
// Given a positive integer, print the lowest and highest possible
// integer with the same number of 1 bits. 
void PrintLowHigh(unsigned int num)
{
    int bits = 0;
    while (num)
    {
        if (num % 2)
        {
            ++bits;
        }

        num = num >> 1;
    }

    unsigned int low = (1 << bits) - 1;
    unsigned int high = (low << (32 - bits));


    cout << "LOW: " << low << "\nHIGH: " << high << endl;
}

/////////////////////////////////////////////////////////////////
// Given a positive integer, print the NEXT lowest and highest
// integer with the same number of 1 bits. 
bool getBit(UINT num, int index)
{
    return (num & (1 << index)) != 0;
}

UINT setBit(UINT num, int index, UINT v)
{
    UINT mmask = (1 << index);
    num = num & ~mmask;
    return num | (v << index);
}

// Swap the values of i and j
UINT swapBits(UINT num, int i, int j)
{

    UINT maski = (1 << i);
    UINT maskj = (1 << j);

    int ibit = (int) getBit(num, i);
    int jbit = (int) getBit(num, j);

    num = setBit(num, i, jbit);
    num = setBit(num, j, ibit);

    return num;

}

UINT getNext(UINT n)
{
    int num = n;
    int count0 = 0;
    int count1 = 0;

    // Count zeros
    while (!(num & 1) && num)
    {
        ++count0;
        num >>= 1;
    }

    // count 1s
    while ((num & 1) && num)
    {
        ++count1;
        num >>= 1;
    }

    if (count1 + count0 == 31) return -1;


    int pos = count1 + count0;
    // swap the count1 and count1 + 1 bits
    n = swapBits(n, pos, pos - 1);

    // Clear bits from count1 down to 0. 
    UINT mmask = ~((1 << pos) - 1);
    n &= mmask;

    // create LSB 
    UINT ones = (1 << (count1 - 1)) - 1;
    n |= ones;


    return n;

}

// get the next lowest integer with same amount of one bits
UINT getPrev(UINT n)
{
    int num = n;
    int count0 = 0;
    int count1 = 0;

    // count 1s
    while ((num & 1) && num)
    {
        ++count1;
        num >>= 1;
    }

    // Count zeros
    while (!(num & 1) && num)
    {
        ++count0;
        num >>= 1;
    }

    if (count1 + count0 == 31) return -1;


    int pos = count1 + count0;
    // swap the count1 and count1 + 1 bits
    n = swapBits(n, pos, pos - 1);

    // Clear bits from count1 down to 0. 
    UINT mmask = ~((1 << (pos - 1)) - 1);
    n &= mmask;

    // create LSB 
    UINT ones = (1 << count1) - 1;
    n |= (ones << (count0 -1));


    return n;
}


// Get Next highest Arithmetic hack
UINT getNextAirth(UINT n)
{
    int num = n;
    int count0 = 0;
    int count1 = 0;

    // Count zeros
    while (!(num & 1) && num)
    {
        ++count0;
        num >>= 1;
    }

    // count 1s
    while ((num & 1) && num)
    {
        ++count1;
        num >>= 1;
    }

    return ((n + (pow(2, count0) - 1)) + 1) + (pow(2, count1 - 1) - 1);
}




int main()
{
    cout << "Collection of Bit Twiddling Hacks" << endl;
    
    //int res = MergeInt(23, 11, 2, 6);
    //DecimalFracToBinAlt(0.625);
    //PrintLowHigh((unsigned int)88);
    //getNext((UINT)3815);
    int res1 = getNext((UINT)3804);
    int res2 = getNextAirth((UINT)3804);

    return 0;
 }