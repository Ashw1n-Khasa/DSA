// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>

int max(int a , int b){
    
    return (a>b )?  a :  b;
    
}

int lcs(char str1[],char str2[]){
    int s1=strlen(str1) ;
    int s2=strlen(str2);
    
    int dp[s1+1][s2+1];
    
    for(int i=0;i<=s1;i++){
        
        for(int j=0;j<=s2;j++){
            
            if(i==0 || j==0){
                dp[i][j]=0;
            }
            
            else if(str1[i-1] == str2[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
            
        }
    }
    
    return dp[s1][s2];
}

int main() {
    char str1[]="AGGTAB";
    char str2[]="XTXAYB";
    printf("%d",strlen(str1));
    
    // printf("%s",str);
    printf("%d",lcs(str1 , str2));
    // Write C code here
    // printf("Try programiz.pro");

    return 0;
}