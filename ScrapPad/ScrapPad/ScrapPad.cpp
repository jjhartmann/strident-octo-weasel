// ScrapPad.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

// Singly Linked List
template<class T>
class Node
{
public:
    Node(T d) :
        data(d),
        next(nullptr)
    {
    }

    T getData() { return data; }
    void setData(T d) { data = d; }
    Node<T>* getNext() { return next; }
    void setNext(Node<T> *n) { next = n; }

    // Delete this
    void remove(Node<T> *prev)
    {
        if (!prev)
        {
            prev->next = next;
        }

        delete this;
    }

    // Add to the end of the list
    void appendToEnd(T d)
    {
        Node<T> *n = new Node<T>(d);
        if (!next)
        {
            next = n;
            return;
        }

        Node<T> *itr = next;
        while (itr->next != nullptr)
        {
            itr = itr->next;
        }

        itr->next = n;
    }



private:
    T data;
    Node<T> *next;

};

// Recursive Fibonacci
int fibrecursive(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else if (n <= 0)
    {
        return 0;
    }

    return fibrecursive(n - 1) + fibrecursive(n - 2);
}


// Recursive Fibonacci with DP
int fibReDP(int i, vector<int> &dp)
{
    if (i == 1) return 1;
    if (i <= 0) return 0;

    if (dp[i] > 0) return dp[i];

    dp[i] = fibReDP(i - 1, dp) + fibReDP(i - 2, dp);

    return dp[i];
}

int fibReDP(int i)
{
    vector<int> dp(i + 1, 0);
    return fibReDP(i, dp);
}


// Iterative Solution
int fibiter(int n)
{
    int total = 0;
    int first = 1;
    int second = 1;

    for (int i = 2; i < n; ++i)
    {
        total = first + second;
        second = first;
        first = total;
    }

    return total;
}


///////////////////////////////////////////////////////////////
// SOlution Classes
class Solution
{
public:
    template< typename T>
    static Node<T>* reverseSingleLinkedList(Node<T> * head)
    {
        // Make sure head is valid and that linked list is > 1
        if (!head || !head->getNext()) return head;

        Node<T> *p1 = head->getNext();
        Node<T> *p2 = p1->getNext();
        head->setNext(nullptr);

        while (p1)
        {
            p1->setNext(head);
            head = p1;
            p1 = p2;

            if (p2)
            {
                p2 = p2->getNext();
            }
        }

        return head;
    }
};


int main()
{
    cout << "The scrap pad" << endl;

    //int ans = 0;
    //ans = fibrecursive(45);
    //ans = fibReDP(45);
    //ans = fibiter(45);

    Node<int> *head = new Node<int>(0);
    for (int i = 1; i < 10; ++i)
    {
        head->appendToEnd(i);
    }

    // Reverse Singly Linked List
    head = Solution::reverseSingleLinkedList<int>(head);



    return 0;
}
