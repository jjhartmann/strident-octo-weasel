// LC_StringToInt.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

#include <string>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int myAtoi(string s) {
    if (s.empty()) return 0;
    
    // Remove white space
    int i = 0;
    while (s[i] == ' ') { ++i; }
    if (i > 0)
    {
        s.erase(0, i);
    }

    bool neg = false;
    if (s[0] == '-' || s[0] == '+') {
        neg = s[0] == '-';
        s.erase(0, 1);
    }
    else if (!isdigit(s[0]))
        return 0;

    i = 0; 
    while (s[i] == '0') { ++i; }
    if (i > 0)
    {
        s.erase(0, i);
    }

    i = 0;
    while (i < s.size() && isdigit(s[i])) { ++i; }
    if (i < s.size()) {
        s.erase(i, s.size() - i);
    }

    // Calc Number
    int ret = 0;
    int p = s.size() - 1;
    for (int i = 0; i < s.size(); ++i, --p) {
        int tmp = (int) s[i] - '0';
        ret += (tmp * pow(10, p));
    }
    
    if (neg) ret *= -1;
    if (ret < 0 && !neg) ret = INT_MAX;
    if (ret > 0 && neg) ret = INT_MIN;
    
    
    return ret;
}


int main() {

    int res = myAtoi("    -04f");
    return 0;
}

