#include <iostream>
using namespace std;

int linearSearch(int *array, int length, int target) {
    for (int i = 0; i < length; i++) {
        if (array[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {4, 7, 2, 3, 0, 9, 6, 1, 8, 5};
    int * arrStart = &arr[0];

    cout << "Index of 2 is " << linearSearch(arr, 10, 2) << "\n";
    cout << "Index of -2 is " << linearSearch(arr, 10, -2) << "\n";
}