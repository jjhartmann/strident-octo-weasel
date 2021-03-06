// LC_MissingRanges.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <string>
#include <vector>
#include <map>



using namespace std;


vector<string> missingRanges(vector<int> numbers) {
    vector<string> ret;
    if (numbers.empty()) {
        ret.push_back("0->99");
        return ret;
    }

    int first = numbers[0];
    if(first != 0) {
        ret.push_back("0->" + to_string(first));
    }

    for (int i = 0; i < numbers.size() - 1; ++i) {
        int curr = numbers[i];
        int next = numbers[i + 1];
        if (curr + 1 == numbers[i + 1]) continue;
        if (abs(next - curr) == 1) {
            ret.push_back(to_string(next + 1));
            continue;
        }

        ret.push_back(to_string(curr) + "->" + to_string(next - 1));
    }

    int last = numbers[numbers.size() - 1];
    if (last != 99) {
        ret.push_back(to_string(last) + "->99");
    }

    return ret;
}


int main()
{

    missingRanges({ 2,3,4,5,52,76,88,91 });
    return 0;
}

