#include <bits/stdc++.h>
using namespace std;

static const int SIZE = 100000 + 7;

int n;
int arr[SIZE];

long long merge(int* a, int from, int mid, int to) {
    int* l = new int[mid - from + 1];
    int* r = new int[to - mid];

    int index = 0;
    for (int i = from; i <= mid; i++) {
        l[index++] = a[i];
    }

    index = 0;
    for (int i = mid + 1; i <= to; i++) {
        r[index++] = a[i];
    }

    
    int i = 0;
    int j = 0;
    long long res = 0;

    index = 0;
    while (i < mid - from + 1 && j < to - mid) {
        if (l[i] <= r[j]) {
            a[from + index++] = l[i++];
        }
        else {
            res += mid - from + 1 - i;
            a[from + index++] = r[j++];
        }
    }

    while (i < mid - from + 1) {
        a[from + index++] = l[i++];
    }

    while (j < to - mid) {
        a[from + index++] = r[j++];
    }

    delete[] l;
    delete[] r;
    return res;
}

long long countInversions(int* arr, int from, int to) {
    if (from == to) {
        return 0LL;
    }

    int mid = (from + to) / 2;

    long long leftRes = countInversions(arr, from, mid);
    long long rightRes = countInversions(arr, mid + 1, to);
    return leftRes + rightRes + merge(arr, from, mid, to);
}

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    input();
    cout << countInversions(arr, 0, n - 1) << "\n";

    return 0;
}