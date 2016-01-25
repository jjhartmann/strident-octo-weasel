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
// Main
int main()
{
    cout << "Check to see if a binary tree is balanced" << endl;

    Node<int> *root = CreateRandTree();



    DeleteTree<int>(root);

    return 0;
}