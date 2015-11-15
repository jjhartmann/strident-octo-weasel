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
        BuildMetaPalindrome();

        return m_Solution.size() - 1;
    }

private:
    //////////////////////////////////////////////////
    bool BuildMetaPalindrome()
    {
        // Check and find all meta-palindromes
        vector<bool> palindromeMap(m_palindrome.size(), false);

        for (auto it : m_metaMap)
        {
            if (it.second.size() > 1)
            {
                CheckMetaPalindrome(it.second,  palindromeMap);
            }
        }

        // Build Final Solution vector.
        string meta_str = "";
        for (int i = 0; i < m_palindrome.size(); ++i)
        {
            if (palindromeMap[i])
            {
                // Create meta-Palindrome
                meta_str += m_palindrome[i];
            }
            else
            {
                if (!meta_str.empty())
                {
                    m_Solution.push_back(meta_str);
                    meta_str.clear();
                }

                m_Solution.push_back(m_palindrome[i]);
            }
        }

        // Check last meta_str
        if (!meta_str.empty())
        {
            m_Solution.push_back(meta_str);
        }


        // Iterate over solution to perform unary set palindrome optimization
        vector<string> sol_opt(m_Solution);
        m_Solution.clear();
        for (int i = 0; i < sol_opt.size(); ++i)
        {
            string curr_pali = "";
            if (IsUnary(sol_opt[i])     &&
                i + 2 < sol_opt.size()  &&
                IsUnary(sol_opt[i + 2]) &&
                (sol_opt[i][0] == sol_opt[i+2][0]))
            {
                // Conduct Optimization
                string lStr = sol_opt[i];
                string rStr = sol_opt[i+2];
                int lSize = lStr.size();
                int rSize = rStr.size();

                string lSplit, rSplit;
                if (lSize > rSize)
                {
                    lSplit = lStr.substr(0, lSize - rSize);
                    rSplit = lStr.substr(lSplit.size(), lSize - lSplit.size());

                    curr_pali = rSplit + sol_opt[i + 1] + rStr;

                    m_Solution.push_back(lSplit);
                    m_Solution.push_back(curr_pali);

                }
                else
                {
                    lSplit = rStr.substr(0, lSize);
                    rSplit = rStr.substr(lSplit.size(), rSize - lSplit.size());

                    curr_pali = lStr + sol_opt[i + 1] + lSplit;

                    m_Solution.push_back(curr_pali);
                    m_Solution.push_back(lSplit);
                }

                i += 2;
            }
            else
            {
                m_Solution.push_back(sol_opt[i]);
            }
        }
    }

    //////////////////////////////////////////////////
    // Check it Palindrome is compsed of a unary set
    bool IsUnary(string s)
    {
        if (s.size() == 1 )
        {
            return true;
        }

        if (s[0] == s[1])
        {
            return true;
        }

        return false;
    }

    //////////////////////////////////////////////////
    bool CheckMetaPalindrome(vector<int> &bucket,  vector<bool> &palindromeMap)
    {
        for (int i = 0; i < bucket.size(); ++i)
        {
            for (int j = i + 1; j < bucket.size(); ++j)
            {
                if (!VerifyMeta(bucket[i], bucket[j], palindromeMap))
                {
                    // If false set i = j and continue with other comparisons
                    i = j-1;
                    j = bucket.size();
                }

                // If true, do nothing.
            }
        }
    }

    //////////////////////////////////////////////////
    bool VerifyMeta(int l_index, int r_index,  vector<bool> &palindromeMap)
    {
        int size = m_palindrome.size();
        int index = l_index;
        vector<bool> temp(palindromeMap);

        // Set initial base palindromes to true.
        temp[r_index] = true;
        temp[l_index] = true;

        while (r_index != l_index)
        {
            if (m_palindrome[--r_index] != m_palindrome[++l_index])
            {
                return false;
            }

            // Add to temp bool vect
            temp[r_index] = true;
            temp[l_index] = true;
        }

        // Add to temp vector.
        palindromeMap.swap(temp);
        return true;

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

        // Check Repeated elements in unary and binary set.
        char seed = curr_palindrom.front();
        int curr_size = curr_palindrom.size();
        string temp = curr_palindrom;
        int u_tracker = 0;
        while (index < s.size()     &&
                    (
                        (curr_size - 2 >= 0  &&  temp[curr_size - 2] == s.at(index)) &&
                        (seed == s.at(index) || (index + 1 < s.size() && temp.back() == s.at(index + 1)))
                    )
              )
        {
            temp += s.at(index++);
            curr_size++;
            u_tracker++;
        }

        if (CheckPalindrome(temp))
        {
            curr_palindrom = temp;
        }
        else
        {
            index = (index - u_tracker);
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
    string test4 = "zxxbxxcxxgxxz";
    string test5 = "jdjhrejaldjdjdjdhshhhhhsjskdkdqofakdjnkkdkaloeiekdjkfnkdakdkkkkslsldkdkkslaslllslsl";
    string test6 = "adjdjdjdkd";
    string test7 = "adjdjdjdkdaaaaa";
    string test8 = "caaaaaaaaaaaaaaaaaaaaaaaadjdjdjdaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    string test9 = "aaabaa";
    string test10 = "ppdjdQdjd";
    string test11 = "asdkfjaieafkdkdkdkdkdkdkalsakdkdkdkkkkkkkkkkkkkksjsjsjskkkkkkkkkkkkkkiejajdjskskskjadjkfasdfadfadf";
    string test12 = "ababbbabbaba";
    string test13 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    string test14 = "adabdcaebdcebdcacaaaadbbcadabcbeabaadcbcaaddebdbddcbdacdbbaedbdaaecabdceddccbdeeddccdaabbabbdedaaabcdadbdabeacbeadbaddcbaacdbabcccbaceedbcccedbeecbccaecadccbdbdccbcbaacccbddcccbaedbacdbcaccdcaadcbaebebcceabbdcdeaabdbabadeaaaaedbdbcebcbddebccacacddebecabccbbdcbecbaeedcdacdcbdbebbacddddaabaedabbaaabaddcdaadcccdeebcabacdadbaacdccbeceddeebbbdbaaaaabaeecccaebdeabddacbedededebdebabdbcbdcbadbeeceecdcdbbdcbdbeeebcdcabdeeacabdeaedebbcaacdadaecbccbededceceabdcabdeabbcdecdedadcaebaababeedcaacdbdacbccdbcece";

    sol.minCut(test14);

    cout << "Finish" << endl;
    return 0;
}