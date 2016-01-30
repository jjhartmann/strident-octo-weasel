///////////////////////////////////////////////////////
// Main
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
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
        mItr(mEdge.begin()),
        mVistied(false)
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

    // Check if node has been visited
    bool isVisited()
    {
        return mVistied;
    }

    // Set As Visited
    void setVisited()
    {
        mVistied = true;
    }

private:
    T mData;
    unordered_map<T, Node<T>*> mEdge;
    typename unordered_map<T, Node<T>*>::iterator mItr;
    bool mVistied;
};

/////////////////////////////////////////////////////////////////////////
// Build random Graph
Node<int>* BuildRandomGraph(int in_size, int in_max)
{
    srand(time(nullptr));
    Node<int> *sNode = new Node<int>(rand() % in_max);

    vector<Node<int>*> buffer;
    buffer.push_back(sNode);

    for (int i = 0; i < in_size; ++i)
    {
        int bSize = buffer.size();
        Node<int> *tmp = new Node<int>(rand() % in_max);

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



///////////////////////////////////////////////////////////////////////////
// Solution Class
class Solution
{
public:
    // Recursive Method
    template<typename T>
    static bool FindNodeDFSR(Node<T> *sNode, T d)
    {
        bool found = false;
        DFSRHelper(sNode, d, found);
        return found;
    }


    // Iterative Solution
    template<typename T>
    static bool FindNodeDFS(Node<T> *sNode, T d)
    {
        stack<Node<T>*> buffer;

        buffer.push(sNode);
        while (!buffer.empty())
        {
            Node<T> *n = buffer.top();
            buffer.pop();

            if (n->getData() == d)
            {
                return true;
            }

            n->setVisited();
            n->resetItr();
            while (n->isChildValid())
            {
                Node<T> *child = n->getCurrentChild();
                if (!child->isVisited())
                {
                    child->setVisited();
                    buffer.push(child);
                }
                n->nextChild();
            }
        }

        return false;
    }

private:
    template<typename T>
    static void DFSRHelper(Node<T> *n, T d, bool &found)
    {
        if (!n || found) return;


        if (d == n->getData())
        {
            found = true;
            return;
        }

        n->resetItr();
        while (n->isChildValid() && !found)
        {
            DFSRHelper(n->getCurrentChild(), d, found);
            n->nextChild();
        }
    }
};


int main()
{
    cout << "Find a route between two nodes in directed graph." << endl;

    Node<int> *sNode = BuildRandomGraph(15, 15);

    bool res;
    res = Solution::FindNodeDFSR<int>(sNode, 10);
    res = Solution::FindNodeDFS<int>(sNode, 10);

    DeleteGraph<int>(sNode);
    return 0;
}