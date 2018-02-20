// LC_ReverseWordString.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <stack>

using namespace std;


void reverseWords(string &s) {
    string reversed;
    int j = s.size();
    for (int i = s.size() - 1; i >= 0; --i)
    {
        if (s[i] == ' ') j = i;
        else if (i == 0 || s[i-1] == ' ')
        {
            if (reversed.size() > 0)
            {
                reversed += " ";
            }
            reversed += s.substr(i, j - i);
        }
    }

    s = reversed;
}

void reverseWords2(string &s) {

    if (s.empty()) return;

    stack<string> buffer;
    bool valid = false;
    for (int i = 0; i < s.size(); ++i) {
        while (i < s.size() && s[i] == ' ') { ++i; }
        
        int j = i;
        while (j < s.size() && s[j] != ' ')
        {
            ++j;
            valid = true;
        }

        if (j - i > 0) 
            buffer.push(s.substr(i, j - i));
    
        i = j;
    }

    if (!valid)
    {
        s = "";
        return;
    }

    s = buffer.top();
    buffer.pop();
    while (!buffer.empty()) {
        s = s + " " + buffer.top();
        buffer.pop();
    }
}


int main() {
     
    string str = "   a   ";
    reverseWords(str);

    return 0;
}

