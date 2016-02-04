////////////////////////////////////////////////////////////////
// Main

#include <iostream>

using namespace std;


////////////////////////////////////////////////////////////////
// BST Nodes. 
enum BRANCH {
    LEFT = 0,
    RIGHT = 1,
};

template<class T>
class Node
{
public:
    Node(T d) :
        mData(d),
        mLeft(nullptr),
        mRight(nullptr)
    {}

    T getData() { return mData; }
    void setData(T d) { mData = d;  }
    

    // Retrieve child
    Node<T>* getChild(BRANCH id)
    {
        return (id == LEFT) ? mLeft : mRight;
    }

    // Set Child
    void setChild(BRANCH id, Node<T> *n)
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
    Node<T> *mLeft;
    Node<T> *mRight;

};


////////////////////////////////////////////////////////////////
// Solution Class
class Solution
{
public:
    template<typename T>
    static Node<T>* GetNextNodeInOrder(Node<T> *curr)
    {




    }
};




int main()
{
    cout << "An algorithm to determine the next node given a node in a BST (in-order)" << endl;


    return 0;
}