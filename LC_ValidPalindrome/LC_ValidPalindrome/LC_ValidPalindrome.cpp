// LC_ValidPalindrome.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>


bool isPalindrome(std::string s) {
    auto begin = s.begin();
    auto end = s.end();
    --end;

    while(begin != end) {
        while (!isalnum(end[0])) { --end; }
        while (!isalnum(begin[0])) { ++begin; }

        if(tolower(begin[0]) != tolower(end[0])) return false;
        --end;
        ++begin;
    }

    return true;
}


int main() {

    bool res = isPalindrome("This siht");
    return 0;
}

