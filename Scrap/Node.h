/////////////////////////////////////////////////
// Class Node:
// 
// Implements a standard neuron in for interaction
#ifndef HH_CLASS_NODE
#define HH_CLASS_NODE

#include <vector>

using namespace std;

class Node
{
	public:
	Node(float weight);
	~Node();
	
	float feedForward(float data);
	float backPropogate(float error);
	
	void addFowardConnection(Node* n);
	void addBackwardConnection(Node* n);	
	
	private:
	// Private Vars
	float mWeight;
	std::vector<Node*> mConnectionForward;
	std::vector<Node*> mConnectionBackward;

	//Private Methods
	float activationFunction(float data);
};

#endif