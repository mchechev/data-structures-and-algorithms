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

struct Edge {
	int from;
	int to;
};

class Graph {
private:
	vector<Node> nodes;

	void _topologicalSort(list<int>& sorted, vector<char>& visited, int start) const {
		visited[start] = 'o';
		for (auto neighbour : nodes[start].neighbours) {
			if (visited[neighbour] == 'u') {
				_topologicalSort(sorted, visited, neighbour);
			} else if (visited[neighbour] == 'o') {
				cout << "Found cycle going through nodes " << start << " and " << neighbour << "\n";
			}
		}
		visited[start] = 'c';
		sorted.push_front(start);
	}

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
		}
	}

	list<int> topologicalSort() const {
		list<int> sorted;
		// 'o' for open, 'c' for closed, 'u' for unvisited
		// open = the node is in the stack of DFS
		// closed = the node is not in the stack of DFS
		// unvisited = we have never gone to that node
		vector<char> visited(nodes.size(), 'u');

		for (int i = 0; i < nodes.size(); i++) {
			if (visited[i] == 'u') {
				_topologicalSort(sorted, visited, i);
			}
		}

		return sorted;
	}
};

int main() {
	Graph g(5);
	g.connect(4, 3);
	g.connect(4, 2);
	g.connect(1, 3);
	g.connect(2, 0);
	// g.connect(0, 4); // Adds a cycle

	list<int> sorted = g.topologicalSort();
	for (auto i : sorted) {
		cout << i << " ";
	}
	cout << "\n";
}