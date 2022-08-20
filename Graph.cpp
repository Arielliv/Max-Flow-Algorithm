#include "Graph.h"

Graph::Graph(int n) {
	this->MakeEmptyGraph(n);
}

void Graph::MakeEmptyGraph(int n) {
	this->g.reserve(n);
	for (int i = 0; i < n; i++) {
		this->g.push_back(Vertex(i + 1, new list<GraphNode>{}));
	}
	this->lSize = n;
};

list<int> Graph::GetAdjList(int u) {
	return this->g[u - 1].getAdjList();
};

void Graph::AddEdge(int u, int v, int c) {
	this->g[u - 1].addEdge(v,c);
	//this->g[v - 1].addEdge(u, 0);
};

void Graph::AddFlow(int u, int v, int f) {
	this->g[u - 1].addFlow(v, f);
	//this->g[v - 1].addFlow(u, -f);
}

void Graph::RemoveEdge(int u, int v) {
	this->g[u - 1].removeEdge(v);
};

void Graph::printGraph() const{
	for (auto it = begin(this->g); it != end(this->g); ++it) {
		cout << "Vertex Name : " << it->getVertexName() << " { " << endl;
		it->printAdjList();
		cout <<  " } " << endl;
	}
}

Graph Graph::getResidualGraph() {
	Graph result = Graph(this->lSize);

	for (int i = 0; i < this->lSize; i++) {
		list<GraphNode> tempList = this->g[i].getAdjFullList();
		for (auto y = tempList.begin(); y != tempList.end(); ++y) {
			int f = y->getFlow();
			int cf = y->getCapacity() - f;
			if (cf > 0) {
				result.g[i].addEdge(y->getVertexName(), y->getCapacity() - y->getFlow());
			}
			if (f > 0) {
				result.g[y->getVertexName() - 1].addEdge(i, y->getFlow());
			}
		}

	}
	return result;
}