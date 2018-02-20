// LC_StringToInt.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

#include <string>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int myatoi(string s) {
    if (s.empty()) return 0;

    bool neg = false;
    if (s[0] == '-' || s[0] == '+') {
        neg = s[0] == '-';
        s.erase(0, 1);
    }
    else if (!isdigit(s[0]))
        return 0;

    int i = 0;
    while (i < s.size() && isdigit(s[i])) { ++i; }
    if (i < s.size() - 1) {
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

    return ret;
}


int main() {

    int res = myatoi("1285755748");
    return 0;
}

