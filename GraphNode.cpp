#include "GraphNode.h"

 bool operator<(const GraphNode& a, const GraphNode& b) {
	return a.capacity < b.capacity;
};
 bool operator>(const GraphNode& a, const GraphNode& b) {
	return a.capacity > b.capacity;
};

 bool operator==(const GraphNode& a, const int& i) {
	 return a.vertexName == i;
 };
 bool operator==(const GraphNode& a, const GraphNode& b) {
	 return a.vertexName == b.vertexName;
 };
 bool operator<=(const GraphNode& a, const GraphNode& b) {
	return a.capacity <= b.capacity;
};
 bool operator>=(const GraphNode& a, const GraphNode& b) {
	return a.capacity >= b.capacity;
};

 ostream& operator<<(std::ostream& os, const GraphNode& p) {
	 os << "Vertex Name : " << p.getVertexName() << " Capacity : " << p.getCapacity() << " Flow : " << p.getFlow() << endl;
	 return os;
 }
