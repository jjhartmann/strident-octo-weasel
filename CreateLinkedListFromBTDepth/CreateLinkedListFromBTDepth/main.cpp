////////////////////////////////////////////////////////////////
// Main

#include <iostream>

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

int main()
{

    cout << "Create a vector linked lists for each depth of a binary tree" << endl;




    return 0;
}