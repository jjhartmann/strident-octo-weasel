#include <iostream>

using namespace std;


template <class T>
class Node
{
public:
    // Construct new node
    Node(T d):
        data(d),
        next(nullptr)
    {}

    T getData() { return data; }
    void SetData(T d) { data = d; }
    Node<T>* getNext() { return next; }
    void setNext(Node<T> *n) { next = n; }

    // Remove this node
    void remove(Node<T> *prev)
    {
        if (prev != nullptr)
        {
            prev->setNext(next);
        }

        delete this;
    }

    // Append node to end of list
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
private:
    T data;
    Node<T> *next;
};

template <typename T>
void deleteLinkedList(Node<T> *head)
{
    while (head != nullptr)
    {
        Node<T> *n = head->getNext();
        delete head;
        head = n;

    }
}

int main()
{
    cout << "Add two numbers where each digit is represented in reverse order in a linked list." << endl;

    // Num1 = 1569
    Node<int> *num1 = new Node<int>(9);
    num1->appendToEnd(6);
    num1->appendToEnd(5);
    num1->appendToEnd(1);

    // Num2 = 2134
    Node<int> *num2 = new Node<int>(4);
    num2->appendToEnd(3);
    num2->appendToEnd(1);
    num2->appendToEnd(2);


    // Delete the linked lists
    deleteLinkedList < int > (num1);
    deleteLinkedList < int > (num2);

    return 0;
}