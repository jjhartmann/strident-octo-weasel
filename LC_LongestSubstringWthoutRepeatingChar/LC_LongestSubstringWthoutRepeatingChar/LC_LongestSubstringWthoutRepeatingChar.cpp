// LC_LongestSubstringWthoutRepeatingChar.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int lengthOfLongestSubstring(string s) {

    int buffer[128];
    memset(buffer, -1, sizeof(buffer));

    int maxlen = 0;
    int j = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (buffer[(int)s[i]] >= j) {
            j = buffer[(int)s[i]] + 1;
        }

        buffer[(int)s[i]] = i;

        // Set max
        maxlen = (i - j + 1 > maxlen) ? i - j + 1 : maxlen;

    }

    return maxlen;
}


int main() {

    int res = lengthOfLongestSubstring("ajkdlkakdasdklfasdf");

    return 0;
}
