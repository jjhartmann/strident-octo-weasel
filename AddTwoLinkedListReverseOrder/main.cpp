#include <iostream>

using namespace std;


template <class T>
class Node
{
public:
    // Construct new node
    Node(T d):
        data(d),
        next(nullptr)
    {}

    T getData() { return data; }
    void SetData(T d) { data = d; }
    Node<T>* getNext() { return next; }
    void setNext(Node<T> *n) { next = n; }

    // Remove this node
    void remove(Node<T> *prev)
    {
        if (prev != nullptr)
        {
            prev->setNext(next);
        }

        delete this;
    }

    // Append node to end of list
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


//////////////////////////////////////////////////////////
// Solution Class
template <class T>
class Solution
{
public:
    static Node<T>* addLinkedListsReverseOrder(Node<T> *num1, Node<T> *num2) // Don't own
    {
        // Get the first number
        int x = 0;
        int multiplier = 1;
        while (num1 != nullptr)
        {
            x = x + (num1->getData() * multiplier);
            multiplier *= 10;

            num1 = num1->getNext();
        }

        // Get the second number
        int y = 0;
        multiplier = 1;
        while (num2 != nullptr)
        {
            y = y + (num2->getData() * multiplier);
            multiplier *= 10;

            num2 = num2->getNext();
        }

        // Add the two numbers
        int total = x + y;

        // Reconstruct new linked list with number
        Node<T> *ret = new Node<T>(total % 10);
        total = total/10;

        while (total != 0)
        {
            ret->appendToEnd(total % 10);
            total = total / 10;
        }

        return ret;
    }

    static Node<T>* addLinkedListForwardOrder(Node<T> *num1, Node<T> *num2)
    {
        num1 = reverseList(num1);
        num2 = reverseList(num2);

        Node<T> *ret = addLinkedListsReverseOrder(num1, num2);
        return reverseList(ret);

    }

private:
    static Node<T>* reverseList(Node<T> *head)
    {
        Node<T> *reverse = nullptr;
        while (head != nullptr)
        {
            Node<T> *next = head->getNext();
            head->setNext(reverse);
            reverse = head;
            head = next;
        }

        return reverse;
    }
};


template <typename T>
void deleteLinkedList(Node<T> *head)
{
    while (head != nullptr)
    {
        Node<T> *n = head->getNext();
        delete head;
        head = n;

    }
}

int main()
{
    cout << "Add two numbers where each digit is represented in reverse order in a linked list." << endl;

    // Num1 = 1569
    Node<int> *num1 = new Node<int>(9);
    num1->appendToEnd(6);
    num1->appendToEnd(5);
    num1->appendToEnd(1);

    // Num2 = 2134
    Node<int> *num2 = new Node<int>(4);
    num2->appendToEnd(3);
    num2->appendToEnd(1);
    num2->appendToEnd(2);


    //Add to linked lists.
    Node<int> *res1 = Solution<int>::addLinkedListsReverseOrder(num1, num2);
    Node<int> *res2 = Solution<int>::addLinkedListForwardOrder(num1, num2);

    // Delete the linked lists
    deleteLinkedList < int > (num1);
    deleteLinkedList < int > (num2);
    deleteLinkedList < int > (res1);
    deleteLinkedList < int > (res2);

    return 0;
}