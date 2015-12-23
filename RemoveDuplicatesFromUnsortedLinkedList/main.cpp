#include <iostream>

using namespace std;

template <class T>
class Node
{
public:
    //Node
    Node (T d)
    {
        data = d;
    }

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

private:
    T data;
    Node<T> *next;
};




int main()
{
    cout << "Remove duplicates from an unsorted linked list." << endl;

    return 0;
}