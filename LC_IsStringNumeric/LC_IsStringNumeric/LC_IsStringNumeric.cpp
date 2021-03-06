// LC_IsStringNumeric.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;


bool isNumber(string s) {
    if (s.empty()) return false;

    int index = 0;
    int max = s.size() - 1;;
    while (index < s.size() && s[index] == ' ') { ++index; }
    while (max >= 0 && s[max] == ' ') { --max; }
    if (index > max) return false;
    if (max >= 0 && !(s[max] == '.' ||  isdigit(s[max]))) return false;

    if (index < max && (s[index] == '-' || s[index] == '+'))
        ++index;

    bool decimalFlag = false;
    bool eFlag = false;
    while (index <= max) {
        if(s[index] == '.'){
            if (decimalFlag) return false;
            decimalFlag = true;
        }
        else if (s[index] == 'e')
        {
            if (eFlag) return false;
            eFlag = true;
        }
        else if (!isdigit(s[index])) {
            return false;
        }
        ++index;
    }

    return index >= max;
}


int main() {

    bool res = isNumber(" ");
    return 0;
}
