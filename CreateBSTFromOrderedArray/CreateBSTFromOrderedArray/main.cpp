/////////////////////////////////////////////
// Main
#include <iostream>
#include <vector>

using namespace std;

template< class T >
class Node
{
public:
    Node() :
        mData(-1),
        mLeft(nullptr),
        mRight(nullptr)

    {
        ; // Do nothing.
    }

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
public:
    
    template< typename T >
    static Node<T>* BuildBTSFromSortedArray(const vector<T> &in_vec)
    {

        int index = ceil(double(in_vec.size()) / 2);
        int b = 0;
        int e = in_vec.size() - 1;

        Node<T> *root = new Node<T>(in_vec[index]);

        // Create Empty Nodes.
        root->setLeft(new Node<T>());
        root->setRight(new Node<T>()); 


        buildRec<int>(root->getLeft(), b, index - 1, in_vec);
        buildRec<int>(root->getRight(), index + 1, e, in_vec);

        return root;
    }

private:
    template< typename T>
    static void buildRec(Node<T> *n, int b, int e, const vector<T> &v)
    {
        // Base case
        if (!n) return;
        
        int index = b + ceil((float(e) - float(b)) / 2);
        n->setData(v[index]);

        // Base Case
        if (b >= e) return;

        // Create new nodes.
        n->setLeft(new Node<T>());
        
        if (e - b > 1)
            n->setRight(new Node<T>());

        buildRec(n->getLeft(), b, index - 1, v);
        buildRec(n->getRight(), index + 1, e, v);
    }
};



int main()
{
    vector<int> test = { 0,1,2,3,4,5,6,7 };
    Node<int>* res = Solution::BuildBTSFromSortedArray<int>(test);
    return 0; 
}