/////////////////////////////////////////////
#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>

#include "Node.h"

using namespace std;

#define NNET vector< vector<Node*> >


NNET BuildNet(int layers, int height)
{
	srand(time(0));
	NNET Net(layers, vector<Node*>(height));
	
	for (auto& layer : Net)
	{
		for (auto& node : layer)
		{
			float weight = static_cast<float>(rand() % 1000)/1000.0f;
			cout << weight << endl;
			node = new Node(weight);
		}
	}
	
	return Net;
}

void PrintNet(NNET &net)
{
	for (auto& layer : net)
	{
		for (auto& node : layer)
		{
			printf("%d\t", node->getWeight());
			// cout << node->getWeight() << endl;;
		}
		printf("\n");
	}
	
	
}


int main()
{
	// Test
	cout << "Test" << endl;
	NNET net = BuildNet(3, 4);
	PrintNet(net);
	
	
	
	
	
	
	
	
	return 0;
}