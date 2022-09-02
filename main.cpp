#include <iostream>
#include <iterator>
#include "Graph.h"
#include "Utils.h"
#include "BFSSolution.h"
#include "GreedySolution.h"

using namespace std;

int main() {
	int n, m, s, t;
	int i, j, c;

	cin >> n;
	cin >> m;
	cin >> s;
	cin >> t;

	if (s < 0 || t < 0 || n < 0 || m < 0) {
		cout << "invalid input" << endl;
		exit(1);
	}

	Graph g1 = Graph(n);
	Graph g2 = Graph(n);

	
	for (int k = 0; k < m; k++) {
		cin >> i >> j >> c;
		if (c < 0 || i > n || j > n) {
			cout << "invalid input" << endl;
			exit(1);
		}
		g1.AddEdge(i, j, c);
		g2.AddEdge(i, j, c);
	}

	cout << "BFS Method: " << endl;
	Graph bfsResult = BFSSolution().run(g1, s, t);
	cout << "Max flow = " << bfsResult.getFlow(s) << endl;
	cout << "Min Cut: ";
	Utils().printMinCut(bfsResult, s);


	cout << "Greedy Method: " << endl;
	Graph greedyResult = GreedySolution().run(g2, s, t);
	cout << "Max flow = " << greedyResult.getFlow(s) << endl;
	cout << "Min Cut: ";
	Utils().printMinCut(greedyResult, s);
}