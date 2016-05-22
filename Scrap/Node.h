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
	
	void feedForward(float data);
	void backPropogate(float error);
	
	void addFowardConnection(Node* n);
	void addBackwardConnection(Node* n);	
	
	inline void setWeight(float w) {mWeight = w;}
	inline float getWeight(){ return mWeight; }
	float getData();
	float getError();
	
	private:
	// Private Vars
	float mWeight;
	float mData;
	float mError;
	std::vector<Node*> mConnectionForward;
	std::vector<Node*> mConnectionBackward;

	//Private Methods
	float activationFunction(float data);
};

#endif