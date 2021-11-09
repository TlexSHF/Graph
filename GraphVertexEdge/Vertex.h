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
	void connectNode(std::shared_ptr<Vertex> node);
	void removeEdge(std::shared_ptr<Edge<T>> edge);
private:
	T m_val;
	std::vector<std::shared_ptr<Edge<T>>> m_edgePtrVector;
	void addEdge(std::shared_ptr<Edge<T>> edge);
};

template<typename T>
Vertex<T>::Vertex(T val) :
	m_val{ val } {
}

template<typename T>
Vertex<T>::~Vertex() {
	//When a vertex gets deleted, the destructors in the edgePtrVector are called
	//They will delete themselves from their nodes if they exist there.
	std::cout << "Destructing Vertex" << std::endl;
}

template<typename T>
inline T Vertex<T>::getVal() const {
	return m_val;
}

template<typename T>
inline std::vector<std::shared_ptr<Edge<T>>> Vertex<T>::getEdges() const {
	return m_edgePtrVector;
}

template<typename T>
void Vertex<T>::connectNode(std::shared_ptr<Vertex> node) {
	std::shared_ptr<Vertex> thisNode{ this };
	Edge<T> edge(thisNode, node); //an edge created between the two nodes
	this->addEdge(std::make_shared<Edge<T>>(edge)); //adding the edge to this node
	node->addEdge(std::make_shared<Edge<T>>(edge)); //adding the edge to the new adjacent node
}

template<typename T>
void Vertex<T>::removeEdge(std::shared_ptr<Edge<T>> edge) {
	//loop does not end after one edge is found in cases there are multiples
	for (auto it{ m_edgePtrVector.begin() }; it < m_edgePtrVector.end(); it++) {
		if (*it == edge) {
			m_edgePtrVector.erase(it);
		}
	}
}

template<typename T>
inline void Vertex<T>::addEdge(std::shared_ptr<Edge<T>> edge) {
	m_edgePtrVector.push_back(edge);
}


#endif // !VERTEX