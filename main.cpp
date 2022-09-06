#include <iostream>
#include <iterator>
#include "Graph.h"
#include "Utils.h"
#include "BFSSolution.h"
#include "GreedySolution.h"

using namespace std;

int main() {
	try {
		int n, m, s, t;
		int i, j, c;

		cin >> n;
		cin >> m;
		cin >> s;
		cin >> t;

		if (s < 0 || t < 0 || n < 0 || m < 0) {
			throw std::invalid_argument("invalid input");
		}

		Graph g1 = Graph(n);
		Graph g2 = Graph(n);


		for (int k = 0; k < m; k++) {
			cin >> i >> j >> c;
			if (c < 0 || i > n || j > n) {
				throw std::invalid_argument("invalid input");
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
	catch (const std::invalid_argument& e) {
		cout << "invalid input" << endl;
		exit(1);
	}
	catch (const std::logic_error& e) {
		cout << e.what() << endl;
		exit(1);
	}
}