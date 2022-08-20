#include <iostream>
#include <iterator>
#include "Graph.h"
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
	cout << "blablalba" << endl;
	//g.getResidualGraph().printGraph();
	BFSSolution().run(g, s, t).printGraph();
}