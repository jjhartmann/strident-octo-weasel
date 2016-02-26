// fibNumbers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <vector>

using namespace std;

int fibhelp(int n, vector<int> &buf)
{
    if (n == 3)
    {
        return 2;
    }
    else if (n <= 2)
    {
        return 1;
    }

    if (buf[n] > 0)
        return buf[n];

    buf[n] = fibhelp(n - 1, buf) + fibhelp(n - 2, buf);
    return buf[n];
}

int fib(int n)
{
    vector<int> buf(n, 0);
    return fibhelp(n, buf);
}

// To execute C++, please define "int main()"
int main() {

    int res = fib(10);

    cout << "Answer: " << res << endl;

}
