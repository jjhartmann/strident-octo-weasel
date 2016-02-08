///////////////////////////////////////////////////////////////
// Main - Bit Twiddling

#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;
typedef unsigned int UINT;

/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
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


/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
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

/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
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
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
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


// Find the next smallest with arithmetic hack
UINT getPrevArith(UINT n)
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

    // Opposite of larger hack.
    return ((n - (pow(2, count1) - 1)) - 1) - (pow(2, count0 - 1) - 1);
}


/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
// Determine the number of bits differing between two numbers
int GetNumberofDifferingBits(UINT n, UINT m)
{
    // Use xor and then count bits. 
    int delta = n ^ m; 
    
    int i = 0;
    while (delta)
    {
        delta = delta & (delta - 1);
        ++i;
    }


    return i;
}

/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
// Swap the odd and even bits with as few operations as possible. 
int SwapOddEvenPairs(UINT n)
{
    // Use an xAA.. mask -> 10101010. 
    // THen shift all odd right by one. 
    // Shift all even left by one using the mask. 
    // Merge with |
    UINT amask = 0xAAAAAAAA;

    return ((n & amask) >> 1) | ((n & ~amask) << 1);
}



/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
// Find missing number from array with only access to the bits. 
UINT findmissingNumber(vector<UINT> vec, int col)
{
    if (col >= 32)
    {
        return 0; // Length of integer exceeded. 
    }

    // Make vector for onebits and zerobits
    vector<UINT> onebit;
    vector<UINT> zerobit;

    // partition array by bits at col. 
    for (UINT i : vec)
    {
        if (getBit(i, col))
        {
            onebit.push_back(i);
        }
        else
        {
            zerobit.push_back(i);
        }
    }

    // Check size, smaller signifies the missing bit. 
    if (zerobit.size() <= onebit.size())
    {
        UINT n = findmissingNumber(zerobit, col + 1);
        return (n << 1);
    }
    else
    {
        UINT n = findmissingNumber(onebit, col + 1);
        return (n << 1) | 1;
    }
}

// start
UINT findmissingNumber(vector<UINT> vec)
{
    return findmissingNumber(vec, 0);
}


int main()
{
    cout << "Collection of Bit Twiddling Hacks" << endl;
    
    //int res = MergeInt(23, 11, 2, 6);
    //DecimalFracToBinAlt(0.625);
    //PrintLowHigh((unsigned int)88);
    //getNext((UINT)3815);
    //int res1 = getNext((UINT)3804);
    //int res2 = getNextAirth((UINT)3804);
    //int res3 = getPrev((UINT)3815);
    //int res4 = getPrevArith((UINT)3815);
    //int res5 = GetNumberofDifferingBits(3806, 3385);
    //int res6 = SwapOddEvenPairs(999);

    // Missing 11.
    vector<UINT> test = { 0,1,2,3,4,5,6,7,8,9,10,12,13,14,15,16,17,18,19,20,21,22,23 };
    int res7 = findmissingNumber(test);

    return 0;
 }