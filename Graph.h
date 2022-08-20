#pragma once

#include <iostream>
#include <iterator>
#include <list>
#include <vector>
#include "Vertex.h"

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
	void AddEdge(int u, int v, int c);
	void RemoveEdge(int u, int v);
	void AddFlow(int u, int v, int f);
	void printGraph() const;
	Graph getResidualGraph();
};
