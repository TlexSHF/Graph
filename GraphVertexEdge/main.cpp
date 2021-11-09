#include <memory>
#include <iostream>
#include "Edge.h"


int main() {

	std::shared_ptr<Vertex<int>> nodePtrA{ std::make_shared<Vertex<int>>(5) };
	std::shared_ptr<Vertex<int>> nodePtrB{ std::make_shared<Vertex<int>>(2) };

	nodePtrA->connectNode(nodePtrB);
	std::cout << nodePtrA->getEdges()[0]->getA()->getVal() << std::endl;
	std::cout << nodePtrA->getEdges()[0]->getB()->getVal() << std::endl;
	std::cout << nodePtrB->getEdges()[0]->getA()->getVal() << std::endl;
	std::cout << nodePtrB->getEdges()[0]->getB()->getVal() << std::endl;

	//DELETION DOES NOT WORK YET
	//nodePtrA = { nullptr };

	return 0;
}