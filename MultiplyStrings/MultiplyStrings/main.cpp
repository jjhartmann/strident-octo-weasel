//////////////////////////////////////////////////////////////////////
// Multiply Strings
//       Given two numbers represented as strings, return multiplication of the numbers as a string.
//       Note: The numbers can be arbitrarily large and are non - negative.

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cstdlib>

using namespace std;

// Struct to represent disembodied numer
struct NumberD
{
    int val;
    int exp;
};


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


// Build vector
void buildNumVec(string str, vector<NumberD> &vec)
{
    int slen = str.length();
    int i = max(slen - 4, 0);
    int exp = 0;
    int len = 4;
    while (len > 0)
    {
        NumberD num;
        string valstr = str.substr(i, len);
        int val = atoi(valstr.c_str());

        num.val = val;
        num.exp = exp;
        vec.push_back(num);

        if (i - 4 < 0) {
            len = i;
            i = 0;
        }
        else {
            i -= 4;
        }

        exp += 4;
    }
}

// Multiple Vectors
vector<NumberD> multipleVector(vector<NumberD> &avec, vector<NumberD> &bvec)
{
    vector<NumberD> res;
    
    int asize = avec.size();
    int bsize = bvec.size();

    for (int i = 0; i < asize; ++i)
    {
        for (int j = 0; j < bsize; ++j)
        {
            NumberD temp;
            temp.val = avec[i].val * bvec[j].val;
            temp.exp = avec[i].exp + bvec[j].exp;
            res.push_back(temp);
        }
    }

    return res;
}

// Convert to string
vector<string> convertVecToString(vector<NumberD> vec)
{
    vector<string> res;
    for (int i = 0; i < vec.size(); ++i)
    {
        string temp = to_string(vec[i].val);

        for (int j = 0; j < vec[i].exp; ++j)
        {
            temp += "0";
        }

        res.push_back(temp);
    }

    return res;
}

// Multiply Two Strings
string multiplyString(string a, string b)
{
    int alen = a.length();
    int blen = b.length();

    vector<NumberD> avec;
    vector<NumberD> bvec;

    buildNumVec(a, avec);
    buildNumVec(b, bvec);

    // Multiply components and merge. 
    vector<NumberD> resvec = multipleVector(avec, bvec);

    // Convert resvect to strings
    vector<string> resStr = convertVecToString(resvec);

    // Add Strings together
    string product = "0";
    for (int i = 0; i < resStr.size(); ++i)
    {
        product = addStrings(resStr[i], product);
    }

    return product;
}

class Solution {
public:
    string multiply(string num1, string num2) {

        int alen = num1.length();
        int blen = num2.length();

        vector<NumberD> avec;
        vector<NumberD> bvec;

        buildNumVec(num1, avec);
        buildNumVec(num2, bvec);

        // Multiply components and merge. 
        vector<NumberD> resvec = multipleVector(avec, bvec);

        // Convert resvect to strings
        vector<string> resStr = convertVecToString(resvec);

        // Add Strings together
        string product = "0";
        for (int i = 0; i < resStr.size(); ++i)
        {
            product = addStrings(resStr[i], product);
        }

        return product;
    }
};

int main()
{
    cout << "Multiply Strings" << endl;
    int res = countInteger(123456789);
    
    Solution sol;


    string sum = addStrings("92258441254412541111221122211443", "99855566658477412554412155444188");
    string test = sol.multiply("9212518930487213973668059034619153835677898283391567122521443284", "9212518930487213973668059034619153835677898283391567122521443284");
    return 0;
}