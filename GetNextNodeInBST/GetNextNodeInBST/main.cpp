////////////////////////////////////////////////////////////////
// Main

#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;


////////////////////////////////////////////////////////////////
// BST Nodes. 
enum BRANCH {
    LEFT = 0,
    RIGHT = 1,
};

template<class T>
class Node
{
public:
    Node(T d) :
        mData(d),
        mLeft(nullptr),
        mRight(nullptr)
    {}

    T getData() { return mData; }
    void setData(T d) { mData = d;  }
    

    // Retrieve child
    Node<T>* getChild(BRANCH id)
    {
        return (id == LEFT) ? mLeft : mRight;
    }

    // Set Child
    void setChild(BRANCH id, Node<T> *n)
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
    Node<T> *mLeft;
    Node<T> *mRight;

};


// Create Binary Search Tree
Node<int>* GenerateRandomBSearchTree(int size, int in_max)
{
    srand(time(nullptr));
    Node<int> *root = new Node<int>(rand() % in_max);

    for (int i = 0; i < size; ++i)
    {
        Node<int> *tmp = new Node<int>(rand() % in_max);
        Node<int> *n = root;
        bool inserted = false;

        while (!inserted)
        {
            BRANCH id;
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


////////////////////////////////////////////////////////////////
// Solution Class
class Solution
{
public:
    template<typename T>
    static Node<T>* GetNextNodeInOrder(Node<T> *curr)
    {




    }
};




int main()
{
    cout << "An algorithm to determine the next node given a node in a BST (in-order)" << endl;


    return 0;
}