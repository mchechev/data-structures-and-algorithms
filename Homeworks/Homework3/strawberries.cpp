#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100024;

long long a[MAX_N];
long long p[MAX_N];

int main() {
    long long n;
    scanf("%lld", &n);

    scanf("%lld", &a[0]);
    p[0] = a[0];
    for (int i = 1; i < n; i++) {
        scanf("%lld", &a[i]);
        p[i] = p[i - 1] + a[i];
    }

    long long m;
    scanf("%lld", &m);

    for (int i = 0; i < m; i++) {
        long long q;
        scanf("%lld", &q);

        long long l = 0, r = n - 1;
        long long ans = n;
        while (l <= r) {
            int m = (l + r) / 2;
            if (p[m] >= q) {
                ans = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        ans++;
        printf("%lld\n", ans);
    }

    return 0;
}

