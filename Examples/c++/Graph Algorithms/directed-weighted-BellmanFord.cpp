#include <iostream>
#include <vector>
#include <list>
#include <climits>
#include <queue>
using namespace std;

struct Pair {
	int index;
	int distance;

	bool operator<(const Pair & rhs) const {
		return distance > rhs.distance;
	}
};

struct Edge {
	int from;
	int to;
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
		}
	}

	vector<Edge> getAllEdges() const {
		vector<Edge> edges;

		for (int from = 0; from < nodes.size(); from++) {
			for (auto neighbour : nodes[from].neighbours) {
				int to = neighbour.index;
				int distance = neighbour.distance;
				edges.push_back(Edge{ from, to, distance });
			}
		}

		return edges;
	}

	list<Edge> bellmanFord(int start) const {
		vector<Edge> allEdges = getAllEdges();
		list<Edge> tree;

		vector<int> distance(nodes.size(), INT_MAX);
		vector<int> parent(nodes.size(), -1);

		distance[start] = 0;
		for (int i = 0; i < nodes.size() - 1; i++) {
			for (auto edge : allEdges) {
				int alternativeDistance = distance[edge.from] + edge.distance;
				if (alternativeDistance < distance[edge.to]) {
					distance[edge.to] = alternativeDistance;
					parent[edge.to] = edge.from;
				}
			}
		}

		// Check for negative cycles (do 1 more relaxation round)
		for (auto edge : allEdges) {
			int alternativeDistance = distance[edge.from] + edge.distance;
			if (alternativeDistance < distance[edge.to]) {
				cout << "Negative cycle found\n";
				break;
			}
		}

		for (int i = 0; i < parent.size() ; i++) {
			if (parent[i] != -1) {
				int directDistance = distance[i] - distance[parent[i]];
				tree.push_back({parent[i], i, directDistance});
			}
		}

		return tree;
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
	g.connect(0, 3, 2);

	list<Edge> tree = g.bellmanFord(0);
	cout << "Bellman-Ford tree:\n";
	for (Edge edge : tree) {
		cout << edge.from << "-" << edge.to << "(" << edge.distance << ")\n";
	}
}
