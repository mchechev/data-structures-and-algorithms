#include <iostream>

void swap(int & a, int & b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void selectionSort(int * array, int length) {
    for (int currentIndex = 0; currentIndex < length; currentIndex++) {
        int smallestNumberIndex = currentIndex;

        for (int potentialSmallerNumberIndex = currentIndex + 1;
             	potentialSmallerNumberIndex < length;
             	potentialSmallerNumberIndex++) {
            if (array[potentialSmallerNumberIndex] < array[smallestNumberIndex]) {
                smallestNumberIndex = potentialSmallerNumberIndex;
            }
        }
        
        swap(array[currentIndex], array[smallestNumberIndex]);
    }
}

int main() {
    int arr[] = {2, 5, 3, 6, 1, 4};
    int * arrStart = &arr[0];

    selectionSort(arrStart, 6);

    for (int i = 0; i < 6; i++) {
        std::cout << arr[i] << ", ";
    }

    std::cout << "\n";
}