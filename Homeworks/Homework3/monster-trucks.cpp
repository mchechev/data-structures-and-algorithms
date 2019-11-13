#include <vector>
#include <random>
#include <iostream>
#include <algorithm>
#include <chrono>
#include <fstream>

using namespace std;

struct Truck {
    long long distance = 0;
    long long price = 0;
};

long long Price(Truck* trucks, long long arrSize, long long distance) {
    long long price = 0;
    for (long long i = 0; i < arrSize; i++) {
        price += abs(trucks[i].distance - distance) * trucks[i].price;
    }
    return price;
}

long long Min(long long a, long long b) {
    return a < b ? a : b;
}

long long MinPriceTernaryNaive(Truck* trucks, long long size, long long left, long long right) {
    if (right - left < 3) { // brute force small intervals
        long long currentMin = Price(trucks, size, left);
        for (long long i = left + 1; i < right + 1; i++) {
            currentMin = Min(currentMin, Price(trucks, size, i));
        }
        return currentMin;
    }
    else if (left < right) {
        long long leftThird = left + (right - left) / 3;
        long long rightThird = right - (right - left) / 3;

        long long leftPrice = Price(trucks, size, leftThird);
        long long rightPrice = Price(trucks, size, rightThird);

        if (leftPrice < rightPrice) {
            return MinPriceTernaryNaive(trucks, size, left, rightThird);
        }
        else if (leftPrice > rightPrice) {
            return MinPriceTernaryNaive(trucks, size, leftThird, right);
        }
        else {
            return leftPrice;
        }
    }
    return -1; // in case some error occurs
}

bool Compare(Truck& lhs, Truck& rhs) {
    return (lhs.distance < rhs.distance);
}

int main() {
    long long N;
    cin >> N;
    Truck* trucks = new Truck[N];
    for (long long i = 0; i < N; i++) {
        cin >> trucks[i].distance;
        cin >> trucks[i].price;
    }

    sort(trucks, trucks + N, Compare);
    
    if (N > 1) {
        cout << MinPriceTernaryNaive(trucks, N, trucks[0].distance, trucks[N-1].distance);
    }
    else {
        cout << 0;
    }
}
