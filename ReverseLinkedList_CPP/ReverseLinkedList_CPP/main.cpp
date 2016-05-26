///////////////////////////////////////////////////////////////////////
// Reverse Linked List
//

#include<iostream>

using namespace std;



// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        if (head == nullptr) return head;
        if (head->next == nullptr) return head;


        ListNode *p1 = head;
        ListNode *p2 = head->next;
        p1->next = nullptr;

        while (p2 != nullptr)
        {
            ListNode *tmp = p2->next;

            p2->next = p1;
            p1 = p2;
            p2 = tmp;
        }

        return p1;
    }
};

void deleteList(ListNode * n)
{
    if (n == nullptr) return;
    deleteList(n->next);

    delete n;
}

int main()
{
    cout << "reverse Linked List." << endl;
    ListNode *head = new ListNode(0);
    head->next = new ListNode(1);
    //head->next->next = new ListNode(2);

    Solution sol;
    sol.reverseList(head);

    deleteList(head);

    return 0;
}