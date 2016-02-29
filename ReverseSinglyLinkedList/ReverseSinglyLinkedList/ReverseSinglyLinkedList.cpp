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

// To execute C++, please define "int main()"
int main() {

    Node<int> *head = BuildLinkedList(5, 10);
    PrintList<int>(head);


    return 0;
}
