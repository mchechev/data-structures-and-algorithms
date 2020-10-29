#include <bits/stdc++.h>
using namespace std;

int bs1(vector<int>&v, int num) {
    int l = 0;
    int r = v.size() - 1;
    
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (v[mid] <= num) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return l - 1;
}

int bs2(vector<int>&v, int num) {
    int l = 0;
    int r = v.size() - 1;
    
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (v[mid] >= num) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return r + 1;
}

void solve() {
    int n, q;
    cin >> n >> q;
    
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }
    
    sort(v.begin(), v.end());
    
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        
        if (a > b) {
            cout << 0 << endl;
        } else {
            cout << bs1(v, b) - bs2(v, a) + 1 << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();

    return 0;
}