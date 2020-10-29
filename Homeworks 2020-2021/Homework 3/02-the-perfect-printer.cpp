#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n;
    int k;
    cin >> n >> k;
    
    vector<int> p;
    for (int i = 0; i < k; i++) {
        int pr;
        cin >> pr;
        p.push_back(pr);
    }
    
    long long l = 0;
    long long r = LLONG_MAX;
    
    long long ans = LLONG_MAX;
    while (l <= r) {
        long long mid = (l + r) / 2;
        
        long long cur = n;
        for (int pr : p) {
            cur -= mid / pr;
            
            if (cur <= 0) {
                break;
            }
        }
        
        if (cur > 0) {
            l = mid + 1;
        } else {
            ans = mid;
            r = mid - 1;
        }
    }
    
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();

    return 0;
}