#include <bits/stdc++.h>
using namespace std;

const int SIZE = 200001;

int n, q, s;
int a[SIZE];
int prefixSum[SIZE];

void input() {
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

int findLast(int num) {
    int res = -1;
    int r = num;
    int l = 0;

    while (l <= r) {
        int mid = (l + r) >> 1;

        int intervalSum = prefixSum[num] - prefixSum[mid] + a[mid];

        if (intervalSum > s) {
            res = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    return num - res;
}

int findFirst(int num) {
    int l = 0, r = n - 1;

    while (l <= r) {
        int mid = (l + r) >> 1;

        if (a[mid] <= num) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    return l - 1;
}

void solve() {
    sort(a, a + n);

    prefixSum[0] = a[0];
    for (int i = 1; i < n; i++) {
        prefixSum[i] = prefixSum[i - 1] + a[i];
    }

    for (int i = 0; i < q; i++) {
        int p;
        cin >> s >> p;
        cout << findLast(findFirst(p)) << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    input();
    solve();

    return 0;
}