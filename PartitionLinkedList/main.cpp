#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>

using namespace std;

template< class T>
class Node
{
public:
    // Construct new node
    Node(T d) :
            data(d),
            next(nullptr)
    {}

    // Get data
    T getData()
    {
        return data;
    }

    // Set Data
    void setData(T d)
    {
        data = d;
    }

    // get Next ptr
    Node<T>* getNext()
    {
        return next;
    }

    // set Next prt
    void setNext(Node<T> *n)
    {
        next = n;
    }

    // Append node on end of list
    void appendToEnd(T d)
    {
        Node<T> *tmp = new Node<T>(d);
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

    // Remove this node
    void remove(Node<T> *prev)
    {
        if (prev != nullptr)
        {
            prev->setNext(next);
        }

        delete this;
    }


private:
    T data;
    Node<T> *next;
};


int main()
{
    cout << "partition a linked list around a position x" << endl;
    srand(time(nullptr));
    Node<int> *head = new Node<int>(rand() % 100);
    for (int i = 0; i < 15; ++i)
    {
        head->appendToEnd(rand() % 100);
    }

    // Partition linked list.

    // Delete linked list
    while (head != nullptr)
    {
        Node<int> *n = head->getNext();
        head->remove(nullptr);
        head = n;
    }


    return 0;
}