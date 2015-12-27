#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <set>
#include <ctime>

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

    void remove(Node<T> *prev)
    {
        if (prev != nullptr && next != nullptr)
        {
            prev->next = next;
            delete this;
        }
        else
        {
            delete this;
        }
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


template <class T>
class Solution
{
public:
    void removeDuplicateswithBuffer(Node<T> *head)
    {
        // Iterate through linked list and delete nodes.
        Node<T> *n = head;
        Node<T> *prev = nullptr;
        pair< typename set<T>::iterator, bool > res;
        while (n != nullptr)
        {
            res = buffer.insert(n->getData());
            if (!res.second)
            {
                n->remove(prev);
                n = prev;
            }

            //increment and set prev;
            prev = n;
            n = n->getNext();
        }
    }

private:
    set<T> buffer;
};




int main()
{
    cout << "Remove duplicates from an unsorted linked list." << endl;
    srand(time(nullptr));
    Node<int> *head = new Node<int>(rand() % 30);

    // Create a linked list
    for (int i = 0; i < 30; ++i)
    {
        head->appendToTail(rand() % 30);
    }


    // Remove duplicates using buffer
    Solution<int> sol;
    sol.removeDuplicateswithBuffer(head);


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