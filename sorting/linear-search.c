#include <stdio.h>

int linear(int a[], int size, int key) {
    int i;
    for (i = 0; i < size; i++) {
        if (a[i] == key) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {2, 6, 1, 8, 3, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 3;
    int id = linear(arr, size, key);
    if (id != -1) {
        printf("Key found at index: %d\n", id);
    } else {
        printf("Key not found\n");
    }

    return 0;
}

