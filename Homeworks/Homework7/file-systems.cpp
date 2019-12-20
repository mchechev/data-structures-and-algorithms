#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

struct Node {
	string name;
	vector<Node*> sub;
	Node* parent = nullptr;

	Node(const string& name, Node* parent = nullptr) : name(name), parent(parent) { }

	bool hasSub(string dir) {
		for (Node* i : sub) {
			if (i->name == dir) {
				return true;
			}
		}
		return false;
	}

	void mkdir(const string& dir) {
		if (hasSub(dir)) {
			cout << "Directory already exists\n";
		} else {
			sub.push_back(new Node(dir, this));
		}
	}

	void ls() {
		sort(sub.begin(), sub.end(), [](const auto& lhs, const auto& rhs) {
			return lhs->name < rhs->name; });

		for (auto i : sub) {
			cout << i->name << " ";
		}
		
		cout << "\n";
	}

	Node* cd(const string& dir) {
		if (dir == "..") {
			if (parent) {
				return parent;
			}
		} else {
			for (Node* i : sub) {
				if (i->name == dir) {
					return i;
				}
			}
		}

		cout << "No such directory\n";
		return this;
	}

	void pwd() const {
		stack<string> dirs;
		const Node* current = this;
		while (current != nullptr) {
			dirs.push(current->name);
			current = current->parent;
		}

		while (!dirs.empty()) {
			cout << dirs.top() << "/";
			dirs.pop();
		}
		cout << "\n";
	}
};

int main() {
	int N;
	string in;

	Node* current = new Node("");

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> in;
		if (in == "mkdir") {
			cin >> in;
			current->mkdir(in);
		} else if (in == "ls") {
			current->ls();
		} else if (in == "cd") {
			cin >> in;
			current = current->cd(in);
		} else if (in == "pwd") {
			current->pwd();
		}
	}
}