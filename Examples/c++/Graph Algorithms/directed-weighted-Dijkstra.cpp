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

	list<Edge> dijkstra(int start) const {
		if (nodes.size() < 1) {
			return list<Edge>();
		}
		
		// parent[i] will hold the index of the parent node
		vector<int> parent(nodes.size(), -1);
		// distance[i] will hold the total distance to the i-th node
		vector<int> distance(nodes.size(), INT_MAX);
		// visited[i] will be a marker if we've been to this node before
		vector<bool> visited(nodes.size(), false);

		distance[start] = 0;
		// Holds the next node to process with the distance required to reach it
		priority_queue<Pair> nextToProcess;
		nextToProcess.push({start, 0});
		while (!nextToProcess.empty()) {
			Pair currentPair = nextToProcess.top();
			nextToProcess.pop();
			int currentNode = currentPair.index;

			// If we've been in this node before skip it
			if (visited[currentNode]) {
				continue;
			}
			visited[currentNode] = true;

			// For each neighbour check if we have a better potential route from the current node 
			for (auto neighbour : nodes[currentNode].neighbours) {
				int neighbourNode = neighbour.index;
				int alternativeDistance = distance[currentNode] + neighbour.distance;
				if (alternativeDistance < distance[neighbourNode]) {
					distance[neighbourNode] = alternativeDistance;
					parent[neighbourNode] = currentNode;
					nextToProcess.push({neighbourNode, alternativeDistance});
				}
			}
		}

		// cout << "Distances: \n";
		// for (auto i : distance) {
		// 	cout << i << " ";
		// }
		// cout << "\n";

		// cout << "Parents: \n";
		// for (auto i : parent) {
		// 	cout << i << " ";
		// }
		// cout << "\n";

		// Construct tree from the edges participating in the Dijkstra traversal
		list<Edge> tree;
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

	list<Edge> tree = g.dijkstra(0);
	cout << "Dijkstra tree:\n";
	for (Edge edge : tree) {
		cout << edge.from << "-" << edge.to << "(" << edge.weight << ")\n";
	}
}
