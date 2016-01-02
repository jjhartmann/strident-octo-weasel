#include <iostream>
#include <stack>

using namespace std;

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
    Stack myStack;
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