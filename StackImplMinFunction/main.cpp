#include <iostream>
#include <stack>

using namespace std;


// Uses two stacks, one for the main int and one for the min values
// Uses less space then have pairs of stacks.
class Stack2
{
public:
    void push(int d)
    {
        if (mMinStack.empty())
        {
            mMinStack.push(d);
        }
        else if (mMinStack.top() >= d)
        {
            mMinStack.push(d);
        }

        mStack.push(d);
    }

    int pop()
    {
        if (mStack.empty()) return 0;

        int ret = mStack.top();
        mStack.pop();

        if (ret == mMinStack.top())
        {
            mMinStack.pop();
        }

        return ret;
    }

    int min()
    {
        if (mMinStack.empty()) return 0;
        return mMinStack.top();
    }

private:
    stack<int> mStack;
    stack<int> mMinStack;
};


// Stack that uses a pair.
// Pair <value, minValue>
// Would have 2 times the space requirements as a regular stack. 
class Stack
{
public:
    Stack() :
        mMin(INT32_MAX)
    {}

    void push(int d)
    {
        if (mMin > d)
        {
            mMin = d;
        }
        mStack.push(make_pair(d, mMin));
    }

    int pop()
    {
        int ret = mStack.top().first;
        mStack.pop();
        mMin = mStack.top().second;
        return ret;
    }

    int min()
    {
        return mMin;
    }

private:
    stack< pair<int, int> > mStack;
    int mMin;
};

int main()
{
    cout << "Implement a stack that has a min function." << endl;
    Stack2 myStack;
    myStack.push(4);
    myStack.push(1);
    myStack.push(5);
    myStack.push(0);
    myStack.push(7);
    myStack.push(-8);
    myStack.push(2);
    myStack.push(-10);

    int res = myStack.pop();
    res = myStack.pop();
    res = myStack.pop();
    res = myStack.pop();
    res = myStack.pop();
    res = myStack.pop();
    res = myStack.pop();
    res = myStack.pop();


    return 0;
}