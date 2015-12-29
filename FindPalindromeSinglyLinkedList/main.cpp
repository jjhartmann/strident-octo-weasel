#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

template <class T>
class Node
{
public:
    Node(T d) :
        data(d),
        next(nullptr)
    {}

    // Get/Set
    T getData() { return data; }
    void setData(T d) { data = d; }
    Node<T>* getNext() { return next; }
    void setNext(Node<T> *n) { next = n; }

    // remove this node
    void remove(Node<T> *prev)
    {
        if (prev != nullptr)
        {
            prev->setNext(next);
        }

        delete this;
    }

    // Append new node to the end of the list
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

////////////////////////////////////////////////////////////////
// Solution class
template <class T>
class Solution
{
public:
    // Find if palindrome using a buffer (vector) to store values
     static bool isPalindromBuffer(Node<T> *head)
    {
        vector<T> buffer;
        Node<T> *n = head;
        while (n != nullptr)
        {
            buffer.push_back(n->getData());
            n = n->getNext();
        }

        int j = buffer.size() - 1;
        for (int i = 0; i < buffer.size(); ++i, --j)
        {
            if (buffer[i] != buffer[j])
            {
                return false;
            }
        }

        return true;
    }


};

////////////////////////////////////////////////////////////////
// delete list
template <typename T>
void deleteList(Node<T> *head)
{
    while (head != nullptr)
    {
        Node<T> *n = head->getNext();
        head->remove(nullptr);
        head = n;
    }
}
//main
int main()
{
    cout << "Find A palindrom in a singly linked list" << endl;

    Node<string> *oddhead = new Node<string>("a");
    oddhead->appendToEnd("b");
    oddhead->appendToEnd("c");
    oddhead->appendToEnd("b");
    oddhead->appendToEnd("a");

    Node<string> *evenhead = new Node<string>("a");
    evenhead->appendToEnd("b");
    evenhead->appendToEnd("a");
    evenhead->appendToEnd("a");
    evenhead->appendToEnd("b");
    evenhead->appendToEnd("a");

    // Check if it is palindrome
    bool res = Solution<string>::isPalindromBuffer(oddhead);

    // Delete the linked lists
    deleteList<string>(oddhead);
    deleteList<string>(evenhead);

    return 0;
}