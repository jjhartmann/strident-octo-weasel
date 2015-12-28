#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


template <class T>
class Node
{
public:
    // Construct new node
    Node(T d) :
        data(d),
        next(nullptr)
    {    }

    // get the next pointer
    Node<T>* getNext()
    {
        return next;
    }

    // Set the next pointer to different node
    void setNext(Node<T> *n)
    {
        next = n;
    }

    // Get the current value of the data
    T getData()
    {
        return data;
    }

    // remove the current (this) node
    void remove(Node<T> *prev)
    {
        if (prev != nullptr)
        {
            prev->setNext(next);
        }

        delete this;
    }

    // Add a new node to the end of the linked list.
    // Return true if success
    void appendToEnd(T d)
    {
        Node<T> *tmp = new Node(d);
        if (next == nullptr)
        {
            next = tmp;
        }
        else
        {
            Node<T> *n = next;
            while (n->getNext() != nullptr)
            {
                n = n->getNext();
            }

            n->setNext(tmp);
        }
    }

private:
    T data;
    Node<T> *next;

};



int main()
{
    cout << "Find the Kth to last element in a singly linked list." << endl;

    // Build the Linked List
    srand(time(nullptr));
    Node<int> *head = new Node<int>(rand() % 100);
    for (int i = 0; i < 15; ++i)
    {
        head->appendToEnd(rand() % 100);
    }

    // Find kth to last node.
    

    // Delete Nodes
    while (head != nullptr)
    {
        Node<int> *tmp = head->getNext();
        head->remove(nullptr);
        head = tmp;
    }

    return 0;
}