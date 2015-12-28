#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>

using namespace std;

template< class T>
class Node
{
public:
    // Construct new node.
    Node(T d) :
            data(d),
            next(nullptr)
    {}

    // Set Next Node
    void setNext(Node<T> *n)
    {
        next = n;
    }

    // Get NExt
    Node<T>* getNext()
    {
        return next;
    }

    // Set Data
    void setData(T d)
    {
        data = d;
    }

    // Get data;
    T getData()
    {
        return data;
    }

    // remove this node.
    void remove(Node<T> *prev)
    {
        if (prev != nullptr)
        {
            prev->setNext(next);
        }

        delete this;
    }

    // Append new node to the end
    void appendToEnd(T d)
    {
        Node<T> *tmp = new Node(d);
        if (next == nullptr)
        {
            next = tmp;
            return;
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
    cout << "Delete a node in the middle of a singly linked list." << endl;

    // Build new linked list
    srand(time(nullptr));
    Node<int> *head = new Node<int>(rand() % 15);
    for (int i = 0; i < 15; ++i)
    {
        head->appendToEnd(rand() % 15);
    }

    // Delete middle node. 


    // delete all linked list nodes
    while (head != nullptr)
    {
        Node<int> *n = head->getNext();
        head->remove(nullptr);
        head = n;
    }

    return 0;
}