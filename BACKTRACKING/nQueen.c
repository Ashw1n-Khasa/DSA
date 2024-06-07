// Online C compiler to run C program online
#include <stdio.h>
#include <stdbool.h>

#define K 8
bool isSafe(int arr[K][K],int x , int y , int n){
    //for 
    for(int i=0;i<=x;i++){
        if(arr[i][y]==1){
            return false;
        }
    }
    
    //left diagonal
    int r=x;
    int c=y;
    
    while(r>=0 && c>=0){
        if(arr[r][c]==1){
            return false;
        }
        r--;
        c--;
        
    }
    
    //right diagonal
    r=x;
    c=y;
    
    while(r >=0 &&c<n){
        if(arr[r][c]==1){
            return false;
        }
        r--;
        c++;
    }
    
    return true;
    
}

bool nQueen(int arr[K][K],int x,int n){
    if(x>=n){
        return true;
    }
    
    for(int i=0;i<n;i++){
        if(isSafe(arr,x,i,n)){
            arr[x][i]=1;
            if(nQueen(arr,x+1,n)){
                return true;
            }
            arr[x][i]=0;
        }
    }
    return false;
}

void print(int arr[K][K],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // int n;
    // printf("Enter size of board :- ");
    // scanf("%d",&n);
    int arr[K][K];
    for(int i=0;i<K;i++){
        for(int j=0;j<K;j++){
            arr[i][j]=0;
        }
    }
    
    if(nQueen(arr,0,K)){
        print(arr,K);
    }
    
    

    return 0;
}
