#include <stdio.h>
int binary(int arr[], int size, int key) {
    int start = 0;
    int end = size - 1;

    while (start <= end) {
        int mid = (start + end) / 2;

        if (arr[mid] == key) {
            return mid;
        } else if (key > arr[mid]) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return -1;
}

int main() {
    int arr[] = {2, 5, 9, 11, 23, 32};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 9; // Number to search
    int output = binary(arr, size, key);
    
    if (output != -1) {
        printf("%d is present at %dth index\n", key, output);
    } else {
        printf("%d not found in the array\n", key);}
    return 0;
}

