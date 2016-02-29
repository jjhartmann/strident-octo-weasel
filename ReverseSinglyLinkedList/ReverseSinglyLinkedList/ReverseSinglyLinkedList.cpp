// ReverseSinglyLinkedList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

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

private:
    T mData;
    Node<T> *mNext;
};

int main()
{
    return 0;
}

