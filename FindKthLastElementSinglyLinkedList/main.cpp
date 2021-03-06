#include <iostream>
#include <cmath>
#include <vector>
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



template <class T>
class Solution
{
public:
    static Node<T>* findKthElementfromLast(Node<T> *head, int k)
    {
        vector<Node<T> *> buffer;
        Node<T> *n = head;
        int size = 0;

        // Find size and store every 10th pointer in buffer.
        while (n != nullptr)
        {
            if (size != 0 && size % 10 == 0)
            {
                buffer.push_back(n);
            }

            ++size;
            n = n->getNext();
        }

        // determine distance from head
        int distance = size - k;
        int index = floor(distance / 10) - 1;
        int delta = distance % 10;

        n = buffer[index];
        for (int i = 0; i < delta; ++i)
        {
            n = n->getNext();
        }

        return n;

    }


    // Using Recursion
    static Node<T>* findKthToLastRecursion(Node<T> *n, int k, int &i)
    {
        if (n == nullptr)
        {
            return nullptr;
        }

        Node<T> *tmp = findKthToLastRecursion(n->getNext(), k, i);
        ++i;

        if (k == i)
        {
            return n;
        }

        return tmp;
    }


    // Using duel pointers
    static Node<T>* findKthToLastDuelPointers(Node<T> *head, int k)
    {
        Node<T> *p1 = head;
        Node<T> *p2 = head;

        // Go to kth element in p1.
        for (int i = 0; i < k; ++i)
        {
            if(!p1) return nullptr;

            p1 = p1->getNext();
        }

        // Iterate both pointers until p1 is nullptr. Return p2.
        while (p1 != nullptr)
        {
            p1 = p1->getNext();
            p2 = p2->getNext();
        }

        return p2;

    }

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
//   Node<int> *res = Solution<int>::findKthElementfromLast(head, 3);
//    int tmp = 0;
//    Node<int> *res = Solution<int>::findKthToLastRecursion(head, 3, tmp);
    Node<int> *res = Solution<int>::findKthToLastDuelPointers(head, 3);


    // Delete Nodes
    while (head != nullptr)
    {
        Node<int> *tmp = head->getNext();
        head->remove(nullptr);
        head = tmp;
    }

    return 0;
}