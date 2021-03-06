// LC_StringToInt.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

#include <string>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int myAtoi(string s)
{
    if (s.empty()) return 0;

    int index = 0; 
    while (s[index] == ' ') { ++index; }

    int sign = 1;
    if (index < s.size() && s[index] == '-')
    {
        sign = -1;
        ++index;
    }
    else if (index < s.size() && s[index] == '+')
    {
        sign = 1;
        ++index;
    }

    int ret = 0;
    int len = 0;
    while(index < s.size() && isdigit(s[index]))
    {
        int tmp = (int)s[index] - '0';
        ret = ret * 10 + tmp;

        ++len;
        ++index;
        
        // Check overflow
        if (ret < 0 || len > 10)
        {
            if (sign < 0)
                return INT_MIN;
            return INT_MAX;
        }

    }

    return ret * sign;
}


int myAtoi2(string s) {
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

        if (ret < 0)
        {
            if (neg)
                return INT_MIN;
            return INT_MAX;
        }
    }
    
    if (neg) ret *= -1;
    
    return ret;
}


int main() {

    int res = myAtoi("    10522545459");
    return 0;
}

