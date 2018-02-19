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


        ListNode *ret = new ListNode(0);
        ListNode *itr = ret;
        int remainder = 0;
        while (l1 || l2 || remainder) {

            int l1i = (l1) ? l1->val : 0;
            int l2i = (l2) ? l2->val : 0;

            int total = l1i + l2i + remainder;
            remainder = (total >= 10) ? total / 10 : 0;
            total %= 10;

            itr->val = total;

            // Add another pointer
            if ((l1 && l1->next) || (l2 && l2->next) || remainder > 0) {
                ListNode *tmp = new ListNode(0);
                itr->next = tmp;
                itr = tmp;
            }

            // Increment Pointers
            if (l1)
                l1 = l1->next;

            if (l2)
                l2 = l2->next;
        }

        return ret;
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

