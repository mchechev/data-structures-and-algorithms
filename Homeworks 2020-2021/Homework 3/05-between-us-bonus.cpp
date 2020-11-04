#include <bits/stdc++.h>
using namespace std;

double distance(pair<double, double> a, pair<double, double> b) {
    return sqrt((a.first - b.first) * (a.first - b.first) + 
                (a.second - b.second) * (a.second - b.second));
}

void solve() {
    double x1, y1;
    cin >> x1 >> y1;
    
    double x2, y2;
    cin >> x2 >> y2;
    
    double v1, v2;
    cin >> v1 >> v2;
    
    double l = min(x1, x2);
    double r = max(x1, x2);
    
    double ans = (double) INT_MAX;
    
    int iterations = 30;
    while (iterations--) {
        double mid1 = l + (r - l) / 3.0;
        double mid2 = r - (r - l) / 3.0;
        
        double time1 = distance({x1, y1}, {mid1, 0.0}) / v1 + 
                       distance({mid1, 0.0}, {x2, y2}) / v2;
        
        double time2 = distance({x1, y1}, {mid2, 0.0}) / v1 + 
                       distance({mid2, 0.0}, {x2, y2}) / v2;
        
        ans = min(ans, min(time1, time2));
        
        if (time1 <= time2) {
            r = mid2;
        } else {
            l = mid1;
        }
    }
    
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(5);
    
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    
    return 0;
}