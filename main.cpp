#include <iostream>
#include <iterator>
#include "Graph.h"
#include "Utils.h"
#include "BFSSolution.h"

using namespace std;

int main() {
	int n, m, s, t;
	int i, j, c;

	cin >> n;
	cin >> m;
	cin >> s;
	cin >> t;

	Graph g = Graph(n);

	for (int k = 0; k < m; k++) {
		cin >> i >> j >> c;
		g.AddEdge(i, j, c);
	}

	//g.printGraph();
	
	//g.getResidualGraph().printGraph();
	cout << "BFS Method: " << endl;
	Graph bfsResult = BFSSolution().run(g, s, t);
	cout << "Max flow = " << bfsResult.getFlow(s) << endl;
	cout << "Min Cut: ";
	Utils().printMinCut(bfsResult, s);

}