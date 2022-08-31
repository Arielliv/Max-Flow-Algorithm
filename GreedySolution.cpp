//#include "GreedySolution.h"
//
//Graph GreedySolution::run(Graph g, int s, int t) {
//	Graph residualGraph = g.getResidualGraph();
//	vector<BFSNode> BFSResult = this->BFS(residualGraph, s);
//	BFSNode cur;
//	int minCapacity, curCapacity;
//	while (getAncestorParent(BFSResult, t) == s) {
//		cur = BFSResult[t];
//		minCapacity = residualGraph.getVectorVertex()[BFSResult[cur.getVertexName()].getParent()].getCapacity(cur.getVertexName());
//		while (cur.getVertexName() != s) {
//			curCapacity = residualGraph.getVectorVertex()[BFSResult[cur.getVertexName()].getParent()].getCapacity(cur.getVertexName());
//			cur = BFSResult[BFSResult[cur.getVertexName()].getParent()];
//			if (minCapacity > curCapacity) {
//				minCapacity = curCapacity;
//			}
//		}
//		cur = BFSResult[t];
//		int parent = cur.getParent();
//		while (cur.getVertexName() != s) {
//			g.AddFlow(parent, cur.getVertexName(), minCapacity);
//			cur = BFSResult[parent];
//			parent = cur.getParent();
//		}
//
//		residualGraph = g.getResidualGraph();
//		BFSResult = this->BFS(residualGraph, s);
//	}
//	return g;
//}
