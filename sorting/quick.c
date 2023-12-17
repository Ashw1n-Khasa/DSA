// Online C compiler to run C program online
#include <stdio.h>
void swap(int *a , int* b ){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}


int partition(int arr[],int start,int end){
    int i=start+1;
    int pivot=arr[start];
    for(int j=start+1;j<=end;j++){
        if(arr[j]<pivot){
            swap(&arr[i],&arr[j]);
            i++;
        }
    }
    swap(&arr[start],&arr[i-1]);
    return (i-1);
}

void quick(int arr[],int start,int end){
    if(start<end){
        int p_index=partition(arr,start,end);
        quick(arr,start,p_index-1);
        quick(arr,p_index+1,end);
    }
}

int main() {
    int arr[]={9,1,8,0,2};
    int size=sizeof(arr)/sizeof(arr[0]);
    quick(arr,0,size-1);
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }


    return 0;
}
