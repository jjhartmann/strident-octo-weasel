////////////////////////////////////////////////////////////////////
// Main - Find common ancestor
#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>

using namespace std;


enum NODEID {
    LEFT = 0, 
    RIGHT, 
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

    ~Node()
    {
        mLeft = nullptr;
        mRight = nullptr;
        mParent = nullptr;
    }

    // Get and Set
    T getData() { return mData; }
    void setData(T d) { mData = d; }
    
    Node<T>* getNode(NODEID id)
    {
        if (id == PARENT) return mParent;
        if (id == LEFT) return mLeft;
        return mRight;
    }
    
    void setNode(NODEID id, Node<T> *n)
    {
        if (id == PARENT) mParent = n;
        if (id == LEFT) mLeft = n;
        if (id == RIGHT) mRight = n;
    }



private:
    Node<T> *mLeft; // Don't Own
    Node<T> *mRight; // Don't Own
    Node<T> *mParent; // Don't Own
    T mData;
};


// Build Random Binary Tree
Node<int>* GenerateRandomBTree(int size, int MAX_VAL)
{
    srand(time(NULL));

    Node<int> *root = new Node<int>(rand() % MAX_VAL);
    vector<Node<int>*> buffer;
    buffer.push_back(root);

    for (int i = 0; i < size; ++i)
    {
        int bsize = buffer.size();
        int bindex = rand() % bsize;
        Node<int> *p = buffer[bindex];
        Node<int> *tmp = new Node<int>(rand() % MAX_VAL);

        bool isLeft = (p->getNode(LEFT)) ? true : false;
        bool isRight = (p->getNode(RIGHT)) ? true : false;
        if (rand() % 2)
        {
            // Try left
            if (!isLeft)
            {
                p->setNode(LEFT, tmp);
            }
            else if (!isRight)
            {
                p->setNode(RIGHT, tmp);
                isRight = true;
            }
        }
        else
        {
            // Try left
            if (!isRight)
            {
                p->setNode(RIGHT, tmp);
            }
            else if(!isLeft)
            {
                p->setNode(LEFT, tmp);
                isLeft = true;
            }

        }

        // Set Parent
        tmp->setNode(PARENT, p);


        if (isLeft && isRight)
        {
            buffer[bindex] = tmp;
        }
        else
        {
            buffer.push_back(tmp);
        }
    }


    return root;
}


// Deallocate BTree
template<typename T>
void DeallocateBTree(Node<T> *root)
{
    if (!root) return;

    DeallocateBTree(root->getNode(LEFT));
    DeallocateBTree(root->getNode(RIGHT));

    delete root;
    root = nullptr;
}


///////////////////////////////////////////////////////////////////
// Solution Class
class Solution
{
public:
    // Find and return common ancestor node
    template<typename T>
    static Node<T>* FindCommonAncestor(Node<T>* node1, Node<T>* node2)
    {

    }
};



int main()
{
    cout << "Given two nodes, find the common ancestor in a binary tree" << endl;

    Node<int> *root = GenerateRandomBTree(15, 50);




    DeallocateBTree<int>(root);

    return 0;
}