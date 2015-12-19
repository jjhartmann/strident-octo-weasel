#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isUnique(string str)
    {
        vector<bool> charmap(256);
        for (char c : str)
        {
            c = tolower(c);
            if (charmap[(int) c])
            {
                return false;
            }

            charmap[(int) c] = true;
        }

        return true;
    }

};

int main()
{
    cout << "Determine if string has all unique characters" << endl;

    Solution sol;
//    sol.isUnique("mistake");
    sol.isUnique("Anebila");

    return 0;
}