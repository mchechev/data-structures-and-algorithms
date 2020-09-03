#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <unordered_map>
using namespace std;

class DisjointSet {
private:
	unordered_map<int, int> parent;
	// currentLastTree starts from 0 because our nodes start from 0
	int currentLastTree = 0;
public:
	void add(int child) {
		parent[child] = currentLastTree;
		currentLastTree++;
	}

	int find(int child) { // Returns root of the tree the node belongs to
		if (parent[child] == child) {
			return child;
		}
		// Make the parent of each node be the root of the tree to reduce height
		int root = find(parent[child]);
		parent[child] = root;
		return root;
	}

	void unite(int a, int b) { // Combines two trees by making the root of one be the root for the other as well
		int aRoot = find(a);
		int bRoot = find(b);
		parent[aRoot] = bRoot;
	}

	void initialize(int nodeCount) {
		for (int i = 0; i < nodeCount; i++) {
			add(i);
		}
	}
};

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
		vector<Edge> allEdges = getAllEdges();
		sort(allEdges.begin(), allEdges.end());

		list<Edge> tree;

		DisjointSet components;
		components.initialize(nodes.size());

		for (Edge edge : allEdges) {
			if (components.find(edge.from) != components.find(edge.to)) {
				tree.push_back(edge);
				components.unite(edge.from, edge.to);
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
