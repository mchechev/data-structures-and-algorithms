#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
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

struct Edge {
	int from;
	int to;
	int weight;

	bool operator<(const Edge& rhs) const {
		return weight < rhs.weight;
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
			nodes[to].addNeighbour(from, weight);
		}
	}

	vector<Edge> getAllEdges() const {
		vector<Edge> edges;

		for (int from = 0; from < nodes.size(); from++) {
			for (auto neighbour : nodes[from].neighbours) {
				int to = neighbour.index;
				int weight = neighbour.weight;
				if (from < to) {
					edges.push_back(Edge{ from, to, weight });
				}
			}
		}

		return edges;
	}

	list<Edge> kruskal() const {
		if (nodes.size() < 1) {
			return list<Edge>();
		}
		
		vector<Edge> allEdges = getAllEdges();
		sort(allEdges.begin(), allEdges.end());

		list<Edge> tree;
		vector<int> components;
		components.resize(nodes.size());

		for (int i = 0; i < nodes.size() + 1; i++) {
			components[i] = i;
		}

		for (Edge edge : allEdges) {
			if (components[edge.from] != components[edge.to]) {
				tree.push_back(edge);
				int oldComponent = components[edge.from];
				int newComponent = components[edge.to];
				for (int i = 0; i < components.size(); i++) {
					if (components[i] == oldComponent)
						components[i] = newComponent;
				}
			}
		}

		return tree;
	}
};

int main() {
	Graph g(4);
	g.connect(0, 1, 5);
	g.connect(1, 2, 2);
	g.connect(1, 3, 8);
	g.connect(2, 0, 4);
	g.connect(2, 3, 3);
	g.connect(3, 0, 10);

	list<Edge> spanningTree = g.kruskal();
	for (Edge edge : spanningTree) {
		cout << edge.from << "-" << edge.to << "(" << edge.weight << ")\n";
	}
}
