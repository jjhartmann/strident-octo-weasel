// LC_LongestSubstringTwoRepeatedChar.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>


using namespace std;

int lenOfLongestSubstringTwochar(string s) {

    int i = 0, j = -1, maxlen = 0;
    for (int k = 1; k < s.size(); ++k )
    {
        if (s[k] == s[k - 1]) continue;
        if (j >= 0 && s[j] != s[k])
        {
            maxlen = max(k - i, maxlen);
            i = j + 1;
        }
        j = k - 1;

    }

    return maxlen;
}

int main() {

    int len = lenOfLongestSubstringTwochar("exeba");
    return 0;
}
