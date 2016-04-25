//////////////////////////////////////////////////////////
// NODE Implementation

#include "Node.h"

#include "math.h"

using namespace std;


// Constructor
Node::Node(float weight):
	mWeight(weight)
{
		
}

// Deconstructor
Node::~Node()
{
	
}

// Mehtod to process data in a feed forward network
float Node::feedForward(float data)
{
	for (auto& node : mConnectionForward)
	{
		node->feedForward(data * mWeight);
	}
	return 0;
}

// Process error and backpropogate through layers. 
float Node::backPropogate(float error)
{
	
	
	return 0;
}

// Add a node to the forward output
void addForwardConnection(Node* n)
{
	
	
}

// Add a node to the backward addForwardConnection
void addBackwardConnection(Node* n)
{
	
	
}

// Activation function, ReLU (Rectified Linear Unit)
float activationFunction(float data)
{
	return data > 0 ? data : 0;
}



