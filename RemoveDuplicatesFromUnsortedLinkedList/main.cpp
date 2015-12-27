#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>

using namespace std;

template <class T>
class Node
{
public:
    //Node
    Node(T d) :
            data(d),
            next(nullptr)
    {}

    Node<T>* getNext()
    {
        return next;
    }

    T getData()
    {
        return data;
    }

    void SetNext(Node<T> *n)
    {
        next = n;
    }

    void appendToTail(T d)
    {
        Node<T> *end = new Node(d);
        Node<T> *n = this;
        while (n->next != nullptr)
        {
            n = n->next;
        }

        // set last node
        n->next = end;
    }

private:
    T data;
    Node<T> *next;
};




int main()
{
    cout << "Remove duplicates from an unsorted linked list." << endl;

    Node<int> *head = new Node<int>(rand());

    // Create a linked list
    for (int i = 0; i < 30; ++i)
    {
        head->appendToTail(rand());
    }





    // delete linked list
    Node<int> *n;
    while (n != nullptr)
    {
        n = head->getNext();
        delete head;
        head = n;
    }

    return 0;
}