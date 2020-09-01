#include <iostream>
#include <vector>
#include <list>
using namespace std;

struct Node {
	list<int> neighbours;

	bool hasNeighbour(int index) {
		for (auto i : neighbours) {
			if (i == index) {
				return true;
			}
		}
		return false;
	}

	void addNeighbour(int index) {
		neighbours.push_back(index);
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
				cout << neighbour << ", ";
			}
			cout << "\n";
		}
	}

	void connect(int from, int to) {
		if (!nodes[from].hasNeighbour(to)) { // remove this check to make it multigraph
			nodes[from].addNeighbour(to);
			nodes[to].addNeighbour(from);
		}
	}
};

int main() {
	Graph g(4);
	g.connect(0, 1);
	g.connect(1, 0);
	g.connect(1, 2);
	g.connect(1, 3);
	g.connect(2, 1);
	g.connect(3, 1);
	g.connect(3, 2);

	g.print();
}