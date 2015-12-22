#include <iostream>

using namespace std;

class Solution
{
public:
    static bool isRotation(string s1, string s2)
    {
        int N = s1.length();
        if (N != s2.length() || N < 1) return false;

        char c = s1[0];
        int pos = 0;
        while ((pos = s2.find(c, pos)) != string::npos)
        {
            bool found = true;
            for (int i = 0; i < N && found; ++i)
            {
                if (s1[i] != s2[(i + pos) % N])
                {
                    found = false;
                    pos = pos + i;
                }
            }

            if (found)
            {
                return true;
            }
        }

        return false;
    }

    static bool isRotation2(string s1, string s2)
    {
        if (s1.length() != s2.length() || s1.length() < 1) return false;

        string s1s1 = s1 + s1;
        return (s1s1.find(s2) != string::npos) ? true : false;
    }
};

int main()
{
    cout << "Check if two strings are rotations of eachother." << endl;
//    string test1 = "mybucket";
//    string test2 = "cketmybu";
    string test1 = "mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmybucket";
    string test2 = "mmmmmmmmmmmmmmmmmmmmmmmmmmmybucketmmmmmmmmmm";
//    Solution::isRotation(test1, test2);
    bool test = Solution::isRotation2(test1, test2);
    return 0;
}