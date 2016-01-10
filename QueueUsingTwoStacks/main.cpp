#include <iostream>
#include <stack>

using namespace std;

template <class T>
class MyQueue
{
public:
    // Add type T to the queue
    void push(T d)
    {
        // (1) empty the initial stack and place in stack 2
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }

        // Add data to initial stack
        s1.push(d);

        // (2) Empty stack 2 and place back in stack 1.
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    // return and remove the front of the queue
    T front()
    {
        T tmp = s1.top();
        s1.pop();
        return tmp;
    }

    // Checks if the queue is empty
    bool isEmpty()
    {
        return s1.empty();
    }

private:
    stack<T> s1;
    stack<T> s2;

};

int main()
{
    cout << "Implement a queue using two stacks." << endl;

    MyQueue<int> q;

    for (int i = 0; i < 15; ++i)
    {
        q.push(i);
    }

    int res = 0;
    while (!q.isEmpty())
    {
        res = q.front();
    }


    return 0;
}