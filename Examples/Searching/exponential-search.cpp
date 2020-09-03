#include <iostream>
using namespace std;

int binarySearch(int *array, int length, int target) {
    int left = 0;
    int right = length - 1;

    while(left <= right) {
        int mid = (left + right) / 2;

        if (array[mid] == target) {
            return mid;
        }
        if (array[mid] > target) {
            right = mid - 1;
        }
        if (array[mid] < target) {
            left = mid + 1;
        }
    }

    return -1;
}

int exponentialSearch(int *array, int length, int target) {
   if (length == 0) {
      return false;
   }

   int right = 1;
   while (right < length && array[right] < target) {
      right *= 2;
   }

   int binaryIndex = binarySearch(array + right/2, min(right + 1, length) - right/2, target);
   if (binaryIndex != -1) {
      return binaryIndex + right/2;
   } else {
      return -1;
   }
}

int main() {
   int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
   int * arrStart = &arr[0];


    cout << "Index of 2 is " << exponentialSearch(arr, 10, 2) << "\n";
    cout << "Index of -2 is " << exponentialSearch(arr, 10, -2) << "\n";
}