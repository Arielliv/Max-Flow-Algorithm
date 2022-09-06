#include "GreedySolution.h"

Graph GreedySolution::run(Graph g, int s, int t) {
	Graph residualGraph = g.getResidualGraph();
	vector<ShorterRouteNode> GreedyDijkstraResult = this->GreedyDijkstra(residualGraph, s);
	ShorterRouteNode cur;
	int minCapacity, curCapacity;
	while (getAncestorParent(GreedyDijkstraResult, t) == s) {
		minCapacity = getMinCapacityInRoute(residualGraph,GreedyDijkstraResult, t);
		cur = GreedyDijkstraResult[t];
		int parent = cur.getParent();
		while (cur.getVertexName() != s) {
			g.AddFlow(parent, cur.getVertexName(), minCapacity);
			cur = GreedyDijkstraResult[parent];
			parent = cur.getParent();
		}

		residualGraph = g.getResidualGraph();
		GreedyDijkstraResult = this->GreedyDijkstra(residualGraph, s);
	}
	return g;
}

vector<ShorterRouteNode> GreedySolution::GreedyDijkstra(Graph& g, int s) {
	priority_queue<ShorterRouteNode> GreedyQueue;
	vector<ShorterRouteNode> vResult; // d.
	vector<bool> visited; // p.

	for (int i = 0; i <= g.getVSize(); i++) {
		vResult.push_back(ShorterRouteNode(i, -1, INT_MIN));
		visited.push_back(false);
	}
	
	vResult[s].setLevel(INT_MAX);
	for (int i = 1; i < g.getVSize()+1; i++) {
		GreedyQueue.push(vResult[i]);
	}

	while (!GreedyQueue.empty()) {
		ShorterRouteNode u = GreedyQueue.top();
		GreedyQueue.pop();
		list<GraphNode> adjFullList = g.getAdjFullList(u.getVertexName());
		//if (!visited[u.getVertexName()]) {
			visited[u.getVertexName()] = true;
			for (const auto& v : adjFullList) {
				int min = std::min(vResult[u.getVertexName()].getLevel(), g.getCapacity(u.getVertexName(), v.getVertexName()));
				if (vResult[v.getVertexName()].getLevel() < min) {
					vResult[v.getVertexName()].setLevel(min);
					vResult[v.getVertexName()].setParent(u.getVertexName());
					GreedyQueue.push(ShorterRouteNode(v.getVertexName(), vResult[v.getVertexName()].getParent(), vResult[v.getVertexName()].getLevel()));
				}
			}
		//}

	}

	return vResult;
}

int GreedySolution::getAncestorParent(vector<ShorterRouteNode> GreedyResult, int u) {
	int cur = u;
	int parent = GreedyResult[u].getParent();
	while (parent != -1) {
		cur = parent;
		parent = GreedyResult[parent].getParent();
	}
	return cur;
}

int GreedySolution::getMinCapacityInRoute(Graph& g,vector<ShorterRouteNode> GreedyResult, int u) {
	int parent = GreedyResult[u].getParent();
	int min = g.getCapacity(parent, u);
	int cur = u;
	int curCapacity = min;
	while (parent != -1) {
		curCapacity = g.getCapacity(GreedyResult[cur].getParent(), cur);
		if (curCapacity < min) {
			min = curCapacity;
		}
		cur = parent;
		parent = GreedyResult[parent].getParent();
	}
	return min;
}