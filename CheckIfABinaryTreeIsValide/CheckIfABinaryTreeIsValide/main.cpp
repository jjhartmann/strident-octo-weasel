/////////////////////////////////////////////////////////////////
// Main


#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>


using namespace std;

enum NODE_ID
{
    LEFT = 0,
    RIGHT,
};

template<class T>
class TNode
{
public:
    TNode(T d) :
        mData(d),
        mLeft(nullptr),
        mRight(nullptr)
    {}

    ~TNode()
    {
        mLeft = nullptr;
        mRight = nullptr;
        mData = -1;
    }

    // Get and Set
    T getData() { return mData; }
    void setData(T d) { mData = d }
    TNode<T>* getChild(NODE_ID id)
    {
        return (id == LEFT) ? mLeft : mRight;
    }

    void setChild(NODE_ID id, TNode<T> *n)
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
    cout << "Check to see if a binary tree is in fact a binary search tree." << endl;

    return 0;
}