//////////////////////////////////////////////////////////////////////
// Multiply Strings
//       Given two numbers represented as strings, return multiplication of the numbers as a string.
//       Note: The numbers can be arbitrarily large and are non - negative.

#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdlib>

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
    int alen = a.length();
    int blen = b.length();
    int ad = 0; 
    int bd = 0;

    int maxlen = max(alen, blen);

    if (maxlen != alen){
        ad = blen - alen;
    }
    else {
        bd = alen - blen;
    }

    string res = "";

    int carry = 0;
    for (int i = maxlen - 1; i >= 0; --i)
    {
        char ac = ((i - ad) >= 0) ? a[i - ad] : '0';
        char bc = ((i - bd) >= 0) ? b[i - bd] : '0';

        int ai = atoi(&ac);
        int bi = atoi(&bc);
        int sum = ai + bi + carry;
        
        int lsb = (sum % 10);
        carry = static_cast<int>(floor(sum/10)) % 10;

        res = to_string(lsb) + res;
    }

    if (carry > 0)
    {
        res = to_string(carry) + res;
    }

    return res;
}


int main()
{
    cout << "Multiply Strings" << endl;
    int res = countInteger(123456789);
    
    string sum = addStrings("923", "88");

    return 0;
}