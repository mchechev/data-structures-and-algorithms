#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100024;

queue < pair <string, int> > groups[MAX_N];
queue <int> groupQueue;

int main() {
    int n, m;
    cin >> n >> m;

    int i;
    for (i = 0; i < n; i++) {
        string name;
        int group;
        cin >> name >> group;

        if (groups[group].empty()) {
            groupQueue.push(group);
        }
        groups[group].push({name, i});

        if (i > 0 && i % 2 == 0) {
            cout << groups[groupQueue.front()].front().first << " ";
            cout << groups[groupQueue.front()].front().second << " " << i << endl;
            groups[groupQueue.front()].pop();
            if (groups[groupQueue.front()].empty()) {
                groupQueue.pop();
            }
        }
    }

    if (i % 2 == 1) {
        i++;
    }

    while (!groupQueue.empty()) {
        while (!groups[groupQueue.front()].empty()) {
            cout << groups[groupQueue.front()].front().first << " ";
            cout << groups[groupQueue.front()].front().second << " " << i << endl;
            groups[groupQueue.front()].pop();
            i += 2;
        }
        groupQueue.pop();
    }

    return 0;
}

/**
8
Ivan 10
Nikolay 10
Vasil 3
Daniel 4
Yoanna 3
Maria 3
Pesho 666
Gosho 10

*/
