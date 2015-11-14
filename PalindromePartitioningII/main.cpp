#include <iostream>
#include <map>
#include <stack>

using namespace std;

///////////////////////////////////////////////////////
// A brute force attempt would, by checking every poss-
// ible substring, conduct about N^2 comparisons. O(N^2).
// A better solution, to bring the comparisons down to
// possibly N, is by the following observations.
//
// Observations: A palindrome is:
// (1) Either self contained, and therefore complete.
// (2) Is composed of smaller sub-palindromes.
// (3) Therefore, if palindrome is not complete, the
//     sub-palindromes must be adjacent.
///////////////////////////////////////////////////////

class Solution {
public:
    int minCut(string s)
    {
        // (1) Extract all of the base palindromes.
        BuildMeta(s);
    }

private:
    void BuildMeta(string s)
    {
        string curr_palindrom = "";
        // Search for all smallest palindromes.
        for (int i = 0; i < s.size(); ++i)
        {
            // if empty add c
            if (m_memory.empty())
            {
                m_memory.push(s.at(i));
                curr_palindrom = ToStr(s.at(i));
                continue;
            }

            // Else Check for adjacent chars in string
            Construct(i, curr_palindrom, s);
        }


    }

    // Store metapalindromes
    int Construct(int i, string &curr_palindrom, string s)
    {
        int index = i;
        int rindex = i;
        m_memory.pop();

        if (m_memory.top() == s.at(i))
        {
            //even
            curr_palindrom += ToStr(s.at(index));
        }
        else if (i + 1 < s.size() && m_memory.top() == s.at(i + 1))
        {
        // Odd palindrome.
            curr_palindrom = curr_palindrom + ToStr(s.at(index)) + ToStr(s.at(index + 1));
        }
        else
        {
            //Nothing matches. add to queue
            m_memory.push(s.at(i));
            curr_palindrom += ToStr(s.at(i));
            return index;
        }

        // Start extraction
        ++index;
        while (!m_memory.empty())
        {
            if (m_memory.top() == s.at(++index))
            {
                m_memory.pop();
                curr_palindrom += ToStr(s.at(index));
            }
            else
            {
                --index;
                m_MetaMap[rindex] = m_memory.top();
                m_memory.pop();
            }
            --rindex;
        }

        // add current palindrom to metaMap
        m_MetaMap[index] = curr_palindrom;
        curr_palindrom.clear();
        return index;
    }

    // Converts char to string
    string ToStr(const char c)
    {
        string s = string(1, c);
        return s;
    }


private:
    map<int, string> m_MetaMap;
    stack<char> m_memory;
};

int main()
{
    Solution sol;

    string test1 = "abadxyxdaba";
    sol.minCut(test1);

    return 0;
}