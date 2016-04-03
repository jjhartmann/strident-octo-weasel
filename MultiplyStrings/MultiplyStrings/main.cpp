//////////////////////////////////////////////////////////////////////
// Multply Strings
//       Given two numbers represented as strings, return multiplication of the numbers as a string.
//       Note: The numbers can be arbitrarily large and are non - negative.

#include <iostream>

using namespace std;

int countInteger(int x)
{
    int sz = sizeof(int) * 8;

    int c = 0;
    for (int i = 0; i < sz; ++i)
    {
        if ((x & (1 << i)) > 0)
        {
            c = i;
        }
    }

    return c;
}

string addStrings(string a, string b)
{

    return "";
}


int main()
{
    cout << "Multiply Strings" << endl;
    int res = countInteger(123456789);
    


    return 0;
}