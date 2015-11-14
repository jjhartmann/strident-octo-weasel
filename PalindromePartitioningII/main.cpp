#include <iostream>
#include <map>
#include <unordered_map>
#include <stack>
#include <string>
#include <vector>
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
        BuildBasePalindrome(s);

        // (2) Match all base palindromes and build into meta-palindromes if possible.
        BuildMetaPalindrome();
    }

private:
    void BuildMetaPalindrome()
    {

    }

    //////////////////////////////////////////////////
    // Building the base palindromes in O(n) time.
    void BuildBasePalindrome(string s)
    {
        // Search for all smallest palindromes.
        for (int i = 0; i < s.size(); ++i)
        {
            // if empty add c
            if (m_memory.empty())
            {
                m_memory.push(s.at(i));
                continue;
            }

            // Else Check for adjacent chars in string
            i = Construct(i, s);
        }

        // Add rest of m_memory to map
        if (!m_memory.empty())
        {
            int ri = s.size() - 1;
            while(!m_memory.empty())
            {
                AddToMap(ToStr(m_memory.top()), ri--);
                m_memory.pop();
            }
        }
    }

    // Store metapalindromes
    int Construct(int i, string &s)
    {
        int index = i;
        int rindex = 0;
        string curr_palindrom;
        if (m_memory.top() != s.at(index) &&
            !(index + 1 < s.size() && m_memory.top() == s.at(index + 1)))
        {
            //Nothing matches. add to queue
            m_memory.push(s.at(index));
            return index;
        }

        // Set up even odd palindromes.
        if (index + 1 < s.size() && m_memory.top() == s.at(index + 1))
        {
            rindex = index-1;
            curr_palindrom =  ToStr(s.at(index++));
        }
        else
        {
            rindex = index - 1;
        }

        // Start extraction
        bool match = true;
        while (!m_memory.empty())
        {
            if (match && index < s.size() && m_memory.top() == s.at(index))
            {
                curr_palindrom = ToStr(m_memory.top()) + curr_palindrom + ToStr(s.at(index++));
                m_memory.pop();
            }
            else
            {
                AddToMap(ToStr(m_memory.top()), rindex);

                cout << "TEST CURR_PALIN:\t" << m_memory.top() << endl;
                m_memory.pop();
                match = false;
            }

            // Inc/De index
            --rindex;
        }

        // add current palindrom to metaMap
        AddToMap(curr_palindrom, --index);
        cout << "TEST CURR_PALIN:\t" << curr_palindrom << endl;
        return index;
    }

    // Converts char to string
    string ToStr(const char c)
    {
        string s = string(1, c);
        return s;
    }

    /////////////////////////////////////////////////
    // Metamap helper functions
    void AddToMap(string s, int i)
    {
        vector<int> &ref = m_metaMap[s];
        ref.push_back(i);
    }

private:
    unordered_map<string, vector<int> > m_metaMap;
    stack<char> m_memory;
};

int main()
{
    Solution sol;

    string test1 = "abcdxxyxxyxxdcba";
    sol.minCut(test1);

    cout << "Finish" << endl;
    return 0;
}