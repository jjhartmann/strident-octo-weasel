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

/////////////////////////////////////////////////////////////////
// Solution Class
template <class T>
class Solution
{
public:
    static Node<T>* partitionList(Node<T> *head, int x)
    {
        Node<T> *lwiter = nullptr;
        Node<T> *n = head;
        Node<T> *uphead = head;
        Node<T> *upiter = nullptr;

        while (n != nullptr)
        {
            if (n->getData() <= x)
            {
                // Add node to lower list.
                if (lwiter == nullptr)
                {
                    lwiter = n;
                    head = lwiter;
                }
                else
                {
                    lwiter->setNext(n);
                    lwiter = lwiter->getNext();
                }

            }
            else
            {
                // Upper Parition
                if (upiter == nullptr)
                {
                    upiter = n;
                    uphead = upiter;
                }
                else
                {
                    upiter->setNext(n);
                    upiter = upiter->getNext();
                }
            }

            n = n->getNext();
            if (lwiter != nullptr) lwiter->setNext(nullptr);
            if (upiter != nullptr) upiter->setNext(nullptr);
        }

        // Connect the lower and upper paritions
        lwiter->setNext(uphead);
        return head;
    }


    // Different approach to partitioning linked list
    static Node<T>* partitionList2(Node<T> *n, int x)
    {
        Node<T> *lwhead = nullptr;
        Node<T> *uphead = nullptr;

        while (n != nullptr)
        {
            Node<T> *next = n->getNext();
            if (n->getData() <= x)
            {
                n->setNext(lwhead);
                lwhead = n;
            }
            else
            {
                n->setNext(uphead);
                uphead = n;
            }

            n = next;
        }

        // Find the end of lwhead and merge lists
        Node<T> *head = lwhead;
        while (lwhead->getNext() != nullptr)
        {
            lwhead = lwhead->getNext();
        }

        lwhead->setNext(uphead);
        return head;
    }
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
    head = Solution<int>::partitionList2(head, 50);

    // Delete linked list
    while (head != nullptr)
    {
        Node<int> *n = head->getNext();
        head->remove(nullptr);
        head = n;
    }


    return 0;
}