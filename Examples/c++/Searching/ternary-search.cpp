#include <iostream>
using namespace std;

int ternarySearch(int *array, int length, int target) {
    int left = 0;
    int right = length - 1;

    while (left <= right) {
        int leftThird = left + (right - left) / 3;
        int rightThird = right - (right - left) / 3;

        if (array[leftThird] == target) {
            return leftThird;
        }
        if (array[rightThird] == target) {
            return rightThird;
        }

        if (target < array[leftThird]) {
            right = leftThird - 1;
        } else if (target > array[rightThird]) {
            left = rightThird + 1;
        } else  {
            left = leftThird + 1;
            right = rightThird - 1;
        }
    }

    return -1;
}

int main() {
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int * arrStart = &arr[0];

    cout << "Index of 2 is " << ternarySearch(arr, 10, 2) << "\n";
    cout << "Index of -2 is " << ternarySearch(arr, 10, -2) << "\n";
}