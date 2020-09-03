#include <iostream>
#include <random>

void swap(int & a, int & b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int generateRandomNumber(int from, int to) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(from,to);

    return dist6(rng);
}

void shuffle(int * arr, int length) {
    for (int i = 0; i < length - 1; i++) {
        int swapCurrentWith = generateRandomNumber(i, length - 1);
        swap(arr[i], arr[swapCurrentWith]);
    }
}

int partition(int * array, int start, int end) {
    int pivot = array[end];
    int pivotIndex = start;
    for (int i = start; i <= end; i++) {
        if (array[i] < pivot) {
            swap(array[i], array[pivotIndex]);
            pivotIndex++;
        }
    }
    swap(array[end], array[pivotIndex]);
    return pivotIndex;
}

void _quickSort(int * array, int start, int end) {
    if (start < end) {
        int pivot = partition(array, start, end);
        _quickSort(array, start, pivot - 1);
        _quickSort(array, pivot + 1, end);
    }
}

void quickSort(int * array, int length) {
    shuffle(array, length);
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