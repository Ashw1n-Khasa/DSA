#include <stdio.h>

void bubble(int arr[], int size) {
    int temp;
    for(int i=1;i<size;i++){
        for(int j=0;j<size-i;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
    }
}

int main() {
    int arr[] = {2, 5, 1, 7, 3, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    bubble(arr, size);
    printf("Sorted Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}

