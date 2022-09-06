#include "Graph.h"

Graph::Graph(int n) {
	this->MakeEmptyGraph(n);
}

void Graph::MakeEmptyGraph(int n) {
	this->g.reserve(n+1);
	for (int i = 0; i < n+1; i++) {
		this->g.push_back(Vertex(i, new list<GraphNode>{}));
	}
	this->lSize = n;
};

list<int> Graph::GetAdjList(int u) {
	return this->g[u].getAdjList();
};

list<GraphNode> Graph::getAdjFullList(int u) {
	return this->g[u].getAdjFullList();
};

void Graph::AddEdge(int u, int v, int c) {
	this->g[u].addEdge(v,c);
};

void Graph::AddFlow(int u, int v, int f) {
	if (!this->g[u].checkIfEdgeExists(v)) {
		this->g[u].addEdge(v, f);
		
	}
	else if (this->g[u].getCapacity(v) < f) {
		string error = "error in add flow of vertex: " + std::to_string(u) + " and vertex : " + std::to_string(v) + " tried to add flow of: " + std::to_string(f) + " to capacity : " + std::to_string(this->g[u].getCapacity(v));
		throw std::logic_error(error);
	}
	else {
		this->g[u].addFlow(v, f);
	}
	
}

void Graph::RemoveEdge(int u, int v) {
	this->g[u].removeEdge(v);
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

	for (int u = 1; u <= this->lSize; u++) {
		list<GraphNode> tempList = this->g[u].getAdjFullList();
		for (auto v = tempList.begin(); v != tempList.end(); ++v) {
			
			int f = v->getFlow();
			int cf = v->getCapacity() - f;
			if (cf > 0) {
				result.g[u].addEdge(v->getVertexName(), v->getCapacity() - v->getFlow());
			}
			if (f > 0) {
				result.g[v->getVertexName()].addEdge(u, v->getFlow());
			}
		}

	}
	return result;
}

int Graph::getVSize() const {
	return this->lSize;
}

vector<Vertex> Graph::getVectorVertex() const {
	return this->g;
}

int Graph::getCapacity(int u, int v) {
	return this->g[u].getCapacity(v);
}

int Graph::getFlow(int s) const {
	int count = 0;
	list<GraphNode> tempList = this->g[s].getAdjFullList();
	for (auto it = tempList.begin(); it != tempList.end(); ++it) {
		count += (*it).getFlow();
	}

	return count;
}