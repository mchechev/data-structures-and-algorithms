#include <iostream>

void swap(int & a, int & b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int partition(int * array, int startIndex, int endIndex) {
    int pivot = array[endIndex];
    int pivotIndex = startIndex;

    for (int i = startIndex; i <= endIndex; i++) {
        if (array[i] < pivot) {
            swap(array[i], array[pivotIndex]);
            pivotIndex++;
        }
    }

    swap(array[endIndex], array[pivotIndex]);
    return pivotIndex;
}

void _quickSort(int * array, int startIndex, int endIndex) {
    if (startIndex < endIndex) {
        int pivot = partition(array, startIndex, endIndex);
        _quickSort(array, startIndex, pivot - 1);
        _quickSort(array, pivot + 1, endIndex);
    }
}

void quickSort(int * array, int length) {
    _quickSort(array, 0, length - 1);
}

int main() {
    int arr[] = {2, 5, 3, 6, 1, 4};
    int * arrStart = &arr[0];

    quickSort(arrStart, 6);

    for (int i = 0; i < 6; i++) {
        std::cout << arr[i] << ", ";
    }

    std::cout << "\n";
}