#pragma once
#include "GraphNode.h"
#include <list>
#include <algorithm>
using namespace std;

class Vertex
{
private:
	int vertexName;
	list<GraphNode>* l;
	bool checkIfEdgeExists(int v);
public:
	Vertex() : vertexName(-1), l(new list<GraphNode>{}) {};
	Vertex(int vertexName, list<GraphNode>* l);
	list<GraphNode>::iterator findEdage(int v);
	list<int>& getAdjList() const;
	list<GraphNode> getAdjFullList() const;
	void removeEdge(int v);
	void addEdge(int v, int c);
	void addFlow(int v, int f);
	void printAdjList() const;
	int getVertexName() const;
	friend bool operator==(const Vertex& a, const Vertex& b);
};

