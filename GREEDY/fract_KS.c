
#include <stdio.h>
void swap(float* a , float* b){
    float temp=*a;
    *a=*b;
    *b=temp;
}

void swapI(int* a , int* b ){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void KS(int wt[],int prof[],float prof_wt[],int capac){
    int i=0;
    float profit=0;
    while(capac!=0 && (capac-wt[i]>=0)){
        profit+=prof[i];
        capac-=wt[i];
        printf("profit :- %d | ",prof[i]);
        printf("weight:- %d ",wt[i]);
        printf("\n");
        i++;
    }
    printf("remaining capc :- %d ",capac);
    printf("\n profit :- %f ",profit);
    
    profit+=capac*prof_wt[i];
    
    
    printf("Max profit :- %.2f ",profit);
    
}

int main(){
    int prof[]={10,5,15,7,6,18,3};
    int wt[]={2,3,5,7,1,4,1};
    
    int n=sizeof(wt)/sizeof(wt[0]);
    float prof_wt[n];
    
    int capac=15;
    
    for(int i=0;i<n;i++){
        prof_wt[i]=(float)prof[i]/wt[i];
    }
    
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(prof_wt[j]<prof_wt[j+1]){
                swap(&prof_wt[j],&prof_wt[j+1]);
                swapI(&wt[j],&wt[j+1]);
                swapI(&prof[j],&prof[j+1]);
            }
        }
    }
    
    for(int i=0;i<n;i++){
        printf("wt :- %d , prof :- %d , p/w :- %.1f ",wt[i],prof[i],prof_wt[i]);
        printf("\n");
    }
    
    KS(wt,prof,prof_wt,capac);
}