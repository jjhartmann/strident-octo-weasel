// LC_ImplementStrStr.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int strStr(string haystack, string needle) {

    if(needle.size() > haystack.size()) return -1;

    hash<string> stringHash;
    size_t hs = stringHash(needle);
    for (int i = 0; i <= haystack.size() - needle.size(); ++i) {
        string substr = haystack.substr(i, needle.size());
        if (hs == stringHash(substr))
            return i;
    }

    return -1;
}

int strStrBF(string haystack, string needle) {
    if (needle.size() > haystack.size()) return -1;

    for (int i = 0; i <= haystack.size() - needle.size(); ++i) {
        bool found = true;
        for (int j = 0; j < needle.size(); ++j) {
            if (haystack[i + j] != needle[j]) {
                found = false;
            }
        }

        if (found) return i;
    }

    return -1;
}


int main() {

    int res = strStr(" ", " ");
    return 0;
}

