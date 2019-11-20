#include <iostream>
using namespace std;

int binarySearch(int *array, int length, int target) {
    int left = 0;
    int right = length - 1;

    while(left <= right) {
        int mid = (left + right) / 2;

        if (array[mid] == target) {
            return mid;
        }
        if (array[mid] > target) {
            right = mid - 1;
        }
        if (array[mid] < target) {
            left = mid + 1;
        }
    }

    return -1;
}

int main() {
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int * arrStart = &arr[0];

    cout << "Index of 2 is " << binarySearch(arr, 10, 2) << "\n";
    cout << "Index of -2 is " << binarySearch(arr, 10, -2) << "\n";
}