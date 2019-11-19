#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    Node *left;
    Node *right;
    int value;
    Node(int value) {
        this->value = value;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST {

public:
    BST() {
        root = NULL;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    void printKDistant(int k) {
        printKDistant(root, k);
    }

private:
	void printKDistant(Node* node, int k) {
        if (node == nullptr) {
            return;
        }

        if (k == 0) {
            cout << (node->value) << " ";
            return;
        }

        printKDistant(node->right, k - 1);
        printKDistant(node->left, k - 1);
    }

    Node* root;

    Node* insert(Node *curNode, int value) {
        if (curNode == NULL) {
            curNode = new Node(value);
        } else if (curNode->value < value) {
            curNode->right = insert(curNode->right, value);
        } else if (curNode->value > value) {
            curNode->left = insert(curNode->left, value);
        } else {
        	//if we already have this value at the tree - do nothing
        }
        return curNode;
    }
};

int main() {
    int n;
    cin >> n;
    int value;
    BST tree;
    for(int i = 0 ; i < n; i++) {
        cin >> value;
        tree.insert(value);
    }
    int k;
    cin >> k;
    tree.printKDistant(k);
    return 0;
}
