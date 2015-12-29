#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

template< class T>
class Node
{
public:
    Node(T d) :
            data(d),
            next(nullptr)
    {}

    // Get and set
    T getData() { return data; }
    void setData(T d) {data = d; }
    Node<T>* getNext() { return next; }
    void setNext(Node<T> *n) { next = n; }

    // Append new node to end of list
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


////////////////////////////////////////////////////////////////////
// Solution class
template <class T>
class Solution
{
public:
    static Node<T>* findBeginningofLoop(Node<T> *head)
    {
        Node<T> *pt1 = head->getNext();
        Node<T> *pt2 = (head->getNext()) != nullptr ? head->getNext()->getNext() : nullptr;

        // Find the collision point
        int count = 2;
        while (pt1 != pt2)
        {
            if (pt1 == nullptr || pt2 == nullptr)
            {
                return nullptr;
            }

            if (count % 2 == 0)
            {
                pt1 = pt1->getNext();
            }

            pt2 = pt2->getNext();
            ++count;
        }


        // Set pt1 to head and both iterate until collision
        // Since now pt1 and pt2 are both k nodes away from the collision point.
        pt1 = head;
        while (pt1 != pt2)
        {
            pt1 = pt1->getNext();
            pt2 = pt2->getNext();
        }

        return pt1;
    }
};


int main()
{
    cout << "Find the beginning of a loop in a linked list" << endl;

    srand(time(nullptr));
    // create a node with a loop
    Node<int> *head = new Node<int>(0);
    for (int i = 0; i < 10; ++i)
    {
        head->appendToEnd(i + 1);
    }

    Node<int> *loopbegin = head;
    int randnum = (rand() % 5) + 3;
    for (int i = 0; i < randnum; ++i)
    {
        loopbegin = loopbegin->getNext();
    }

    Node<int> *lastNode = head;
    while (lastNode->getNext() != nullptr)
    {
        lastNode = lastNode->getNext();
    }

    lastNode->setNext(loopbegin);


    // Solution to find the beginning of a loop.
    Node<int> *res = Solution<int>::findBeginningofLoop(head);

    ////////////////////////////////////
    // Delete list
    while (head != nullptr)
    {
        Node<int> *n = head->getNext();
        head->remove(nullptr);
        head = n;
    }

    return 0;
}