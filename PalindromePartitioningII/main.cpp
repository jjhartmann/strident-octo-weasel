#include <iostream>
#include <map>
#include <unordered_map>
#include <deque>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

///////////////////////////////////////////////////////
// This problem is best solved using Dynamic programming
// Just realized this after spending a good day trying
// to be clever. Yep.
///////////////////////////////////////////////////////

class Solution {
public:
    int minCut(string s)
    {
        if (s.empty()) return 0;
        int n = s.length();
        vector<int> dp(n, -1);
        vector<bool> isPalindrome(n * n, false);

        for (int right = 0; right < s.length(); right++) {
            dp[right] = right;
            isPalindrome[right*n + right] = true;
            for (int left = 0; left <= right; left++) {
                if (s[left] == s[right] && (right - left <= 1 || isPalindrome[(left + 1) * n + (right - 1)])) {
                    if (left == 0)
                        dp[right] = 0;
                    else {
                        isPalindrome[left*n + right] = true;
                        dp[right] = min(dp[left - 1] + 1, dp[right]);
                    }
                }
            }
        }
        return dp[n - 1];
    }
};


//////////////////////////////////////////////////
//////////////////////////////////////////////////
int main()
{
    Solution sol;

    string test1 = "abababa";
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

    sol.minCut(test1);

    cout << "Finish" << endl;
    return 0;
}