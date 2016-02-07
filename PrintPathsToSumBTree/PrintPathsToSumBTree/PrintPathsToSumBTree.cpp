// PrintPathsToSumBTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
#include <vector>
#include <queue>


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
    T mData;
    Node<T> *mLeft; // Don't Own
    Node<T> *mRight; // Don't Own
    Node<T> *mParent; // Don't Own
};


// Build Random Binary Tree
Node<int>* GenerateRandomBTree(int size, int MAX_VAL)
{
    srand(time(NULL));

    Node<int> *root = new Node<int>(rand() % MAX_VAL);
    vector<Node<int>*> buffer;
    buffer.push_back(root);

    for (int i = 0; i < size; ++i)
    {
        int bsize = buffer.size();
        int bindex = rand() % bsize;
        Node<int> *p = buffer[bindex];
        Node<int> *tmp = new Node<int>(rand() % MAX_VAL);

        bool isLeft = (p->getNode(LEFT)) ? true : false;
        bool isRight = (p->getNode(RIGHT)) ? true : false;
        bool inserted = false;
        if (rand() % 2)
        {
            // Try left
            if (!isLeft)
            {
                p->setNode(LEFT, tmp);
                inserted = true;
                isLeft = true;
            }
            else if (!isRight)
            {
                p->setNode(RIGHT, tmp);
                isRight = true;
                inserted = true;
            }
        }
        else
        {
            // Try left
            if (!isRight)
            {
                p->setNode(RIGHT, tmp);
                inserted = true;
                isRight = true;
            }
            else if (!isLeft)
            {
                p->setNode(LEFT, tmp);
                isLeft = true;
                inserted = true;
            }

        }

        // Set Parent
        if(inserted)
            tmp->setNode(PARENT, p);


        if (isLeft && isRight && inserted)
        {
            buffer[bindex] = tmp;
        }
        else if (inserted)
        {
            buffer.push_back(tmp);
        }
        else
        {
            buffer.erase(buffer.begin() + bindex);
            delete tmp;
        }
    }


    return root;
}


// Deallocate BTree
template<typename T>
void DeallocateBTree(Node<T> *root)
{
    if (!root) return;

    DeallocateBTree(root->getNode(LEFT));
    DeallocateBTree(root->getNode(RIGHT));

    delete root;
    root = nullptr;
}

//////////////////////////////////////////////////////////////////////
// Solution Class
class Solution
{
public:
    static void PrintAllPathsToSum(Node<int> *n, string path, const int val, int sum)
    {
        if (!n) return;

        // Return if subtree is greater then sum.
        int d = n->getData();
        sum += d;
        if (sum > val) return;

        // When we have a match, print path. 
        if (sum == val)
        {
            std::printf("%s_(%i)->END \n", path.c_str(),d);
            // Let the recursion continue in case next nodes contain '0'
        }

        // Recurse
        PrintAllPathsToSum(n->getNode(LEFT), path + "_(" + to_string(d) + ")->LEFT", val, sum);
        PrintAllPathsToSum(n->getNode(RIGHT), path + "_(" + to_string(d) + ")->RGHT", val, sum);
    }


private:


};


int main()
{
    cout << "Print all paths that sum to a certain value in BTree" << endl;

    Node<int> *root = GenerateRandomBTree(100000, 10);

    string path = "ROOT";
    Solution::PrintAllPathsToSum(root, path, 45, 0);


    DeallocateBTree(root);
    return 0;
}

