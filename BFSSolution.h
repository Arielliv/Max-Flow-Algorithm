#pragma once
#include "Graph.h"
#include "BFSNode.h"
#include <vector>
#include <queue>

class BFSSolution
{
public:
	BFSSolution() {};
	Graph run(Graph g, int s, int t);
	vector<BFSNode> BFS(Graph& g,int s);
	int getAncestorParent(vector<BFSNode> BFSResult, int u);
	void sortBFSList(vector<BFSNode>& BFSList);
};


