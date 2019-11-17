#include <iostream>
#include <random>

void swap(int & a, int & b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int partition(int * array, int start, int end)  {
    int pivot = array[(start + end) / 2];
    int left = start;
    int right = end;

    while (left <= right) {
        while (array[left] < pivot) {
            left++;
        }
        while (array[right] > pivot) {
            right--;
        }

        swap(array[left], array[right]);
        left++;
        right--;
    }

    return left;
}

void _quickSort(int * array, int start, int end) {
    if (start < end) {
        int pivot = partition(array, start, end);
        _quickSort(array, start, pivot - 1);
        _quickSort(array, pivot, end);
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