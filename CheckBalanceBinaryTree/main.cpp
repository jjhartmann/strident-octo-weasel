#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

template< class T >
class Node
{
public:
    Node(T d) :
        mData(d),
        mLeft(nullptr),
        mRight(nullptr)
    {}

    ~Node()
    {
        mLeft = nullptr;
        mRight = nullptr;
        mData = 0;
    }

    Node<T>* getRight()
    {
        return mRight;
    }

    void setRight(Node<T> *n)
    {
        mRight = n;
    }

    Node<T>* getLeft()
    {
        return mLeft;
    }

    void setLeft(Node<T> *n)
    {
        mLeft = n;
    }

    T getData()
    {
        return mData;
    }
    


private:
    T mData;
    Node<T> *mLeft;
    Node<T> *mRight;
};


///////////////////////////////////
// Delete Entire Tree
template <typename T>
void DeleteTree(Node<T> *root)
{
    if (!root)
    {
        return;
    }

    DeleteTree(root->getLeft());
    DeleteTree(root->getRight());
    delete root;
    root = nullptr;
}

//////////////////////////////////
// Create a random tree
Node<int>* CreateRandTree()
{
    srand(time(nullptr));
    int MAX = 20;
    Node<int> *root = new Node<int>(rand() % MAX);
    vector<Node<int>*> leafs;
    leafs.push_back(root);

    for (int i = 0; i < 20; ++i)
    {
        int rVal = rand() % MAX;
        Node<int> *n = (leafs[rVal % leafs.size()]);
        bool leftEmpty = (n->getLeft() == nullptr) ? true : false;
        bool rightEmpty = (n->getRight() == nullptr) ? true : false;

        if (rVal % 2 && leftEmpty)
        {
            n->setLeft(new Node<int>(rVal));
            leftEmpty = false;

            // Push new leaf
            leafs.push_back(n->getLeft());
            if (!rightEmpty)
            {
                n = n->getRight();
            }

        }
        else if(rightEmpty)
        {
            n->setRight(new Node<int>(rVal));
            rightEmpty = false;

            // Push new leaf
            leafs.push_back(n->getRight());
            if (!leftEmpty)
            {
                n = n->getLeft();
            }
        }
    }


    return root;
}


//////////////////////////////////
// Solution Class
class Solution
{
public:
    template< typename T>
    static bool CheckIfBinaryTreeIsBalanced(Node<T> *root)
    {
        int max = ~0;
        int min = INT32_MAX;
        IsBalanced(root, min, max, 0);

        return (max - min) <= 1;
    }

private:
    template< typename T>
    static void IsBalanced(Node<T> *n, int &min, int &max, int count)
    {
        if (!n) 
        {
            if (count > max) max = count;
            if (count < min) min = count;
            return;
        }

        ++count;
        IsBalanced(n->getLeft(), min, max, count);
        IsBalanced(n->getRight(), min, max, count);
    }

};

//////////////////////////////////
// Main
int main()
{
    cout << "Check to see if a binary tree is balanced" << endl;

    Node<int> *root = CreateRandTree();
    bool res = Solution::CheckIfBinaryTreeIsBalanced<int>(root);

    DeleteTree<int>(root);

    return 0;
}