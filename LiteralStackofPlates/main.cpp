#include <iostream>
#include <vector>

using namespace std;

template <class T>
class Node
{
public:
    Node(T d) :
        mData(d),
        mNext(nullptr),
        mPrev(nullptr)
    {}

    // Getter and setters
    T getData() { return mData; }
    void setData(T d) { mData = d; }
    Node<T>* getNext() { return mNext; }
    void setNext(Node<T> *n) { mNext = n; }
    Node<T>* getPrev() { return mPrev; }
    void setPrev(Node<T> *n) { mPrev = n; }

private:
    T mData;
    Node<T>* mNext;
    Node<T>* mPrev;
};

template <class T>
class Stack
{
public:
    Stack() :
        mSize(1),
        mHead(nullptr),
        mCurr(nullptr)
    {}

    ~Stack()
    {
        while (mHead != nullptr)
        {
            Node<T> *n = mHead->getNext();
            delete mHead;
            mHead = n;
        }

        mSize = 0;
        mHead = nullptr;
        mCurr = nullptr;
    }

    // Push to stack
    void push(T d)
    {
        Node<T> *tmp = new Node<T>(d); // Own
        if (mHead == nullptr)
        {
            mHead = tmp;
            mCurr = tmp;
        }
        else
        {
            tmp->setPrev(mCurr);
            mCurr->setNext(tmp);
            mCurr = tmp;
        }

        ++mSize;
    }

    // Pop and return value
    T pop()
    {
        T data = 0;
        Node<T> *n = nullptr;

        if (mCurr == nullptr)
        {
            return data;
        }
        else if (mCurr->getPrev() == nullptr)
        {
            data = mCurr->getData();
            delete mCurr;
            mCurr = nullptr;
            mHead = nullptr;
            mSize = 0;

            return data;
        }

        n = mCurr->getPrev();
        data = mCurr->getData();

        delete mCurr;

        mCurr = n;
        mCurr->setNext(nullptr);
        --mSize;

        return data;

    }

    // Get the size of the stack
    int size()
    {
        return mSize;
    }

private:
    int mSize;
    Node<T> *mHead;
    Node<T> *mCurr;
};

template <class T>
class SetofStacks
{
public:



private:
    int mLimit;
    vector<Stack<T>*> mStacks;

};


int main()
{
    cout << "Implment a stack where once an internal limit is exceeed, the stack creates a "
         << "new stack to hold all subsequent mData. (literal stack of plates)" << endl;
    return 0;
}