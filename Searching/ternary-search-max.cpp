#include <iostream>
using namespace std;

int ternarySearchMax(int *array, int length, int target) {
    
}

int main() {
    int arr[] = {0, 1, 2, 3, 4, 5, 4, 3, 2, 1};
    int * arrStart = &arr[0];

    int maxIndex = ternarySearchMax(arr, 10);
    cout << "Max index is " << maxIndex << " with value " << array[maxIndex] << "\n";
}