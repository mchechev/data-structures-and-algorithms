#include <iostream>

void merge(int * originalArray, int * mergeArray, int start, int mid, int end) {
    int left = start;
    int right = mid + 1;

    for (int i = start; i <= end; i++) {
        if (left <= mid && (right > end || originalArray[left] <= originalArray[right])) {
            mergeArray[i] = originalArray[left];
            left++;
        } else {
            mergeArray[i] = originalArray[right];
            right++;
        }
    }

    for (int i = start; i <= end; i++) {
        originalArray[i] = mergeArray[i];
    }
}

void _mergeSort(int * originalArray, int * mergeArray, int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        _mergeSort(originalArray, mergeArray, start, mid);
        _mergeSort(originalArray, mergeArray, mid + 1, end);
        merge(originalArray, mergeArray, start, mid, end);
    }
}

void mergeSort(int * array, int length) {
    int * mergeArray = new int[length];
    _mergeSort(array, mergeArray, 0, length - 1);
    delete[] mergeArray;
}

int main() {
    int arr[] = {2, 5, 3, 6, 1, 4};
    int * arrStart = &arr[0];
    mergeSort(arrStart, 6);

    for (int i = 0; i < 6; i++) {
       std::cout << arr[i] << ", ";
    }

    std::cout << "\n";
}