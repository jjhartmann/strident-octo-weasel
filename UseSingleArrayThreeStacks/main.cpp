#include <iostream>
#include <array>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

template <class T, int NUM>
class Stack
{
public:
    Stack()
    {
        index.resize(NUM, -1);
        stackArray.resize(NUM * 10);
    }

    // Pop the front of the stack
    template <int N>
    T pop()
    {
        if (N >= NUM || index[N] < 0) return -1;
        int currindex = (index[N] *  NUM) + N;
        T ret = stackArray[currindex];
        --index[N];

        return ret;
    }

    // Push an object T to stack number
    template <int N>
    void push(T data)
    {
        if (N >= NUM) return;
        ++index[N];
        int currindex = (index[N] *  NUM) + N;

        if (currindex >= stackArray.size())
        {
            stackArray.resize(currindex * 2);
        }

        stackArray[currindex] = data;
    }

private:
    vector<T> stackArray;
    vector<int> index;
};


int main()
{
    cout << "Use a single array to implement 3 stacks" << endl;
    Stack<int, 3> myThreeStack;

    // Add to the stack
    for (int i = 0; i < 12; ++i)
    {
        myThreeStack.push<0>(i);
    }

    for (int i = 12; i < 24; ++i)
    {
        myThreeStack.push<1>(i);
    }

    for (int i = 24; i < 36; ++i)
    {
        myThreeStack.push<2>(i);
    }

    // Remove from the stack
    vector<int> test;
    for (int i = 0; i < 12; ++i)
    {
        test.push_back(myThreeStack.pop<0>());
    }

    for (int i = 12; i < 24; ++i)
    {
        test.push_back(myThreeStack.pop<1>());
    }

    for (int i = 24; i < 36; ++i)
    {
        test.push_back(myThreeStack.pop<2>());
    }


    return 0;
}