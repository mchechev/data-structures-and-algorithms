#include <bits/stdc++.h>
using namespace std;

const int SIZE = 100000 + 7;

long long n, m;
pair <long long, long long> arr[SIZE];

void input() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i].first;
    }

    for (int i = 0; i < n; i++) {
        cin >> arr[i].second;
    }
}

bool check(long long num) {
    long long baloons = m;
    for (int i = 0; i < n; i++) {
        if (arr[i].second == 0) {
            continue;
        }

        long long temp = num / arr[i].second;

        if (temp >= arr[i].first) {
            continue;
        }

        baloons -= (arr[i].first - temp);

        if (baloons < 0) {
            return false;
        }
    }
    return true;
}

void solve() {
    long long left = 0;
    long long right = 1000000000000000000;

    long long ans;
    while (left <= right) {
        long long mid = (left + right) / 2;

        if (check(mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();
    solve();

    return 0;
}