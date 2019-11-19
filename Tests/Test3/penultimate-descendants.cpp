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

    void deletePenultimateAndPrint() {
        deletePenultimate(root);
        inorder(root);
    }

private:
    void deletePenultimate(Node* node) {
        if (node == nullptr) {
            return;
        }

        if (isLeaf(node->left) && (node->right == nullptr || isLeaf(node->right))) {
            node->value = node->left->value;
            delete node->left;
            node->left = nullptr;
        } else if (node->left == nullptr && isLeaf(node->right)) {
            node->value = node->right->value;
            delete node->right;
            node->right = nullptr;
        }

        deletePenultimate(node->left);
        deletePenultimate(node->right);
    }

    bool isLeaf(Node* node) {
        if (node == nullptr) {
            return false;
        }

        return node->left == nullptr && node->right == nullptr;
    }

    void inorder(Node* node) {
        if (node == nullptr) {
            return;
        }

        inorder(node->left);
        cout << (node->value) << " ";
        inorder(node->right);
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
    tree.deletePenultimateAndPrint();
    return 0;
}
