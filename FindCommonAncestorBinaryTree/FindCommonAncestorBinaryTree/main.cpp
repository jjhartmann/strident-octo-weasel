////////////////////////////////////////////////////////////////////
// Main - Find common ancestor
#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>

using namespace std;


enum NODEID {
    LEFT = 0, 
    RIGHT, 
    PARENT,
};

template<class T>
class Node
{
public:
    Node(T d) :
        mData(d),
        mLeft(nullptr),
        mRight(nullptr),
        mParent(nullptr)
    {}

    ~Node()
    {
        mLeft = nullptr;
        mRight = nullptr;
        mParent = nullptr;
    }

    // Get and Set
    T getData() { return mData; }
    void setData(T d) { mData = d; }
    
    Node<T>* getNode(NODEID id)
    {
        if (id == PARENT) return mParent;
        if (id == LEFT) return mLeft;
        return mRight;
    }
    
    void setNode(NODEID id, Node<T> *n)
    {
        if (id == PARENT) mParent = n;
        if (id == LEFT) mLeft = n;
        if (id == RIGHT) mRight = n;
    }



private:
    Node<T> *mLeft; // Don't Own
    Node<T> *mRight; // Don't Own
    Node<T> *mParent; // Don't Own
    T mData;
};







int main()
{
    cout << "Given two nodes, find the common ancestor in a binary tree" << endl;





    return 0;
}