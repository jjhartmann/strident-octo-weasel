#include <iostream>
#include <map>
#include <unordered_map>
#include <deque>
#include <string>
#include <vector>
#include <cmath>
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
        if (CheckPalindrome(s))
        {
            return 0;
        }

        // (1) Extract all of the base palindromes.
        BuildBasePalindrome(s);

        // (2) Match all base palindromes and build into meta-palindromes if possible.
//        BuildMetaPalindrome(s);
    }

private:
    //////////////////////////////////////////////////
    void BuildMetaPalindrome(const string &s)
    {
        for (auto &it : m_metaMap)
        {
            // only test strings greater then size 1.
            if (it.first.size() > 1 && it.second.size() > 1)
            {
                // Verify collisions.
                vector<int> c_vec = it.second;
                int size = c_vec.size();
                string b_pal = it.first;

                for (int i = 0; i < size; ++i)
                {
                    for (int j = i+1; j <= size; ++j)
                    {
                        // If j == size, then all cases have passed.
                        if (j == size)
                        {
                            // push substr to sol.
                            m_Solution.push_back(s.substr(c_vec[i] + 1, abs(c_vec[i] - c_vec[j-1]) - it.first.size()));
                            continue;
                        }

                        // Check inner substring for palindrome.
                        string substr = s.substr(c_vec[i] + 1, abs(c_vec[i] - c_vec[j]) - it.first.size());
                        if (!CheckPalindrome(substr))
                        {
                            // add to result base string c_vec[i].
                            if (i == j-1)
                            {
                                m_Solution.push_back(it.first);
                            }
                            else
                            {
                                // Store previous substring
                                m_Solution.push_back(b_pal + s.substr(c_vec[i] + 1, abs(c_vec[i] - c_vec[j-1]) - it.first.size()) + b_pal);
                                i = j-1; // set to current unused base palindrome.
                            }

                            j = size + 1; // if first compare fail, all others fail.
                            continue;
                        }
                    }
                }

            }
        }
    }

    //////////////////////////////////////////////////
    // Building the base palindromes in O(n) time.
    void BuildBasePalindrome(const string s)
    {
        // Search for all smallest palindromes.
        for (int i = 0; i < s.size(); ++i)
        {
            // if empty add c
            if (m_memory.empty())
            {
                m_memory.push_back(s.at(i));
                continue;
            }

            // Else Check for adjacent chars in string
            i = Construct(i, s);
        }

        // Add rest of m_memory to map
        if (!m_memory.empty())
        {
            while(!m_memory.empty())
            {
                AddToMap(ToStr(m_memory.front()));
                m_memory.pop_front();
            }
        }
    }

    //////////////////////////////////////////////////
    // Store metapalindromes
    int Construct(int i, const string &s)
    {
        int index = i;
        string curr_palindrom;
        if (m_memory.back() != s.at(index) &&
            !(index + 1 < s.size() && m_memory.back() == s.at(index + 1)))
        {
            //Nothing matches. add to queue
            m_memory.push_back(s.at(index));
            return index;
        }

        // Set up even odd palindromes.
        if (index + 1 < s.size() && m_memory.back() == s.at(index + 1))
        {
            curr_palindrom =  ToStr(s.at(index++));
        }

        // Start extraction
        bool match = true;
        while (!m_memory.empty())
        {
            if (match && index < s.size() && m_memory.back() == s.at(index))
            {
                curr_palindrom = ToStr(m_memory.back()) + curr_palindrom + ToStr(s.at(index++));
                m_memory.pop_back();
            }
            else
            {
                AddToMap(ToStr(m_memory.front()));
                m_memory.pop_front();
                match = false;
            }
        }

        // add current palindrome to metaMap
        AddToMap(curr_palindrom);
        return index - 1;
    }

    //////////////////////////////////////////////////
    // Check for palindrome in given string
    bool CheckPalindrome(string s)
    {
        for (int i = 0, j = s.size() - 1; i < s.size() / 2; ++i, --j)
        {
            if (s[i] != s[j])
            {
                return false;
            }
        }

        return true;
    }

    //////////////////////////////////////////////////
    // Checks for the single case that the entire string may be a palindrome.
    // Wondering if I should check this case in the beginning....
    bool CheckPalindromeEdge(string s, int r_index, int l_index)
    {
        while (r_index < s.size() && r_index >= 0)
        {
            if (s[r_index++] != s[l_index--])
            {
                return false;
            }
        }

        return true;
    }

    //////////////////////////////////////////////////
    // Converts char to string
    string ToStr(const char c)
    {
        string s = string(1, c);
        return s;
    }

    /////////////////////////////////////////////////
    // Metamap helper functions
    void AddToMap(string s)
    {
        // Get current size (index of s)
        vector<int> &ref = m_metaMap[s];
        ref.push_back(m_palindrome.size());

        m_palindrome.push_back(s);
    }

private:
    unordered_map<string, vector<int> > m_metaMap;
    vector<string> m_palindrome;
    vector<string> m_Solution;
    deque<char> m_memory;
};


//////////////////////////////////////////////////
//////////////////////////////////////////////////
int main()
{
    Solution sol;

    string test1 = "abcdxxyxxyxxdcba";
    string test2 = "zxxbxxcxxcxxz";
    string test3 = "zxxbxxcxxbxxz";
    sol.minCut(test2);

    cout << "Finish" << endl;
    return 0;
}