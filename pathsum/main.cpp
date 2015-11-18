#include <iostream>
#include <stack>

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

        bool res;
//         res = findSumIterative(root, sum);
        res = findSumIterStack(root, sum);
//        res = findSum(root, sum);
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

    bool findSumIterStack(TreeNode* node, int sum)
    {
        stack<TreeNode*> p_stack;
        stack<TreeNode*> p_visit;
        p_stack.push(node);
        p_visit.push(node);

        int calcsum = p_stack.top()->val;

        while(!p_stack.empty())
        {
            if (p_visit.top() == p_stack.top()->right ||
                (p_stack.top()->right == nullptr &&
                (p_stack.top()->left == nullptr ||
                        p_visit.top() == p_stack.top()->left)))
            {
                if (calcsum == sum && p_stack.top()->right == nullptr &&
                        p_stack.top()->left == nullptr)
                {
                    return true;
                }

                cout << p_stack.top()->val << endl;

                if (p_stack.top()->left != nullptr)
                    p_visit.pop();

                if (p_stack.top()->right != nullptr)
                    p_visit.pop();

                // Go up one level
                calcsum = calcsum - p_stack.top()->val;
                p_stack.pop();

                // Check if tree traversal finished.
                if (p_visit.top() == node->right)
                    p_stack.pop();

                continue;
            }

            if (p_stack.top()->left != nullptr &&
                p_stack.top()->left != p_visit.top())
            {
                p_visit.push(p_stack.top()->left);
                p_stack.push(p_stack.top()->left);
            }
            else if (p_stack.top()->right != nullptr &&
                    p_stack.top()->right != p_visit.top())
            {
                p_visit.push(p_stack.top()->right);
                p_stack.push(p_stack.top()->right);
            }

            // calculate the sum
            calcsum += p_stack.top()->val;
        }

        return false;
    }

    bool findSumIterative(TreeNode *node, int sum)
    {
        TreeNode* current = node->left;
        TreeNode* parent = node;

        while (current != nullptr)
        {
            if (parent != nullptr)
            {
                parent->left = current->right;
                current->right = parent;
            }


            if (current->left != nullptr)
            {
                parent = current;
                current = current->left;
            }
            else
            {
                cout << current->val << endl;
                current = current->right;
                parent = nullptr;
            }


        }
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