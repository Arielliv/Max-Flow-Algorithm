#pragma once
#include "Graph.h"
#include "ShorterRouteNode.h"
#include <vector>
#include <queue>
class Graph;
class BFSSolution
{
public:
	BFSSolution() {};
	Graph run(Graph g, int s, int t);
	vector<ShorterRouteNode> BFS(Graph& g,int s);
	int getAncestorParent(vector<ShorterRouteNode> BFSResult, int u);
	void sortBFSList(vector<ShorterRouteNode>& BFSList);
};


