#pragma once
#include <vector>
#include <memory>
#include "Vertex.h"

template <typename T>
class Graph {
public:
	Graph();
	std::shared_ptr<Vertex<T>> insertNode(T val);
	std::shared_ptr<Edge<T>> insertEdge(std::shared_ptr<Vertex<T>> nodeA, std::shared_ptr<Vertex<T>> nodeB);
	void removeNode(std::shared_ptr<Vertex<T>> node);
	void removeEdge(std::shared_ptr<Edge<T>> edge);
	void printGraph();
private:
	std::vector<std::shared_ptr<Vertex<T>>> m_nodePtrVector;
	typename std::vector<std::shared_ptr<Vertex<T>>>::iterator findNode(std::shared_ptr<Vertex<T>> node);
};

template<typename T>
Graph<T>::Graph() {}

template<typename T>
std::shared_ptr<Vertex<T>> Graph<T>::insertNode(T val) {
	std::shared_ptr<Vertex<T>> nodePtr{ std::make_shared<Vertex<T>>(val) };
	m_nodePtrVector.push_back(nodePtr);
	return nodePtr;
}

template<typename T>
std::shared_ptr<Edge<T>> Graph<T>::insertEdge(std::shared_ptr<Vertex<T>> nodeA, std::shared_ptr<Vertex<T>> nodeB) {
	std::shared_ptr<Edge<T>> edgePtr{ std::make_shared<Edge<T>>(nodeA, nodeB) };

	auto itA = findNode(nodeA);
	auto itB = findNode(nodeB);

	if (itA != m_nodePtrVector.end() && itB != m_nodePtrVector.end()) {
		nodeA->addEdge(edgePtr);
		nodeB->addEdge(edgePtr);
	}
	return edgePtr;
}

template<typename T>
void Graph<T>::removeNode(std::shared_ptr<Vertex<T>> node) {
	auto it = findNode(node);
	m_nodePtrVector.erase(it);
}

template<typename T>
void Graph<T>::removeEdge(std::shared_ptr<Edge<T>> edge) {
	std::shared_ptr<Vertex<T>> nodeA{ edge->getA() };
	std::shared_ptr<Vertex<T>> nodeB{ edge->getB() };
	
	auto itA = findNode(nodeA);
	auto itB = findNode(nodeB);

	if (itA != m_nodePtrVector.end() && itB != m_nodePtrVector.end()) {
		nodeA->removeEdge(edge);
		nodeB->removeEdge(edge);
	}
}

template<typename T>
void Graph<T>::printGraph() {
	for (int i{ 0 }; i < m_nodePtrVector.size(); i++) {
		m_nodePtrVector[i]->printEdges();
	}
}

template<typename T>
typename std::vector<std::shared_ptr<Vertex<T>>>::iterator Graph<T>::findNode(std::shared_ptr<Vertex<T>> node) {
	typename std::vector<std::shared_ptr<Vertex<T>>>::iterator it{ m_nodePtrVector.begin() };

	while (it != m_nodePtrVector.end()) {
		if (*it == node) {
			//Node was found
			break;
		}
		it++;
	}

	//If it == vertices.end => indicates the node was not found
	return it;
}
