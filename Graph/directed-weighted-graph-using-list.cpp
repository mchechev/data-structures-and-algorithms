#include <iostream>
#include <vector>
#include <list>
using namespace std;

struct Pair {
	int index;
	int weight;
};

struct Node {
	list<Pair> neighbours;

	bool hasNeighbour(int index) {
		for (auto neighbour : neighbours) {
			if (neighbour.index == index) {
				return true;
			}
		}
		return false;
	}

	void addNeighbour(int index, int weight) {
		neighbours.push_back(Pair{ index, weight });
	}
};

class Graph {
private:
	vector<Node> nodes;

public:
	Graph(int nodeCount = 0) {
		nodes.resize(nodeCount);
	}

	void print() const {
		for (int node = 0; node < nodes.size(); node++) {
			cout << node << ": ";
			for (auto neighbour : nodes[node].neighbours) {
				cout << neighbour.index << "(" << neighbour.weight << "), ";
			}
			cout << "\n";
		}
	}

	void connect(int from, int to, int weight) {
		if (!nodes[from].hasNeighbour(to)) { // remove this check to make it multigraph
			nodes[from].addNeighbour(to, weight);
		}
	}
};

int main() {
	Graph g(4);
	g.connect(0, 1, 5);
	g.connect(1, 0, 3);
	g.connect(1, 2, 2);
	g.connect(1, 3, 10);
	g.connect(2, 1, 21);
	g.connect(3, 1, 9);
	g.connect(3, 2, 1);

	g.print();
}
