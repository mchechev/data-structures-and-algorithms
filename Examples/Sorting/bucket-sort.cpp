#include <iostream>
#include <vector>
#include <algorithm>

void bucketSort(double *array, int length) {
    std::vector<double> buckets[length];

    for(int i = 0; i < length; i++) {
        buckets[int(length * array[i])].push_back(array[i]);
    }

    for(int i = 0; i < length; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    int index = 0;
    for(int i = 0; i < length; i++) {
        while(!buckets[i].empty()) {
            array[index] = buckets[i][0];
            index++;
            buckets[i].erase(buckets[i].begin());
        }
    }
}

int main() {
    double arr[] = {0.25, 0.36, 0.58, 0.41, 0.29, 0.22, 0.45, 0.79, 0.01, 0.69};
    double * arrStart = &arr[0];

    bucketSort(arrStart, 10);

    for (int i = 0; i < 10; i++) {
        std::cout << arr[i] << ", ";
    }

    std::cout << "\n";
}