#include <iostream>
#include <stack>

using namespace std;

template <class T>
class MyQueue
{
public:
    // Add type T to the queue
    void add(T d)
    {
        // Always push onto s2 which holds the latest element on the top.
        s2.push(d);
    }

    // return and remove the front of the queue
    T front()
    {
        // Call the shift elements to make sure that
        shiftElements();

        T tmp = s1.top();
        s1.pop();
        return tmp;
    }

    // Return the first element.
    T peek()
    {
        shiftElements();
        return s1.top();
    }

    // Checks if the queue is empty
    bool isEmpty()
    {
        return s1.empty() && s2.empty();
    }

private:
    stack<T> s1;
    stack<T> s2;

    // Shift the elements form s2 to s1.
    // This is so we do not always shift the elements around and only when we need it.
    void shiftElements()
    {
        // Only shift when s1 is empty.
        if (s1.empty())
        {
            while (!s2.empty())
            {
                s1.push(s2.top());
                s2.pop();
            }
        }
    }


};

int main()
{
    cout << "Implement a queue using two stacks." << endl;

    MyQueue<int> q;

    for (int i = 0; i < 15; ++i)
    {
        q.add(i);
    }

    int res = 0;
    while (!q.isEmpty())
    {
        res = q.front();
    }


    return 0;
}