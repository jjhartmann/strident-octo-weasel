// InvertBinaryTree-CPP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
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
    TreeNode* invertTree(TreeNode* root) {
        // Switch pointers and recurse
        if (root == nullptr) return root;

        TreeNode *p = root->left;
        
        root->left = root->right;
        root->right = p;

        if (root->left != nullptr)
            invertTree(root->left);

        if (root->right != nullptr)
            invertTree(root->right);

        return root;
    }
};

int main()
{
    cout << "Invert a Binary Tree, inspired by Max Howell" << endl;
    



    return 0;
}

