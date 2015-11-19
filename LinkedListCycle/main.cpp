#include <iostream>

using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head)
    {
        if (head == nullptr)
        {
            return false;
        }

        ListNode *runner = head;
        ListNode *drunner = head->next;

        int count = 0;
        while (drunner != nullptr)
        {
            // If runner and drunner meet,
            // Then cycle detected.
            if (runner == drunner)
            {
                return true;
            }

            // Have runner only increment ever other cycle
            if (count % 2 == 0)
            {
                runner = runner->next;
            }

            // Have double runner increment every cycle.
            drunner = drunner->next;

            count++;
        }

        // Return false if nullptr detected
        return false;
    }
};


int main()
{
    return 0;
}