#pragma once
#include <vector>
#include <memory>
#include "Vertex.h"

template <typename T>
class Graph {
public:
	Graph();
	std::shared_ptr<Vertex<T>> insertNode(T val);
	void insertEdge(std::shared_ptr<Vertex<T>> nodeA, std::shared_ptr<Vertex<T>> nodeB);
private:
	std::vector<std::shared_ptr<Vertex<T>>> m_nodePtrVector;
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
void Graph<T>::insertEdge(std::shared_ptr<Vertex<T>> nodeA, std::shared_ptr<Vertex<T>> nodeB) {
	for (int i{ 0 }; i < m_nodePtrVector.size(); i++) {
		if (m_nodePtrVector[i] == nodeA) {
			m_nodePtrVector[i]->connectNode(nodeB);
		}
	}

}
