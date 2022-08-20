#pragma once
#include <iostream>
using namespace std;
class GraphNode
{
private:
	int vertexName;
	int capacity;
	int flow;
public:
	GraphNode(int vertexName, int capacity, int flow) {
		this->vertexName = vertexName;
		this->capacity = capacity;
		this->flow = flow;
	}

	const int getVertexName() const {
		return this->vertexName;
	}

	const int getCapacity() const {
		return this->capacity;
	}

	const int getFlow() const {
		return this->flow;
	}

    void setVertexName(int vertexName)  {
		this->vertexName = vertexName;
	}

	void setCapacity(int capacity)  {
		this->capacity = capacity;
	}

	void setFlow(int flow)  {
		this->flow += flow;
	}

	friend bool operator<(const GraphNode& a, const GraphNode& b);
	friend bool operator>(const GraphNode& a, const GraphNode& b);
	friend bool operator==(const GraphNode& a, const int& i);
	friend bool operator==(const GraphNode& a, const GraphNode& b);
	friend bool operator<=(const GraphNode& a, const GraphNode& b);
	friend bool operator>=(const GraphNode& a, const GraphNode& b);
	friend ostream& operator<<(std::ostream& os, const GraphNode& p);
};

