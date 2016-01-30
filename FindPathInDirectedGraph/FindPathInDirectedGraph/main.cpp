///////////////////////////////////////////////////////
// Main
#include <iostream>
#include <vector>
#include <unordered_map>
#include <ctime>
#include <cstdlib>

using namespace std;


template <class T>
class Node
{
public:
    Node(T d) :
        mData(d),
        mItr(mEdge.begin())
    {}

    // Data Get and Set
    T getData() { return mData;  }
    void setData(T d) { mData = d; }

    // Add edge
    void addEdge(Node<T> *edge)
    {
        mEdge.insert(pair<T, Node<T>*>(edge->getData(), edge));
    }

    // Get Number of edges
    int getEdgeCount()
    {
        return mEdge.size();
    }

    // Checks if the Node has children
    bool hasChild()
    {
        return mEdge.size() > 0;
    }

    // Remove edge based on Node<T>
    void removeEdge(T d)
    {
        unordered_map<T, Node<T>*>::iterator itr = mEdge.find(d);
        if (itr != mEdge.end())
        {
            mEdge.erase(itr);
        }
    }

    // Remove based on index
    void removeEdgeAtIndex(int index)
    {
        if (index >= mEdge.size()) return;
        
        unordered_map<T, Node<T>*>::iterator itr = mEdge.begin() + index;
        if (itr != mEdge.end())
        {
            mEdge.erase(itr);
        }
    }

    // Find a edge
    Node<T>* findEdge(T d)
    {
        return mEdge.find(d);
    }

    // Set Iterator
    void resetItr()
    {
        mItr = mEdge.begin();
    }

    // Get next object. Return true if valid, else false. 
    bool nextChild()
    {
        mItr++;
        if (mItr == mEdge.end())
            return false;

        return true;
    }

    // Test to see if iter is valid
    bool isChildValid()
    {
        return mItr != mEdge.end();
    }

    // get current node
    Node<T>* getCurrentChild()
    {
        if (mItr == mEdge.end())
            return nullptr;

        return mItr->second;
    }  

private:
    T mData;
    unordered_map<T, Node<T>*> mEdge;
    typename unordered_map<T, Node<T>*>::iterator mItr;
};

/////////////////////////////////////////////////////////////////////////
// Build random Graph
Node<int>* BuildRandomGraph(int in_size)
{
    srand(time(nullptr));
    int MAX = 50;

    Node<int> *sNode = new Node<int>(rand() % MAX);

    vector<Node<int>*> buffer;
    buffer.push_back(sNode);

    for (int i = 0; i < in_size; ++i)
    {
        int bSize = buffer.size();
        Node<int> *tmp = new Node<int>(rand() % MAX);

        Node<int> *cNode = buffer[rand() % bSize];
        if (cNode)
        {
            cNode->addEdge(tmp);
            buffer.push_back(tmp);
        }
    }


    return sNode;
}


///////////////////////////////////////////////////////////////////////////
// Deallocate Directed Graph (DFS)
template<typename T>
void DeleteGraph(Node<T> *root)
{
    root->resetItr();
    
    while (root->isChildValid())
    {
        DeleteGraph(root->getCurrentChild());
        root->nextChild();
    }

    delete root;
}


int main()
{
    cout << "Find a route between two nodes in directed graph." << endl;

    Node<int> *sNode = BuildRandomGraph(10);



    DeleteGraph<int>(sNode);
    return 0;
}