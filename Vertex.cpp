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
		/*string error = "eadge aleady exist: " + std::to_string(this->getVertexName()) + " and vertex : " + std::to_string(v) + " tried to add new Edge with capacity: " + std::to_string(c) + "when there was already capacity of: " + std::to_string(this->getCapacity(v));
		throw std::logic_error(error);*/
		list<GraphNode>::iterator it = this->findEdge(v);
		it->setCapacity(it->getCapacity() + c);
	}
	else {
		(*this->l).push_back(GraphNode(v, c, 0));
	}
};

void Vertex::addFlow(int v, int f) {
	if (!this->checkIfEdgeExists(v)) {
		list<GraphNode>::iterator it = this->findEdge(v);
		it->setFlow(it->getCapacity() + f);
		//throw std::logic_error("eadge and flow aleady exists");
	}
	else {
		this->findEdge(v)->setFlow(f);
	}
};

void Vertex::removeEdge(int v) {
	if (!this->checkIfEdgeExists(v)) {
		throw std::logic_error("eadge doesn't exist");
	}
	else {
		(*this->l).erase(this->findEdge(v));
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

list<int> Vertex::getAdjList() const {
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

list<GraphNode>::iterator Vertex::findEdge(int v) const{
	return find((*this->l).begin(), (*this->l).end(), v);
}

bool Vertex::checkIfEdgeExists(int v) const {
	return (this->findEdge(v) != (*this->l).end());
};

int Vertex::getCapacity(int v) const {
	if (!this->checkIfEdgeExists(v)) {
		string error = "getCapacity error: " + std::to_string(this->getVertexName()) + " and vertex : " + std::to_string(v) + " tried to getCapacity: ";
		throw std::logic_error(error);
	}
	return this->findEdge(v)->getCapacity();
}

int Vertex::getFlow(int v) const {
	return this->findEdge(v)->getFlow();
}

Vertex& Vertex::operator=(const Vertex& a) {
	list<GraphNode>::iterator it;
	this->vertexName = a.vertexName;
	for (const auto& v : (*a.l)) {
		(*this->l).push_back(v);
	}
	return *this;
}