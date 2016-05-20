//////////////////////////////////////////////////////////////////////
// Same Tree
//
// Given two binary trees, write a function to check if they are equal or not.
//
// Two binary trees are considered equal if they are structurally identical and the nodes have the same value.

#include <iostream>

using namespace std;



// Definition for a binary tree node.
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr || q == nullptr)
            return p == q;


        if (p->val != q->val)
            return false;

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};


int main()
{
    cout << "Same Tree" << endl;

    TreeNode *p = nullptr;
    TreeNode *q = nullptr;

    Solution sol;
    sol.isSameTree(p, q);



    return 0;
}

