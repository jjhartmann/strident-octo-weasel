/////////////////////////////////////////////////////////////////
// Main


#include <iostream>
#include <vector>
#include <queue>
#include <ctime>
#include <cstdlib>


using namespace std;

enum NODE_ID
{
    LEFT = 0,
    RIGHT,
};

template<class T>
class TNode
{
public:
    TNode(T d) :
        mData(d),
        mLeft(nullptr),
        mRight(nullptr)
    {}

    ~TNode()
    {
        mLeft = nullptr;
        mRight = nullptr;
        mData = -1;
    }

    // Get and Set
    T getData() { return mData; }
    void setData(T d) { mData = d }
    TNode<T>* getChild(NODE_ID id)
    {
        return (id == LEFT) ? mLeft : mRight;
    }

    void setChild(NODE_ID id, TNode<T> *n)
    {
        if (id == LEFT)
        {
            mLeft = n;
        }
        else
        {
            mRight = n;
        }
    }

private:
    T mData;
    TNode<T> *mLeft;
    TNode<T> *mRight;

};



///////////////////////////////////////////////////////////////
// Helper FUnctions
TNode<int>* GenerateRandomBTree(int size, int in_max)
{
    srand(time(nullptr));
    TNode<int> *root = new TNode<int>(rand() % in_max);

    vector<TNode<int>*> buffer;
    buffer.push_back(root);
    for (int i = 0; i < size; ++i)
    {
        int bSize = buffer.size();
        int bIndex = rand() % bSize;

        TNode<int> *n = buffer[bIndex];
        TNode<int> *tmp = new TNode<int>(rand() % in_max);

        if (rand() % 2 && !n->getChild(LEFT))
        {
            n->setChild(LEFT, tmp);
        }
        else if (!n->getChild(RIGHT))
        {
            n->setChild(RIGHT, tmp);
        }
        else if (!n->getChild(LEFT))
        {
            n->setChild(LEFT, tmp);
        }

        if (n->getChild(LEFT) && n->getChild(RIGHT))
        {
            buffer[bIndex] = tmp;
        }
        else
        {
            buffer.push_back(tmp);
        }
    }

    return root;

}


// Create Binary Search Tree
TNode<int>* GenerateRandomBSearchTree(int size, int in_max)
{
    srand(time(nullptr));
    TNode<int> *root = new TNode<int>(rand() % in_max);

    for (int i = 0; i < size; ++i)
    {
        TNode<int> *tmp = new TNode<int>(rand() % in_max);
        TNode<int> *n = root;
        bool inserted = false;

        while (!inserted)
        {
            NODE_ID id;
            id = (n->getData() >= tmp->getData()) ? LEFT : RIGHT;

            if (!n->getChild(id))
            {
                n->setChild(id, tmp);
                inserted = true;
            }
            else
            {
                n = n->getChild(id);
            }
        }

    }

    return root;

}


// Delete Tree
template<typename T>
void DeleteTree(TNode<T> *root)
{
    if (!root) return;

    DeleteTree(root->getChild(LEFT));
    DeleteTree(root->getChild(RIGHT));

    delete root;
    root = nullptr;
}


////////////////////////////////////////////////////////////////////////////
// Solution class
class Solution
{
public:
    template <typename T>
    static bool CheckTreeBST(TNode<T> *root)
    {
        queue<TNode<T>*> buffer;
        buffer.push(root);

        while (!buffer.empty())
        {
            TNode<T> *parent = buffer.front();
            buffer.pop();

            TNode<T> *lchild = parent->getChild(LEFT);
            TNode<T> *rchild = parent->getChild(RIGHT);

            // Check if BST equality holds
            if (lchild && lchild->getData() > parent->getData())
                return false;

            if (rchild && rchild->getData() <= parent->getData())
                return false;

            // Add children to buffer. 
            if (lchild)
                buffer.push(lchild);
            if (rchild)
                buffer.push(rchild);
        }

        return true;
    }

private:

};



int main()
{
    cout << "Check to see if a binary tree is in fact a binary search tree." << endl;
    TNode<int> *bTree = GenerateRandomBTree(10, 10);
    TNode<int> *bSTree = GenerateRandomBSearchTree(10, 100);

    bool res;
    res = Solution::CheckTreeBST<int>(bTree);
    res = Solution::CheckTreeBST<int>(bSTree);


    DeleteTree(bTree);
    DeleteTree(bSTree);

    return 0;
}