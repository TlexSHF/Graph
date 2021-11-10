#include <memory>
#include <iostream>
#include "Graph.h"

int main() {

	Graph<int> graph;

	std::shared_ptr<Vertex<int>> nodePtrA = graph.insertNode(5);
	auto nodePtrB = graph.insertNode(2);
	auto nodePtrC = graph.insertNode(3);
	auto nodePtrD = graph.insertNode(1);
	auto nodePtrE = graph.insertNode(7);

	std::shared_ptr<Edge<int>> edgePtrV = graph.insertEdge(nodePtrA, nodePtrB);
	auto edgePtrW = graph.insertEdge(nodePtrA, nodePtrC);
	auto edgePtrX = graph.insertEdge(nodePtrC, nodePtrD);
	auto edgePtrY = graph.insertEdge(nodePtrC, nodePtrE);
	auto edgePtrZ = graph.insertEdge(nodePtrE, nodePtrD);

	graph.printGraph();

	graph.removeEdge(edgePtrV);
	graph.removeEdge(edgePtrW);
	graph.removeEdge(edgePtrX);
	graph.removeEdge(edgePtrY);
	graph.removeEdge(edgePtrZ);

	graph.removeNode(nodePtrA);
	graph.removeNode(nodePtrB);
	graph.removeNode(nodePtrC);
	graph.removeNode(nodePtrD);
	graph.removeNode(nodePtrE);

	edgePtrV = nullptr;
	edgePtrW = nullptr;
	edgePtrX = nullptr;
	edgePtrY = nullptr;
	edgePtrZ = nullptr;

	nodePtrA = nullptr;
	nodePtrB = nullptr;
	nodePtrC = nullptr;
	nodePtrD = nullptr;
	nodePtrE = nullptr;

	return 0;
}