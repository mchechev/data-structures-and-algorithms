#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    stack<int> street;
    int nextNum = 1;
    
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        while (street.empty() == false && street.top() == nextNum) {
            nextNum++;
            street.pop();
        }

        if (nextNum == num) {
            nextNum++;
        } else {
            street.push(num);
        }
    }

    while (street.empty() == false && street.top() == nextNum) {
        nextNum++;
        street.pop();
    }

    if (street.empty()) {
        cout << "yes\n";
        return;
    }
    cout << "no\n";
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int t;
    cin >> t; 
    
    for (int i = 0; i < t; i++) {
        solve();
    }
 
    return 0;
}