#include <iostream>
using namespace std;

int _binarySearch(int* array, int left, int right, int target) {
    if (right - left < 0) {
        return -1;
    }

    int mid = (right + left) / 2;
    if (array[mid] == target) {
        return mid;
    } else if (array[mid] > target) {
        return _binarySearch(array, left, mid - 1, target);
    } else if (array[mid] < target) {
        return _binarySearch(array, mid + 1, right, target);
    }
    return -1;
}

int binarySearch(int *array, int length, int target) {
    return _binarySearch(array, 0, length - 1, target);
}

int main() {
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int * arrStart = &arr[0];

    cout << "Index of 2 is " << binarySearch(arr, 10, 2) << "\n";
    cout << "Index of -2 is " << binarySearch(arr, 10, -2) << "\n";
}