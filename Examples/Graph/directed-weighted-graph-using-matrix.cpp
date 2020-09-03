#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
	vector<vector<int>> adjacencyMatrix;

public:
	Graph(int nodeCount) {
		adjacencyMatrix.resize(nodeCount);
		for (int row = 0; row < adjacencyMatrix.size(); row++) {
			adjacencyMatrix[row].resize(nodeCount);
			for (int col = 0; col < adjacencyMatrix.size(); col++) {
				adjacencyMatrix[row][col] = 0; // 0 means there is no connection
			}
		}
	}

	void print() const {
		for (auto neighbours : adjacencyMatrix) {
			for (auto neighbour : neighbours) {
				cout << neighbour << " ";
			}
			cout << "\n";
		}
	}

	void connect(int from, int to, int weight = 1) {
		// The outer vector contains the node where we start
		// The inner vector contains the weight to each neighbour
		adjacencyMatrix[from][to] = weight;

		// If the graph wasn't directed we would need to uncomment the row below
		// adjacencyMatrix[to][from] = weight;
	}
};

int main() {
	Graph g(4);
	// By not specifying weight of each edge the graph becomes unweighted
	g.connect(0, 1);
	g.connect(1, 0);
	g.connect(1, 2);
	g.connect(1, 3);
	g.connect(2, 1);
	g.connect(3, 1);
	g.connect(3, 2);

	g.print();
}