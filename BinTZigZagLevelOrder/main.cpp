#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


//  Definition for a binary tree node.
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


typedef vector<vector<int>> SolVec;
typedef vector<int> IntVec;
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        SolVec sol;
        IntVec cell(root->val, 1);
        sol.push_back(cell);
        cell.pop_back();

        vector<TreeNode*> parents;
        parents.push_back(root);

        // Rest of body
        int depth = 1;
        while (!parents.empty())
        {
            vector<TreeNode*> p_temp;
            for (auto it : parents)
            {
                if (depth % 2 == 0)
                {
                    // Even: left to right
                    if (it->left)
                        cell.push_back(it->left->val);

                    if (it->right)
                        cell.push_back(it->right->val);
                }
                else
                {
                    // Odd: Right to left
                    if (it->right)
                        cell.push_back(it->right->val);

                    if(it->left)
                        cell.push_back(it->left->val);
                }
            }

            // Iterate over parents backward and store
            for (vector<TreeNode*>::reverse_iterator it = parents.rbegin(); it != parents.rend(); ++it)
            {
                if (depth % 2 != 0)
                {
                    // Add nodes to parent vec.
                    if ((*it)->left)
                        p_temp.push_back((*it)->left);

                    if ((*it)->right)
                        p_temp.push_back((*it)->right);
                }
                else
                {
                    // Add nodes to parent vec.
                    if ((*it)->right)
                        p_temp.push_back((*it)->right);

                    if ((*it)->left)
                        p_temp.push_back((*it)->left);
                }
            }

            if (!cell.empty())
                sol.push_back(cell);

            cell.clear();
            parents.swap(p_temp);

            // Keep track of tree depth
            ++depth;

        }

        return sol;
    }
};


class CreateTree
{
public:
    CreateTree(vector<int> tree) :
            root(nullptr)
    {
        if (tree.empty())
            return ;

        root = new TreeNode(tree[0]);
        TreeNode *p = root;
        for (int i = 1; exp2(i) < tree.size(); ++i)
        {

        }


    };

    ~CreateTree()
    {

    };

    TreeNode* GetTree()
    {
        return root;
    }

    static void DestroyBinTree(TreeNode *root)
    {
        RecDestory(root);
    }

private:
    TreeNode *root;


    static void RecDestory(TreeNode *node)
    {
        if (!node->left && !node->right)
        {
            return;
        }

        RecDestory(node->left);
        RecDestory(node->right);

        delete node;
    }


};


int main()
{
    cout << "Ziz-zag level order traversal" << endl;

    // Simple tree [1, 2, 6, 5, #, 8, 9]
    TreeNode *testtree = new TreeNode(1);
    testtree->left = new TreeNode(2);
    testtree->right = new TreeNode(3);
    testtree->left->left = new TreeNode(5);
    testtree->right->right = new TreeNode(8);
    testtree->right->left = new TreeNode(9);


    Solution test;
    test.zigzagLevelOrder(testtree);

//    CreateTree::DestroyBinTree(testtree);
    return 0;
}