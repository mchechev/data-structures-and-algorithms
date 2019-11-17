#include <iostream>
using namespace std;

int binarySearch(int *array, int length, int target) {

}

int main() {
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int * arrStart = &arr[0];

    cout << "Index of 2 is " << binarySearch(arr, 10, 2) << "\n";
    cout << "Index of -2 is " << binarySearch(arr, 10, -2) << "\n";
}