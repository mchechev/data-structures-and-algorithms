#include <iostream>
using namespace std;

int main() {
    int M, N;
    cin >> M >> N;
    
    int input = 0;
    long long sum = 0;

    for (int i = 0; i < N; i++) {
        cin >> input;
        sum += input;
    }

    int NtimesM = N * M;
    if (sum >= NtimesM) {
        cout << "yes\n";
    } else {
        cout << "no\n";
    }
}