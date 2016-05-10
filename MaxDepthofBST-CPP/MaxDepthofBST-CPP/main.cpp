//////////////////////////////////////////////////////////////////////
// Max depth of BST
//
// Given a binary tree, find its maximum depth.
// The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

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
    int maxDepth(TreeNode* root) {
        int i = 1;
        if (root == nullptr) return 0;

        return maxDepthHelper(root, i);
    }

private:
    int maxDepthHelper(TreeNode* node, int i)
    {
        int l = i;
        int r = i;
        
        ++i;
        if (node->left != nullptr)
            l = maxDepthHelper(node->left, i);
    
        if (node->right != nullptr)
            r = maxDepthHelper(node->right, i);
    
        return (l < r) ? r : l;
    }
};

int main()
{
    cout << "Maximum Depth of Binary Tree" << endl;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    Solution sol;
    sol.maxDepth(root);

    return 0;
}