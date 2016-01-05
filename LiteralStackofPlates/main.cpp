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

    ~Node()
    {
        mData = 0;
        mNext = nullptr;
        mPrev = nullptr;
    }

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
    // Create an isEmpty stack
    Stack() :
        mSize(0),
        mHead(nullptr),
        mCurr(nullptr)
    {}

    // create stack and push new element
    Stack(T d) :
            mSize(0),
            mHead(nullptr),
            mCurr(nullptr)
    {
        push(d);
    }

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

    // Determine if isEmpty
    bool isEmpty()
    {
        return (mSize <= 0) ? true : false;
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
    SetofStacks(int stackLimit) :
            mLimit(stackLimit)
    {
        mStacks.push_back(new Stack<T>());
    }

    ~SetofStacks()
    {
        for (Stack<T> *stack : mStacks)
        {
            delete stack;
        }
    }

    // Push Data to stack
    void push(T d)
    {
        if (mStacks.back()->size() < mLimit)
        {
            mStacks.back()->push(d);
        }
        else
        {
            mStacks.push_back(new Stack<T>(d));
        }
    }

    // Pop the top of the current stack and return data
    T pop()
    {
        if (!mStacks.empty() && mStacks.back()->isEmpty())
        {
            mStacks.pop_back();
        }

        return !mStacks.empty() ? mStacks.back()->pop() : 0;
    }

    // Pop a specific stack in container of stacks
    T popAt(int index)
    {
        if (index >= mStacks.size()) return 0;

        return mStacks[index]->pop();
    }
private:
    int mLimit;
    vector<Stack<T>*> mStacks;
};


int main()
{
    cout << "Implment a stack where once an internal limit is exceeed, the stack creates a "
         << "new stack to hold all subsequent mData. (literal stack of plates)" << endl;


    SetofStacks<int> myStack(4);

    // Push data to the stack
    for (int i = 0; i < 15; ++i)
    {
        myStack.push(i);
    }

    int data = myStack.pop();
    data = myStack.pop();
    data = myStack.pop();
    data = myStack.pop();
    data = myStack.pop();
    data = myStack.pop();

    data = myStack.popAt(0);
    data = myStack.popAt(0);
    data = myStack.popAt(0);



    return 0;
}