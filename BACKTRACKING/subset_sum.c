// A recursive solution for subset sum problem

#include <stdio.h>
#include <stdbool.h>

// Returns true if there is a subset
// of set[] with sum equal to given sum
bool isSubsetSum(int set[], int i,int n, int sum , int tempsum)
{
    if(sum==tempsum){
        return true;
    }
    // int size = sizeof(set)/sizeof(set[0]);
    if(i>=n){
        return false;
    }
    
    bool include=isSubsetSum(set,i+1,n,sum,tempsum+set[i]);
    
    bool exclude = isSubsetSum(set,i+1,n,sum,tempsum);
    
    return include || exclude;
}

// Driver code
int main()
{
    int set[] = { 3, 34, 4, 12, 5, 2 };
    int sum = 7;
    int n = sizeof(set) / sizeof(set[0]);
    if (isSubsetSum(set, 0,n, sum,0))
        printf("Found a subset with given sum");
    else
        printf("No subset with given sum");
    return 0;
}

