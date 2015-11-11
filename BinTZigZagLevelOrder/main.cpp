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
        IntVec cell;
        vector<TreeNode *> parents;
        if (root)
        {
            cell.push_back(root->val);
            sol.push_back(cell);
            parents.push_back(root);
            cell.clear();
        }

        // Rest of body
        int depth = 1;
        while (!parents.empty())
        {
            vector<TreeNode*> p_temp;
            vector<TreeNode*>::reverse_iterator r_it = parents.rbegin();
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


                // Add reverse parent nodes.
                if (depth % 2 != 0)
                {
                    // Add nodes to parent vec.
                    if ((*r_it)->left)
                        p_temp.push_back((*r_it)->left);

                    if ((*r_it)->right)
                        p_temp.push_back((*r_it)->right);
                }
                else
                {
                    // Add nodes to parent vec.
                    if ((*r_it)->right)
                        p_temp.push_back((*r_it)->right);

                    if ((*r_it)->left)
                        p_temp.push_back((*r_it)->left);
                }

                ++r_it;
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
            delete node;
            return;
        }

        if (node->left)
            RecDestory(node->left);

        if(node->right)
            RecDestory(node->right);

        delete node;
    }


};


int main()
{
    cout << "Ziz-zag level order traversal" << endl;
//
//    // Simple tree [1, 2, 6, 5, #, 8, 9]
//    TreeNode *testtree = new TreeNode(1);
//    testtree->left = new TreeNode(2);
//    testtree->right = new TreeNode(3);
//    testtree->left->left = new TreeNode(5);
//    testtree->right->right = new TreeNode(8);
//    testtree->right->left = new TreeNode(9);

    // Simple tree [3,9,20,#,#,15,7]
    TreeNode *testtree = new TreeNode(3);
    testtree->left = new TreeNode(9);
    testtree->right = new TreeNode(20);
    testtree->right->left = new TreeNode(15);
    testtree->right->right = new TreeNode(7);


    Solution test;
    test.zigzagLevelOrder(testtree);

    CreateTree::DestroyBinTree(testtree);
    return 0;
}