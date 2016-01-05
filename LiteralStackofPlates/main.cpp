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

    // Method moves all data down by one
    void rollOver(Stack<T> *in_stack)
    {
        if (in_stack != nullptr)
        {
            mCurr->setNext(in_stack->mHead);

            // move in_stack head by 1
            in_stack->mHead = in_stack->mHead->getNext();

            if (in_stack->mHead != nullptr)
                in_stack->mHead->setPrev(nullptr);

            --(in_stack->mSize);

            Node<T> *n = mCurr->getNext();
            n->setPrev(mCurr);
            n->setNext(nullptr);
            mCurr = n;
            ++mSize;
        }
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
        while (!mStacks.empty())
        {
            delete mStacks.back();
            mStacks.pop_back();
        }
    }

    // Push Data to stack
    void push(T d)
    {
        if (mStacks.empty())
        {
            mStacks.push_back(new Stack<T>());
        }

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
        T data = !mStacks.empty() ? mStacks.back()->pop() : 0;

        if (!mStacks.empty() && mStacks.back()->isEmpty())
        {
            delete mStacks.back();
            mStacks.pop_back();
        }

        return data;
    }

    // Pop a specific stack in container of stacks
    T popAt(int index)
    {
        if (index >= mStacks.size()) return 0;
        T data = mStacks[index]->pop();

        rollOver(index);

        return data;
    }
private:
    void rollOver(int index)
    {
        // Only iterate over stacks that are not full.
        for (int i = index; i < mStacks.size() - 1; ++i)
        {
            mStacks[i]->rollOver(mStacks[i + 1]);
        }

        if (mStacks.back()->isEmpty())
        {
            delete mStacks.back();
            mStacks.pop_back();
        }

    }

    // Vars
    int mLimit;
    vector<Stack<T>*> mStacks;
};


int main()
{
    cout << "Implement a stack where, once an internal limit is exceeded, the stack creates a "
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

    data = myStack.popAt(0);
    data = myStack.popAt(0);
    data = myStack.popAt(0);
    data = myStack.popAt(0);
    data = myStack.popAt(0);
    data = myStack.popAt(0);
    data = myStack.popAt(0);
    data = myStack.popAt(0);
    data = myStack.popAt(0);
    data = myStack.popAt(0);
    data = myStack.popAt(0);
    data = myStack.popAt(0);
    data = myStack.popAt(0);

    // Push data to the stack
    for (int i = 0; i < 15; ++i)
    {
        myStack.push(i);
    }

    return 0;
}