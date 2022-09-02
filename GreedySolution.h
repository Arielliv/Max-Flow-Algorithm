#include "Graph.h"
#include "ShorterRouteNode.h"
#include <queue>
using namespace std;

#pragma once

class GreedySolution
{
public:
	GreedySolution() {};
	Graph run(Graph g, int s, int t);
	int getAncestorParent(vector<ShorterRouteNode> GreedyResult, int u);
	vector<ShorterRouteNode> GreedyDijkstra(Graph& g, int s);
	int getMinCapacityInRoute(Graph& g, vector<ShorterRouteNode> GreedyResult, int u);
};

