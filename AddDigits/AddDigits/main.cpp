//////////////////////////////////////////////////////////////////////
// Add Digits

#include <iostream>

using namespace std;

class Solution {
public:
    int addDigits(int num) {
        // With a loop
        int res = num;
        
        while (res > 9)
        {
          int n = res % 10;
          while (res > 0)
          {
              res = res / 10;
              n += res % 10;
          }

          res = n;
        }

        return res;

    }
};


int main()
{
    Solution sol;
    int n = sol.addDigits(12356);



    return 0;
}