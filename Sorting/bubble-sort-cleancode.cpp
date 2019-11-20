#include <iostream>

void swap(int & a, int & b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void bubbleSort(int * array, int length) {
    for (int bubbleStartIndex = 0; bubbleStartIndex < length; bubbleStartIndex++) {
        for (int bubbleMovedIndex = 0; bubbleMovedIndex < length - 1; bubbleMovedIndex++) {
            if (array[bubbleMovedIndex] > array[bubbleMovedIndex + 1]) {
                swap(array[bubbleMovedIndex], array[bubbleMovedIndex + 1]);
            }
        }
    }
}

int main() {
    int arr[] = {2, 5, 3, 6, 1, 4};
    int * arrStart = &arr[0];

    bubbleSort(arrStart, 6);

    for (int i = 0; i < 6; i++) {
        std::cout << arr[i] << ", ";
    }

    std::cout << "\n";
}