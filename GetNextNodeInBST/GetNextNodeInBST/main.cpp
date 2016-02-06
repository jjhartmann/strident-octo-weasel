////////////////////////////////////////////////////////////////
// Main

#include <iostream>
#include <ctime>
#include <cmath>
#include <queue>

using namespace std;


////////////////////////////////////////////////////////////////
// BST Nodes. 
enum BRANCH {
    LEFT = 0,
    RIGHT = 1,
    PARENT,
};

template<class T>
class Node
{
public:
    Node(T d) :
        mData(d),
        mLeft(nullptr),
        mRight(nullptr),
        mParent(nullptr)
    {}

    T getData() { return mData; }
    void setData(T d) { mData = d;  }
    
     
    // Retrieve child
    Node<T>* getNode(BRANCH id)
    {
        if (id == PARENT) return mParent;

        return (id == LEFT) ? mLeft : mRight;
    }

    // Set Child
    void setNode(BRANCH id, Node<T> *n)
    {
        if (id == LEFT)
        {
            mLeft = n;
        }
        else if (id == RIGHT)
        {
            mRight = n;
        }
        else
        {
            mParent = n;
        }
    }


private:
    T mData;
    Node<T> *mLeft;
    Node<T> *mRight;
    Node<T> *mParent;

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

            if (!n->getNode(id))
            {
                n->setNode(id, tmp);
                tmp->setNode(PARENT, n);

                inserted = true;
            }
            else
            {
                n = n->getNode(id);
            }
        }

    }

    return root;

}


// BFS and find nth node
template<typename T>
Node<T>* FindNode(Node<T> *root, int NodeNumber)
{
    if (NodeNumber == 0 || !root) return root;

    queue<Node<T>*> buffer;
    buffer.push(root);

    int i = 1;
    while (!buffer.empty())
    {
        Node<T> *n = buffer.front();
        buffer.pop();

        // Check nodes
        Node<int> *cleft = n->getNode(LEFT);
        Node<int> *cright = n->getNode(RIGHT);
        if (NodeNumber == i && cleft)
        {
            return cleft;
        }
        else if (NodeNumber == i + 1 && cright)
        {
            return cright;
        }
        
        if (cleft)
        {
            buffer.push(cleft);
            ++i;
        }
        
        if (cright)
        {
            buffer.push(cright);
            ++i;
        }
    }
    
    return root;
}

// Delete binary serach tree.
template<typename T>
void DeallocateBT(Node<T> *n)
{
    if (!n) return;

    DeallocateBT(n->getNode(LEFT));
    DeallocateBT(n->getNode(RIGHT));

    delete n;
    n = nullptr;

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
    Node<int> *root = GenerateRandomBSearchTree(15, 50);
    Node<int> *node = FindNode(root, 7); // Don't own

    // Find next in-order node. 



    DeallocateBT(root);
    return 0;
}