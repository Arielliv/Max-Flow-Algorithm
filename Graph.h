#pragma once

#include <iostream>
#include <iterator>
#include <list>
#include <vector>
#include "Vertex.h"
#include "BFSSolution.h"
using namespace std;

class Graph
{
private:
	vector<Vertex> g;
	int lSize = 0;
	bool isVertexExists(int u) const;
public:
	Graph(int n);
	void MakeEmptyGraph(int n);
	list<int> GetAdjList(int u);
	list<GraphNode> getAdjFullList(int u);
	void AddEdge(int u, int v, int c);
	void RemoveEdge(int u, int v);
	void AddFlow(int u, int v, int f);
	int getCapacity(int u, int v);
	void printGraph() const;
	Graph getResidualGraph();
	Graph getNegativeResidualGraph();
	Graph getNegativeGraph();
	vector<Vertex> getVectorVertex() const;
	int getVSize() const;
	int getFlow(int s) const;
};

