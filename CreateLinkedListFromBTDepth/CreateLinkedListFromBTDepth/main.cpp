////////////////////////////////////////////////////////////////
// Main

#include <iostream>
#include <vector>
#include <ctime>
#include <stdlib.h>

using namespace std;

enum CHILDID{
    LEFT = 0,
    RIGHT = 1
};

////////////////////////////////////////////////////////////////
// Binary Tree Node
template<class T>
class TNode
{
public:
    TNode(T d) :
        mData(d),
        mLeft(nullptr),
        mRight(nullptr)
    {}

    // Get and set
    T getData() { return mData;  }
    void setData(T d) { mData = d; }
    TNode<T>* getChild(CHILDID id)
    {
        return (id == LEFT) ? mLeft : mRight;
    }

    void setChild(CHILDID id, TNode<T> *n)
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


////////////////////////////////////////////////////////////////
// Linked List Node
template<class T>
class LNode
{
public:
    LNode(T d) :
        mData(d),
        mNext(nullptr),
    {}

    // Get and set
    T getData() { return mData; }
    void setData(T d) { mData = d; }
    LNode<T>* getNext()
    {
        return mNext;
    }

    void setNext(LNode<T> *n)
    {
        mNext = n;
    }

    void appendToEnd(LNode<T> *n)
    {
        if (!mNext)
        {
            mNext = n;
            return;
        }

        LNode<T> *tmp = mNext;

        while (!tmp->getNext())
        {
            tmp = tmp->getNext();
        }

        tmp->setNext(n);
    }

private:
    T mData;
    LNode<T> *mNext;
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



///////////////////////////////////////////////////////////////
// Solution Class
class Solution
{
public:
    template <typename T>
    static void BuildLinkedListFromDepths(TNode<T> *root, vector<LNode<T>*> &v)
    {

    }
};


int main()
{

    cout << "Create a vector linked lists for each depth of a binary tree" << endl;

    TNode<int> *root = GenerateRandomBTree(10, 10);


    return 0;
}