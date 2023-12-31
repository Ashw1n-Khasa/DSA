#include <stdio.h>
void merge(int arr[],int start,int mid , int end){
    int n1,n2;
    n1=mid-start+1;
    n2=end-mid;
    int arr1[n1],arr2[n2];
    for(int i=0;i<n1;i++){
        arr1[i]=arr[start+i];
    }
    for(int j=0;j<n2;j++){
        arr2[j]=arr[mid+1+j];
    }
    int i=0;
    int j=0;
    int k=start;
    while(i<n1 &&j<n2){
        if(arr1[i]<=arr2[j]){
            arr[k]=arr1[i];
            i++,k++;
        }
        if(arr1[i]>arr2[j]){
            arr[k]=arr2[j];
            j++,k++;
        }
        
    
    }
    while(i<n1){
            arr[k]=arr1[i];
            i++,k++;
        }
        while(j<n2){
         arr[k]=arr2[j];
         k++,j++;
     }
    
}
    
        
        
      


void mergeSort(int arr[],int start , int end){
    if(start<end){
        int mid=(start+end)/2;
         mergeSort(arr,start,mid);
         mergeSort(arr,mid+1,end);
         
         merge(arr,start,mid,end);
    }
}

int main(){
    int arr[]={4,5,1,6,2};
    int n=5;
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
