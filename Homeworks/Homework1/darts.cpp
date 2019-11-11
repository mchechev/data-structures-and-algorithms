#include <bits/stdc++.h>
using namespace std;

vector < pair <int, int> > v;
vector <int> doubles;

int main() {
    int n;
    cin >> n;
    v.push_back(make_pair(0, 1));
    for (int i = 1; i <= 20; i++) {
        v.push_back(make_pair(i, 1));
        v.push_back(make_pair(i, 2));
        v.push_back(make_pair(i, 3));

        doubles.push_back(i);
    }

    v.push_back(make_pair(25, 1));
    v.push_back(make_pair(25, 2));

    doubles.push_back(25);

    int ans = 0;

    for (int i = 0; i < doubles.size(); i++) {
        if (doubles[i] * 2 == n) {
            ans++;
        }
    }

    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < doubles.size(); j++) {
            if (v[i].first * v[i].second + doubles[j] * 2 == n) {
                ans++;
            }
        }
    }

    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v.size(); j++) {
            for (int l = 0; l < doubles.size(); l++) {
                if (v[i].first * v[i].second + v[j].first * v[j].second + doubles[l] * 2 == n) {
                    ans++;
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}

