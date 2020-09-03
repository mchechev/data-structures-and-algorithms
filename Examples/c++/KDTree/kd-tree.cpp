#include <bits/stdc++.h>
using namespace std;

static const int SIZE = 200001;

int n, k;
vector<vector<int>> points;

struct point_comparator {
    int dimension;

    point_comparator(int dimension = 0) : dimension(dimension) {}

    bool operator()(const vector<int>& point1, const vector<int>& point2) {
        return point1[dimension] < point2[dimension];
    } 
};

long long distance_squared(vector<int>& point1, vector<int>& point2) {
    long long dist = 0;

    for(int i = 0; i < k; i++) {
        dist += (point1[i] - point2[i]) * (point1[i] - point2[i]);
    }

    return dist;
}

struct kd_node {
    vector<int> point;

    int axis;

    kd_node* left;
    kd_node* right;
};

kd_node* root;

int mem_cnt;
kd_node memory_holder[SIZE];


kd_node* build(int from, int to, int axis) {
    if (from == to) {
        return nullptr;
    }

    int mid = (from + to) / 2;

    nth_element(points.begin() + from, 
                points.begin() + mid, 
                points.begin() + to, 
                point_comparator(axis));

    kd_node* node = &memory_holder[mem_cnt++];

    node->axis = axis;
    node->point = points[mid];

    node->left = build(from, mid, (axis + 1) % k);
    node->right = build(mid + 1, to, (axis + 1) % k);

    return node;
}

// returns the distance to the nearest neightbour squared
long long nearest_neighbour(kd_node* node, vector<int>& point) {
    if (node == nullptr) {
        return LLONG_MAX;
    }

    long long result = distance_squared(node->point, point);

    if (node->point[node->axis] <= point[node->axis]) {
        result = min(result, nearest_neighbour(node->right, point));

        if (node->left && point[node->axis] - sqrt(result) <= node->point[node->axis]) {
            result = min(result, nearest_neighbour(node->left, point));
        }
    } else {
        result = min(result, nearest_neighbour(node->left, point));

        if (node->right && point[node->axis] - sqrt(result) >= node->point[node->axis]) {
            result = min(result, nearest_neighbour(node->right, point));
        }
    }

    return result;
}

void test() {
    // Arrange
    n = 6, k = 3;
    points.push_back({1, 2, 3});
    points.push_back({-1, 3, 7});
    points.push_back({5, -2, 3});
    points.push_back({1, 1, 1});
    points.push_back({-1, -2, 3});
    points.push_back({1, 3, -2});

    root = build(0, n, 0);

    // Act, Assert
    vector<int> testPoint({2, 2, 2});
    assert(nearest_neighbour(root, testPoint) == 2);

    // Free resources
    points.clear();
    n = k = 0;
    mem_cnt = 0;
    root = nullptr;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    test();

    return 0;
}