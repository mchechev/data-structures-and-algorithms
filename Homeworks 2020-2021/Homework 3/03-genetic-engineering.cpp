#include <bits/stdc++.h>
using namespace std;

long long pw3[34];

int rec(long long num, long long start_num, int p, int d) {
    if (p == 0) {
        return d;
    }
    
    long long mid1 = start_num + (pw3[p] / 3);
    long long mid2 = start_num + (pw3[p] / 3) * 2;
    
    if (mid1 <= num && num < mid2) {
        return d;
    }
    if (num < mid1) {
        return rec(num, start_num, p - 1, d + 1);
    }
    return rec(num, mid2, p - 1, d + 1);
}

void solve() {
    int n, p;
    cin >> p >> n;
    
    pw3[0] = 1;
    for (int i = 1; i <= 33; i++) {
        pw3[i] = pw3[i - 1] * 3;
    }
    
    for (int i = 0; i < n; i++) {
        long long num;
        cin >> num;
        cout << rec(num, 1, p, 1) << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    
    return 0;
}