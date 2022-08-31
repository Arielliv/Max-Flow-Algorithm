#include "Utils.h"


void Utils::printMinCut(Graph g, int s) const {
	Graph residualGraph = g.getResidualGraph();
	vector<BFSNode> BFSResult = BFSSolution().BFS(residualGraph, s);
	cout << "S = ";

	for (const auto& vertex : BFSResult) {
		if (vertex.getVertexName() != 0) {
			if (vertex.getVertexName() == s || vertex.getParent() != -1) {
				cout << vertex.getVertexName() << ", ";
			}
		}
	}
	
	cout << ". T = ";
	for (const auto& vertex : BFSResult) {
		if (vertex.getVertexName() != 0) {
			if (vertex.getVertexName() != s && vertex.getParent() == -1) {
				cout << vertex.getVertexName() << ",";
			}
		}
	}

	cout << endl;
}