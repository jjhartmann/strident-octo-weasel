//////////////////////////////////////////////////////////////////////
// Delete Node in Linked List
//
// Write a function to delete a node(except the tail) in a singly linked list, given only access to that node.
//
// Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, the linked list should become 1 -> 2 -> 4 after calling your function.

#include <iostream>

using namespace std;



// Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        
        if (node->next == nullptr)
        {
            delete node;
            node = nullptr;
        }
        else
        {
            node->val = node->next->val;
            ListNode *tmp = node->next;

            node->next = node->next->next;

            delete tmp;
            tmp = nullptr;
        }

    }
};

int main()
{
    cout << "Delete Node form Linked List" << endl;





    return 0;
}


