#include <iostream>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <unordered_set>
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

    void setNext(Node<T> *node)
    {
        next = node;
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
        if (prev != nullptr)
        {
            prev->next = next;
        }

        delete this;
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
        pair< typename unordered_set<T>::iterator, bool > res;
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

    // Remove duplicates with sort
    void removeDuplicatesSort(Node<T> *head)
    {
        // sort the linked list
        head = merge_sort(head);

        // Remove the duplicates
        Node<T> *n = head;
        while (n->getNext() != nullptr)
        {
            if (n->getData() == n->getNext()->getData())
            {
                Node<T> *dup = n->getNext();
                dup->remove(n);
            }

            n = n->getNext();
        }
    }


private:
    Node<T>* merge_sort(Node<T> *n)
    {
        if (n == nullptr || n->getNext() == nullptr)
        {
            return n;
        }

        Node<T> *left = nullptr;
        Node<T> *right = nullptr;
        Node<T> *tmpl = nullptr;
        Node<T> *tmpr = nullptr;

        // init right and left
        if (n != nullptr)
        {
            left = n;
            n = n->getNext();
            left->setNext(nullptr);
            tmpl = left;
        }


        if (n != nullptr)
        {
            right = n;
            n = n->getNext();
            right->setNext(nullptr);
            tmpr = right;
        }

        int i = 2;
        while (n != nullptr)
        {
            // Split the linked list into half.
            if (i % 2 == 0)
            {
                tmpl->setNext(n);
                n = n->getNext();
                tmpl = tmpl->getNext();
                tmpl->setNext(nullptr);
            }
            else
            {
                tmpr->setNext(n);
                n = n->getNext();
                tmpr = tmpr->getNext();
                tmpr->setNext(nullptr);
            }
            ++i;
        }


        left = merge_sort(left);
        right = merge_sort(right);

        return mergeList(left, right);
    }


    // Merge the list together
    Node<T>* mergeList(Node<T> *left, Node<T> *right)
    {
        Node<T> *result = nullptr;
        if (left->getData() < right->getData())
        {
            result = left;
            left = left->getNext();
        }
        else
        {
            result = right;
            right = right->getNext();
        }

        Node<T> *res = result;

        // Merge the two linked lists
        while (left != nullptr && right != nullptr)
        {
            if (left->getData() < right->getData())
            {
                res->setNext(left);
                left = left->getNext();
            }
            else
            {
                res->setNext(right);
                right = right->getNext();
            }

            res = res->getNext();
        }

        // Check whether either left or right have left over nodes.
        while (left != nullptr)
        {
            res->setNext(left);
            left = left->getNext();
            res = res->getNext();
        }

        while (right != nullptr)
        {
            res->setNext(right);
            right = right->getNext();
            res = res->getNext();
        }

        return result;
    }

    // Buffer used in the buffer impl.
    unordered_set<T> buffer;
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
//    sol.removeDuplicatesSort(head);

    // delete linked list
    Node<int> *n;
    while (head != nullptr)
    {
        n = head->getNext();
        delete head;
        head = n;
    }

    return 0;
}