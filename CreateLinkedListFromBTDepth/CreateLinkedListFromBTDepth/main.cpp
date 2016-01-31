////////////////////////////////////////////////////////////////
// Main

#include <iostream>

using namespace std;

enum CHILDID{
    LEFT = 0,
    RIGHT = 1
};

////////////////////////////////////////////////////////////////
// Binary Tree Node
template<class T>
class TNode
{
public:
    TNode(T d) :
        mData(d),
        mLeft(nullptr),
        mRight(nullptr)
    {}

    // Get and set
    T getData() { return mData;  }
    void setData(T d) { mData = d; }
    TNode<T>* getChild(CHILDID id)
    {
        return (id == LEFT) ? mLeft : mRight;
    }

    void setChild(CHILDID id, TNode<T> *n)
    {
        if (id == LEFT)
        {
            mLeft = n;
        }
        else
        {
            mRight = n;
        }
    }

private:
    T mData;
    TNode<T> *mLeft;
    TNode<T> *mRight;
};



int main()
{

    cout << "Create a vector linked lists for each depth of a binary tree" << endl;




    return 0;
}