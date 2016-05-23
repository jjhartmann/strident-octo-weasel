//////////////////////////////////////////////////////////////////////
// Vaild Anagram
//
// Given two strings s and t, write a function to determine if t is an anagram of s.
//
// For example,
//   s = "anagram", t = "nagaram", return true.
//   s = "rat", t = "car", return false.
//
// Note:
// You may assume the string contains only lowercase alphabets.
//
// Follow up :
// What if the inputs contain unicode characters ? How would you adapt your solution to such case ?

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {

        if (s.length() != t.length()) return false;

        // Using map of 256 for all ascii chars. 
        int map[26];

        for (int i = 0; i < 26; i++) { map[i] = 0; }
        
        // map s
        for (int i = 0; i < s.length(); ++i)
        {
            map[s[i] - 'a']++;
        }

        // Check if anagram
        for (int i = 0; i < t.length(); ++i)
        {
            if (map[t[i] - 'a'] < 1)
            {
                return false;
            }

            map[t[i] - 'a']--;
        }

        return true;
    }
};

int main()
{
    cout << "Valid Anagram" << endl;



    return 0;
}


