// LC_ValidPalindrome.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool isPalindrome(std::string s) {
    int i = 0; 
    int j = s.size() - 1;
    while (i <= j) {
        while (i < s.size() && !isalnum(s[i])) { ++i; }
        while (j >= 0 && !isalnum(s[j])) { --j; }
        if (i < j && tolower(s[i]) != tolower(s[j])) {
            return false;
        }
        --j;
        ++i;
    }

    return true;
}



int main() {

    bool res = isPalindrome(" ");
    return 0;
}

