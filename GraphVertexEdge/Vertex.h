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
	void addEdge(std::shared_ptr<Edge<T>> edge);
	void removeEdge(std::shared_ptr<Edge<T>> edge);
	void printEdges();
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

template<typename T>
inline void Vertex<T>::addEdge(std::shared_ptr<Edge<T>> edge) {
	m_edgePtrVector.push_back(edge);
}

template<typename T>
void Vertex<T>::removeEdge(std::shared_ptr<Edge<T>> edge) {
	for (auto it{ m_edgePtrVector.begin() }; it != m_edgePtrVector.end(); it++) {
		if (*it == edge) {
			m_edgePtrVector.erase(it);
			break;
		}
	}
}

template<typename T>
void Vertex<T>::printEdges() {
	std::cout << "Node " << m_val << "'s edges:" << std::endl;
	for (int i{ 0 }; i < m_edgePtrVector.size(); i++) {
		std::cout << '(' << m_edgePtrVector[i]->getA()->getVal() << ',' << m_edgePtrVector[i]->getB()->getVal() << ')' << std::endl;
	}
}


#endif // !VERTEX