#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100024;

int n, k;
int a[MAX_N];

bool check(int m) {
    int cows = 1;
    int last = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] - last >= m) {
            cows++;
            last = a[i];
        }
    }

    return cows >= k;
}

int main() {
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }
    sort(a, a + n);

    int l = 0, r = 2000000000;
    int ans = 0;
    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    printf("%d\n", ans);
    return 0;
}

