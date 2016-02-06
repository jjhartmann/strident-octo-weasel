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
        Node<int> *cleft = n->getChild(LEFT);
        Node<int> *cright = n->getChild(RIGHT);
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

    DeallocateBT(n->getChild(LEFT));
    DeallocateBT(n->getChild(RIGHT));

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




    DeallocateBT(root);
    return 0;
}