#pragma once
#ifndef EDGE
#define EDGE

#include <memory>
#include <iostream>
#include "Vertex.h"
template <typename T>
class Vertex;

template <typename T>
class Edge {
public:
	Edge(std::shared_ptr<Vertex<T>> nodeA, std::shared_ptr<Vertex<T>> nodeB);
	~Edge();
	std::shared_ptr<Vertex<T>> getA() const;
	std::shared_ptr<Vertex<T>> getB() const;
private:
	std::shared_ptr<Vertex<T>> m_nodeA;
	std::shared_ptr<Vertex<T>> m_nodeB;
};

template<typename T>
Edge<T>::Edge(std::shared_ptr<Vertex<T>> nodeA, std::shared_ptr<Vertex<T>> nodeB) :
	m_nodeA{ nodeA }, m_nodeB{ nodeB } {
	std::cout << "Constructing edge" << std::endl;
}

template<typename T>
Edge<T>::~Edge() {
	std::cout << "Destructing edge" << std::endl;
	//Removing the link to this edge from its connected nodes
	std::shared_ptr<Edge> thisEdge{ this };
	m_nodeA->removeEdge(thisEdge);
	m_nodeB->removeEdge(thisEdge);
}

template<typename T>
inline std::shared_ptr<Vertex<T>> Edge<T>::getA() const {
	return m_nodeA;
}

template<typename T>
inline std::shared_ptr<Vertex<T>> Edge<T>::getB() const {
	return m_nodeB;
}



#endif // !EDGE