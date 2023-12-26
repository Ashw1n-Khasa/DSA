// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
struct node{
    int p_id;
    struct node* next ;
}*start,*ptr;

int main() {
    start =malloc(sizeof(struct node));
    int n;
    printf("\nEnter Number of player:- ");
    scanf("%d",&n);
    
    int key;
    printf("\nEnter key:- ");
    scanf("%d",&key);
    
    start->p_id=1;
    
    ptr=start;
    
    for(int i=2;i<=n;i++){
        struct node* newnode=malloc(sizeof(struct node));
        
        ptr->next=newnode;
        newnode->p_id=i;
        newnode->next=start;
        
        
        ptr=newnode;
        
    }
    
    for(n;n>1;n--){
        for(int i=0;i<key-1;++i){
            ptr=ptr->next;
        }
        ptr->next=ptr->next->next;
    }
    
    printf("\nwinner is:- %d",ptr->p_id);

    return 0;
}
