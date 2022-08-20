#include "Vertex.h"

Vertex::Vertex(int vertexName, list<GraphNode>* l) {
	this->vertexName = vertexName;
	this->l = l;
}

int Vertex::getVertexName() const {
	return this->vertexName;
};

void Vertex::addEdge(int v, int c) {
	if (this->checkIfEdgeExists(v)) {
		// throw error
	}
	else {
		(*this->l).push_back(GraphNode(v, c, 0));
	}
};

void Vertex::addFlow(int v, int f) {
	if (!this->checkIfEdgeExists(v)) {
		// throw error
	}
	else {
		this->findEdage(v)->setFlow(f);
	}
};

void Vertex::removeEdge(int v) {
	if (!this->checkIfEdgeExists(v)) {
		// throw error
	}
	else {
		(*this->l).erase(this->findEdage(v));
	}
}

bool operator==(const Vertex& a, const Vertex& b) {
	return a.vertexName == b.vertexName;
}

list<GraphNode> Vertex::getAdjFullList() const {
	list<GraphNode>::iterator it;
	list<GraphNode> tempList(*this->l);

	tempList.sort([](const GraphNode& a, const GraphNode& b) -> bool
			{
				return a < b;
			});

	return tempList;
}

list<int>& Vertex::getAdjList() const {
	list<int> resultList;
	list<GraphNode>::iterator it;

	list<GraphNode> tempList = this->getAdjFullList();

	for (it = tempList.begin(); it != tempList.end(); ++it) {
		resultList.push_back(it->getVertexName());
	}

	return resultList;
}

void Vertex::printAdjList() const {
	list<GraphNode>::iterator it;
	list<GraphNode> tempList(this->getAdjFullList());
	for (auto i = tempList.begin(); i != tempList.end(); ++i) {
		cout << *i;
	}
}

list<GraphNode>::iterator Vertex::findEdage(int v) {
	return find((*this->l).begin(), (*this->l).end(), v);
}

bool Vertex::checkIfEdgeExists(int v) {
	return (this->findEdage(v) != (*this->l).end());
};
