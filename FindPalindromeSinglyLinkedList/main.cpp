#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

template <class T>
class Node
{
public:
    Node(T d) :
        data(d),
        next(nullptr)
    {}

    // Get/Set
    T getData() { return data; }
    void setData(T d) { data = d; }
    Node<T>* getNext() { return next; }
    void setNext(Node<T> *n) { next = n; }

    // remove this node
    void remove(Node<T> *prev)
    {
        if (prev != nullptr)
        {
            prev->setNext(next);
        }

        delete this;
    }

    // Append new node to the end of the list
    void appendToEnd(T d)
    {
        Node<T> *tmp = new Node<T>(d);
        if (next == nullptr)
        {
            next = tmp;
        }

        Node<T> *n = next;
        while (n->getNext() != nullptr)
        {
            n = n->getNext();
        }

        n->setNext(tmp);
    }

private:
    T data;
    Node<T> *next;
};


int main()
{
    cout << "Find A palindrom in a singly linked list" << endl;
    return 0;
}