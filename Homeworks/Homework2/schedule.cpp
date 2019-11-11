#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1000024;

struct Time {
    int start;
    int duration;

    bool operator<(const Time& other) const {
        return start + duration < other.start + other.duration;
    }
};

Time t[MAX_N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 0;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> t[i].start >> t[i].duration;
    }
    
    sort(t, t + n);

    int last = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        if (t[i].start >= last) {
            ans++;
            last = t[i].start + t[i].duration;
        }
    }

    cout << ans << endl;

    return 0;
}
