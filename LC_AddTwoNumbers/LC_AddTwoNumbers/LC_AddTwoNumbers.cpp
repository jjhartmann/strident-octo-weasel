// LC_AddTwoNumbers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdlib>
#include <ctime>

struct ListNode {
    int val;
    ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode * addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1 && !l2) {
            return NULL;
        }
        if (!l1) {
            return l2;
        }
        if (!l2)
        {
            return l1;
        }

        ListNode *dummyhead = new ListNode(0);
        ListNode *itr = dummyhead;
        int remainder = 0;
        while (l1 || l2) {

            int l1i = (l1) ? l1->val : 0;
            int l2i = (l2) ? l2->val : 0;

            int total = l1i + l2i + remainder;
            remainder = (total >= 10) ? total / 10 : 0;
            total %= 10;

            itr->next = new ListNode(total % 10);
            itr = itr->next;

            // Increment Pointers
            if (l1)
                l1 = l1->next;

            if (l2)
                l2 = l2->next;
        }

        if (remainder > 0) {
            itr->next = new ListNode(remainder);
        }

        return dummyhead->next;
    }
};

ListNode* GenerateRandomList(int n)
{
    srand(time(NULL));
    ListNode *ret = new ListNode(rand() % 10);
    ListNode *itr = ret;
    for (int i = 1; i < n; ++i)
    {
        ListNode *tmp = new ListNode(rand() % 10);
        itr->next = tmp;
        itr = tmp;
    }

    return ret;
}

ListNode* GenerateReverseList(int x)
{
    ListNode *ret = new ListNode(x % 10);
    ListNode *itr = ret;
    while ((x = x / 10))
    {
        int remainder = x % 10;
        
        ListNode *tmp = new ListNode(remainder);
        itr->next = tmp;
        itr = tmp;
    } 

    return ret;
}

int main()
{
    Solution sol; 
    
    ListNode *l1 = GenerateReverseList(9);
    ListNode *l2 = GenerateReverseList(9);

    ListNode *res = sol.addTwoNumbers(l1, l2);



    return 0;
}

