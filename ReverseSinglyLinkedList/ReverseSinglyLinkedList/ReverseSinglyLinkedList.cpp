// ReverseSinglyLinkedList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

// Node Class
template <class T>
class Node
{
public:
    Node(T d) :
        mData(d),
        mNext(nullptr)
    {}

    // Getter/Setter
    Node<T>* getNext()
    {
        return mNext;
    }

    void setNext(Node<T> *n)
    {
        mNext = n;
    }

    T getData()
    {
        return mData;
    }

private:
    T mData;
    Node<T> *mNext;
};


// Build Simple List
Node<int>* BuildLinkedList(int size, int MAX)
{
    srand(time(NULL));
    Node<int> *head = new Node<int>(rand() % MAX);

    Node<int> *ptr = head;
    for (int i = 0; i < size - 1; ++i)
    {
        ptr->setNext(new Node<int>(rand() % MAX));
        ptr = ptr->getNext();
    }

    return head;
}

// Print List 
template<typename T>
void PrintList(Node<T> *n)
{
    while (n != nullptr)
    {
        cout << n->getData() << "\t";
        n = n->getNext();
    }
    cout << endl;
}


// Reverse the linked List. 
template <typename T>
Node<T>* ReverseList(Node<T> *head)
{
    if (!head) return nullptr;
    if (!head->getNext()) return head;
    if (!head->getNext()->getNext())
    {
        Node<T> *tmp = head;
        head = tmp->getNext();
        head->setNext(tmp);
        tmp->setNext(nullptr);
        return head;
    }

    // REverse list > 2
    Node<T> *ptr1 = head->getNext();
    Node<T> *ptr2 = ptr1->getNext();
    head->setNext(nullptr);
    
    while (ptr2)
    {
        ptr1->setNext(head);
        head = ptr1;
        ptr1 = ptr2;
        ptr2 = ptr2->getNext();
    }

    // Last switch
    ptr1->setNext(head);
    head = ptr1;
    
    return head;
}



// To execute C++, please define "int main()"
int main() {

    Node<int> *head = BuildLinkedList(20, 50);
    PrintList<int>(head);
    head = ReverseList(head);
    PrintList(head);

    return 0;
}
