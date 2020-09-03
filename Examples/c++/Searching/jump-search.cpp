#include <iostream>
#include <cmath>
using namespace std;

int jumpSearch(int *array, int length, int target) {
   int left = 0;
   int step = sqrt(length);
   int right = step;

   while(right < length && array[right] <= target) {
      left += step;
      right += step;
      if(right > length - 1)
         right = length;
   }

   for(int i = left; i < right; i++) {
      if(array[i] == target)
         return i;
   }

   return -1;
}

int main() {
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int * arrStart = &arr[0];

    cout << "Index of 2 is " << jumpSearch(arr, 10, 2) << "\n";
    cout << "Index of -2 is " << jumpSearch(arr, 10, -2) << "\n";
}