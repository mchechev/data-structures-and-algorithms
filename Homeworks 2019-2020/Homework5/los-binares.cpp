#include <iostream>
using namespace std;

struct Node {
    int data;
    int level = 0;
    Node* left = nullptr;
    Node* right = nullptr;

    Node() = default;
    
    Node(int value, int level) {
        data = value;
        this->level = level;
    }
};

class BST {
private:
    Node* root = nullptr;

    int _level(int value, Node* current) const {
        if (current) {
            if (current->data == value) {
                return current->level;
            } else if (current->data < value) {
                return _level(value, current->right);
            } else {
                return _level(value, current->left);
            }
        } else {
            return -1;
        }
    }

    Node* _insert(int value, Node* current, int currentLevel) {
        if (!current) {
            return new Node(value, currentLevel);
        }

        if (value < current->data) {
            current->left = _insert(value, current->left, currentLevel + 1);
        } else if (value > current->data) {
            current->right = _insert(value, current->right, currentLevel + 1);
        }

        return current;
    }

public:
    int level(int value) const {
        return _level(value, root);
    }

    void insert(int value) {
        root = _insert(value, root, 0);
    }

};

int main() {
    BST s;

    int N, K;
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int in;
        cin >> in;
        s.insert(in);
    }

    for (int i = 0; i < K; i++) {
        int in;
        cin >> in;
        cout  << s.level(in) << "\n";
    }

    return 0;
}
