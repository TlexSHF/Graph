#pragma once
#ifndef VERTEX
#define VERTEX

#include <memory>
#include <vector>
#include "Edge.h"

template <typename T>
class Edge;

template <typename T>
class Vertex {
public:
	Vertex(T val);
	~Vertex();
	T getVal() const;
	std::vector<std::shared_ptr<Edge<T>>> getEdges() const;
	std::shared_ptr<Edge<T>> connectNode(std::shared_ptr<Vertex> node);
	void removeEdge(std::shared_ptr<Edge<T>> edge);
	void printEdges();
	void addEdge(std::shared_ptr<Edge<T>> edge);
private:
	T m_val;
	std::vector<std::shared_ptr<Edge<T>>> m_edgePtrVector;
};

template<typename T>
Vertex<T>::Vertex(T val) :
	m_val{ val } {
	std::cout << "Constructing Vertex: " << m_val << std::endl;
}

template<typename T>
Vertex<T>::~Vertex() {
	//When a vertex gets deleted, the destructors in the edgePtrVector are called
	//They will delete themselves from their nodes if they exist there.
	std::cout << "Destructing Vertex: " << m_val << std::endl;
}

template<typename T>
inline T Vertex<T>::getVal() const {
	return m_val;
}

template<typename T>
inline std::vector<std::shared_ptr<Edge<T>>> Vertex<T>::getEdges() const {
	return m_edgePtrVector;
}

//THIS FUNCTION WILL BE DELETED:
template<typename T>
std::shared_ptr<Edge<T>> Vertex<T>::connectNode(std::shared_ptr<Vertex> node) {
	std::shared_ptr<Vertex> thisNode{ std::make_shared<Vertex>(*this) };
	//Edge<T> edge(thisNode, node); //an edge created between the two nodes
	std::shared_ptr<Edge<T>> edgePtr{ std::make_shared<Edge<T>>(node, thisNode) };
	this->addEdge(edgePtr); //adding the edge to this node
	node->addEdge(edgePtr); //adding the edge to the new adjacent node
	return edgePtr;
}

template<typename T>
void Vertex<T>::removeEdge(std::shared_ptr<Edge<T>> edge) {
	//loop does not end after one edge is found in cases there are multiples
	for (auto it{ m_edgePtrVector.begin() }; it != m_edgePtrVector.end(); it++) {
		if (*it == edge) {
			m_edgePtrVector.erase(it);
			break;
		}
	}
}

template<typename T>
void Vertex<T>::printEdges() {
	std::cout << m_val << "'s edges:" << std::endl;
	for (int i{ 0 }; i < m_edgePtrVector.size(); i++) {
		std::cout << '(' << m_edgePtrVector[i]->getA()->getVal() << ',' << m_edgePtrVector[i]->getB()->getVal() << ')' << std::endl;
	}
}

template<typename T>
inline void Vertex<T>::addEdge(std::shared_ptr<Edge<T>> edge) {
	m_edgePtrVector.push_back(edge);
}


#endif // !VERTEX