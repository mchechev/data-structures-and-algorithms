#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int x, y;
    cin >> x >> y;

    y--;

    if(x < y or (y == 0 and x > 0) or y < 0) {
        cout << "no\n";
        return;
    }

    if((x - y) % 2 != 0) {
        cout << "no\n";
        return;
    }

    cout << "yes\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) { 
        solve();
    }
 
    return 0;
}