#include <iostream>
using namespace std;

int interpolationSearch(int *array, int length, int target) {
    int left = 0;
    int right = length - 1;

    while (array[right] != array[left] && target >= array[left] && target <= array[right]) {
        int mid = left + ((target - array[left]) * (right - left) / (array[right] - array[left]));

        if (array[mid] < target)
            left = mid + 1;
        else if (target < array[mid])
            right = mid - 1;
        else
            return mid;
    }

    if (target == array[left])
        return left;
    else
        return -1;
}

int main() {
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int * arrStart = &arr[0];

    cout << "Index of 2 is " << interpolationSearch(arr, 10, 2) << "\n";
    cout << "Index of -2 is " << interpolationSearch(arr, 10, -2) << "\n";
}