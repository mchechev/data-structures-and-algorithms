#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

struct Pair {
	int index;
	int distance;
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

	void addNeighbour(int index, int distance) {
		neighbours.push_back(Pair{ index, distance });
	}
};

struct Edge {
	int from;
	int to;
	int distance;

	bool operator<(const Edge& rhs) const {
		return distance > rhs.distance;
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
				cout << neighbour.index << "(" << neighbour.distance << "), ";
			}
			cout << "\n";
		}
	}

	void connect(int from, int to, int distance) {
		if (!nodes[from].hasNeighbour(to)) { // remove this check to make it multigraph
			nodes[from].addNeighbour(to, distance);
			nodes[to].addNeighbour(from, distance);
		}
	}

	vector<Edge> getAllEdges() const {
		vector<Edge> edges;

		for (int from = 0; from < nodes.size(); from++) {
			for (auto neighbour : nodes[from].neighbours) {
				int to = neighbour.index;
				int distance = neighbour.distance;
				if (from < to) {
					edges.push_back(Edge{ from, to, distance });
				}
			}
		}

		return edges;
	}

	list<Edge> prim() const {
		if (nodes.size() < 1) {
			return list<Edge>();
		}

		// distance[i] will hold the total distance to the i-th node
		vector<int> distance(nodes.size(), INT_MAX);
		// added[i] will be a marker if we've added the node to the tree
		vector<bool> added(nodes.size(), false);

		list<Edge> tree;
		distance[0] = 0;
		priority_queue<Edge> nextToProcess;
		nextToProcess.push({-1, 0, 0}); // start from the 0th node with no parent
		
		while (!nextToProcess.empty()) {
			Edge nextBest = nextToProcess.top();
			nextToProcess.pop();
			int currentNode = nextBest.to;

			if (added[currentNode]) {
				continue;
			}
			added[currentNode] = true;

			int parent = nextBest.from;
			int minDistance = nextBest.distance;

			if (parent != -1) { // It's not the 0th node
				tree.push_back({parent, currentNode, minDistance});
			}

			for (auto neighbour : nodes[currentNode].neighbours) {
				nextToProcess.push({currentNode, neighbour.index, neighbour.distance});
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

	list<Edge> spanningTree = g.prim();
	for (Edge edge : spanningTree) {
		cout << edge.from << "-" << edge.to << "(" << edge.distance << ")\n";
	}
}
