/////////////////////////////////////////////
// Mian
#include <iostream>
#include <vector>

template< class T >
class Node
{
public:
    Node(T d) :
        mData(d),
        mLeft(nullptr),
        mRight(nullptr)

    {
        ; // Do nothing.
    }

    // Getter and Setters
    T getData() { return mData; }
    void setData(T d) { mData = d; }
    Node<T>* getLeft() { return mLeft; }
    void setLeft(Node<T> *n) { mLeft = n; }
    Node<T>* getRight() { return mRight; }
    void setRight(Node<T> *n) { mRight = n; }

private:
    T mData;
    Node *mLeft;
    Node *mRight;
};



class Solution
{
    template <typename T>
    static Node<T>* BuildBTSFromSortedArray(const vector<T> &in_vec)
    {





    }
};



int main()
{
    return 0; 
}