#pragma once
class BFSNode {
private:
	int vertexName;
	int parent;
	int level;
public:
	BFSNode() {};
	BFSNode(int vertexName, int parent, int level) :vertexName(vertexName), parent(parent), level(level) {};
	int getVertexName() const {
		return this->vertexName;
	}
	int getParent() const {
		return this->parent;
	}
	int getLevel() const {
		return this->level;
	}

	void setVertexName(int vertexName) {
		this->vertexName = vertexName;
	}
	void setParent(int parent) {
		this->parent = parent;
	}
	void setLevel(int level) {
		this->level = level;
	}
};


