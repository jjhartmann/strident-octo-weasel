#include <iostream>

using namespace std;

template< class T >
class Node
{
public:
    Node(T d) :
        data(d),
        mLeft(nullptr),
        mRight(nullptr),
    {}

    Node<T>* getRight()
    {
        return mRight;
    }

    void setRight(Node<T> *n)
    {
        mRight = n;
    }

    Node<T>* getLeft()
    {
        return mLeft;
    }

    void setLeft(Node<T> *n)
    {
        mLeft = n;
    }

    T getData()
    {
        return mData;
    }
    


private:
    T mData;
    Node<T> *mLeft;
    Node<T> *mRight;
};


///////////////////////////////////
// Delete Entire Tree
template <typename T>
void DeleteTree(Node<T> *root)
{
    if (!root)
    {
        return;
    }

    DeleteTree(root->getLeft);
    DeleteTree(root->getRight);
    delete root;
}


int main()
{
    cout << "Check to see if a binary tree is balanced" << endl;
    return 0;
}