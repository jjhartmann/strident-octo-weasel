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
        // 1) Determine the distance to the root
        Node<T>* tmp = node1;
        int dist1 = 0;
        while (tmp->getNode(PARENT))
        {
            ++dist1;
            tmp = tmp->getNode(PARENT);
        }

        // Node 2
        tmp = node2;
        int dist2 = 0;
        while (tmp->getNode(PARENT))
        {
            ++dist2;
            tmp = tmp->getNode(PARENT);
        }

        // 2) Determine greater distance and travers to other nodes level. 
        Node<T> * nfar = (dist1 > dist2) ? node1 : node2;
        Node<T> *nnear = (dist2 <= dist1) ? node2 : node1;
        int deltaDist = abs(dist1 - dist2);

        while (deltaDist--)
        {
            tmp = tmp->getNode(PARENT);
        }

        // 3) Traverse both nodes simultaneously to ancestor
        while (nfar != nnear && far && nnear)
        {
            nfar = nfar->getNode(PARENT);
            nnear = nnear->getNode(PARENT);
        }


        // Ancestor is both near or far
        return nnear;
    }
};



int main()
{
    cout << "Given two nodes, find the common ancestor in a binary tree" << endl;

    Node<int> *root = GenerateRandomBTree(15, 50);

    Node<int> *ancestor = Solution::FindCommonAncestor<int>();


    DeallocateBTree<int>(root);

    return 0;
}