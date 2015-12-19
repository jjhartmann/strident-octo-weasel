#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {

    }


private:
    // Determine if two strings are connected by a char diffence.
    bool checkForEdge(string str1, string str2)
    {
        bool diff = false;
        for (int i = 0; i < str1.length(); ++i)
        {
            if (str1[i] != str2[i])
            {
                if (diff)
                {
                    return false;
                }

                diff = true;
            }
        }

        return true;
    }
};

int main()
{
    cout << "Word Ladder II" << endl;
    return 0;
}