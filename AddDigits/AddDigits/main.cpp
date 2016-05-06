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

    // THe solution can be expressed in constant time. 
    // Since the solution to the question can only be between 
    // 0-9, and that the period of is offset every 10th iter
    // We can then assume that the offset to the sequence equals
    // the floor of N/9. Which we can use to determine the sequence number
    // by looking at the last digit.
    int addDigitsConstantTime(int num) {
        if (num == 0) return 0;

        int offset = (int)(ceil(num / 9)) % 10;

        int n = num % 10;
        if (num % 9 == 0)
        {
            offset -= 1;
        }

        return (offset < 0) ? 9 : ((n + offset) % 10);

    }
};


int main()
{
    Solution sol;
    int n = sol.addDigitsConstantTime(90);



    return 0;
}