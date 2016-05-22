//////////////////////////////////////////////////////////
// NODE Implementation

#include "Node.h"

#include "math.h"


using namespace std;

////////////////////////////////////////////////////////////
// Public Methods
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
void Node::feedForward(float data)
{
	mData = data * mWeight;
}

// Process error and backpropogate through layers. 
void Node::backPropogate(float error)
{
	// calculate error based on error from previous
	mError = error;
	mWeight += error;
}

// Add a node to the forward output
void addForwardConnection(Node* n)
{
	
	
}

// Add a node to the backward addForwardConnection
void addBackwardConnection(Node* n)
{
	
	
}

///////////////////////////////////////////////////////////
// Private Methods
// Activation function, ReLU (Rectified Linear Unit)
float activationFunction(float data)
{
	return data > 0 ? data : 0;
}



