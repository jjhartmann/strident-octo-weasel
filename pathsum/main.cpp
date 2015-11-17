#include <iostream>

using namespace std;


//Definition for a binary tree node.
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum)
    {
        if (root == nullptr)
        {
            return false;
        }

        bool res = findSum(root, sum);
        return res;
    }

private:
    bool findSum(TreeNode *node, int sum)
    {
        if (node->left == nullptr && node->right == nullptr)
        {
            if (sum - node->val == 0)
                return true;
            else
                return false;
        }

        if (node->left != nullptr && node->right != nullptr)
            return findSum(node->left, sum - node->val) || findSum(node->right, sum - node->val);

        if (node->right != nullptr)
            return findSum(node->right, sum - node->val);

        if (node->left != nullptr)
            return findSum(node->left, sum - node->val);



    }
};

void CleanTree(TreeNode *root)
{
    if (root->left == nullptr && root->right == nullptr)
    {
        return;
    }

    if (root->left != nullptr)
        CleanTree(root->left);

    if (root->right != nullptr)
        CleanTree(root->right);

    delete root;
}

int main()
{
    // Set up example tree
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(6);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(-5);
    root->right->right = new TreeNode(-2);
    root->right->right->left = new TreeNode(7);

    Solution sol;
    sol.hasPathSum(root, 13);

    CleanTree(root);
    return 0;
}