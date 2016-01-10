#include <iostream>
#include <stack>
#include <cstdlib>
#include <ctime>


using namespace std;

class Solution
{
public:
    // Sort a stack in ascending order
    static void sortStackAsc(stack<int> &s)
    {
        // Helper vars
        stack<int> tmp;
        int count1 = 0;
        int count2 = 0;
        int min1 = INT32_MAX;
        int pmin1 = INT32_MAX;
        int min2 = ~0;

        // Main algorithm
        // Iterate through the stack, passing the elements back and forth.
        // In each iteration, find the min value and add to s.
        // Build the sorted result.
        do
        {

            // Get min from tmp
            while (!tmp.empty())
            {
                if (min2 >= tmp.top() && tmp.top() > pmin1)
                {
                    if (min2 == tmp.top())
                    {
                        ++count2;
                    }
                    else
                    {
                        count2 = 1;
                    }

                    min2 = tmp.top();
                }

                // Only push unseen elements
                if (pmin1 != tmp.top())
                    s.push(tmp.top());

                tmp.pop();
            }


            // Get min from s
            count1 = 0;
            while (!s.empty() && pmin1 != s.top())
            {
                if (min1 >= s.top() && s.top() > min2)
                {
                    if (min1 == s.top())
                    {
                        ++count1;
                    }
                    else
                    {
                        count1 = 1;
                    }

                    min1 = s.top();
                }

                // Only push unseen elements.
                if (min2 != s.top())
                    tmp.push(s.top());

                s.pop();
            }

            // Add min1 and min2 to s.
            if (min2 != INT32_MAX)
            {
                // push for all duplicates
                for (int i = 0; i < count2; ++i)
                {
                    s.push(min2);
                }
            }

            // push for all duplicates
            for (int i = 0; i < count1; ++i)
            {
                s.push(min1);
            }

            pmin1 = min1;
            min1 = INT32_MAX;
            min2 = INT32_MAX;


        } while (!tmp.empty());

    }

};

int main()
{
    cout << "Sort a stack in acending order." << endl;
    srand(time(nullptr));

    stack<int> test;
    for (int i = 0; i < 10; ++i)
    {
        test.push(rand() % 10);
    }

    Solution::sortStackAsc(test);

    return 0;
}