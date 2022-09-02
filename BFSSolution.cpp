#include "BFSSolution.h"

Graph BFSSolution::run(Graph g, int s, int t) {
	Graph residualGraph = g.getResidualGraph();
	vector<ShorterRouteNode> BFSResult = this->BFS(residualGraph, s);
	ShorterRouteNode cur;
	int minCapacity, curCapacity;
	while (getAncestorParent(BFSResult, t) == s) {
		cur = BFSResult[t];
		minCapacity = residualGraph.getVectorVertex()[BFSResult[cur.getVertexName()].getParent()].getCapacity(cur.getVertexName());
		while (cur.getVertexName() != s) {
			curCapacity = residualGraph.getVectorVertex()[BFSResult[cur.getVertexName()].getParent()].getCapacity(cur.getVertexName());
			cur = BFSResult[BFSResult[cur.getVertexName()].getParent()];
			if (minCapacity > curCapacity) {
				minCapacity = curCapacity;
			}
		}
		cur = BFSResult[t];
		int parent = cur.getParent();
		while (cur.getVertexName() != s) {
			g.AddFlow(parent, cur.getVertexName(), minCapacity);
			cur = BFSResult[parent];
			parent = cur.getParent();
		}

		residualGraph = g.getResidualGraph();
		BFSResult = this->BFS(residualGraph, s);
	}
	return g;
}

int BFSSolution::getAncestorParent(vector<ShorterRouteNode> BFSResult, int u){
	int cur = u;
	int parent = BFSResult[u].getParent();
	while (parent != -1) {
		cur = parent;
		parent = BFSResult[parent].getParent();
	}
	return cur;
}

vector<ShorterRouteNode> BFSSolution::BFS(Graph& g,int s) {
	list<GraphNode>::iterator it;
	queue<Vertex> BFSQueue;
	vector<ShorterRouteNode> vResult;
	vResult.reserve(g.getVSize());
	vector<Vertex> vertexList = g.getVectorVertex();

	for (auto it = begin(vertexList); it != end(vertexList); ++it) {
		vResult.push_back(ShorterRouteNode(it->getVertexName(), -1, INT_MAX));
	}

	BFSQueue.push(vertexList[s]);
	vResult[s].setLevel(0);


	while (!BFSQueue.empty()) {
		Vertex u = BFSQueue.front();
		BFSQueue.pop();
		list<GraphNode> tempList = u.getAdjFullList();


		for (const auto& v : tempList) {
			if (vResult[v.getVertexName()].getLevel() == INT_MAX) {
				vResult[v.getVertexName()].setLevel(vResult[u.getVertexName()].getLevel() + 1);
				vResult[v.getVertexName()].setParent(u.getVertexName());
				BFSQueue.push(vertexList[v.getVertexName()]);
			}
		}
	}

	return vResult;
}

void BFSSolution::sortBFSList(vector<ShorterRouteNode>& BFSList) {
	sort(BFSList.begin(), BFSList.end(),
		[](const ShorterRouteNode& a, const ShorterRouteNode& b) -> bool
		{
			return a.getLevel() < b.getLevel();
		});
}