// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
    
};

void rev_traverse( struct Node* ptr){
    struct Node* temp=ptr;
    
    while(temp->next!=NULL){
        temp=temp->next;
    }
    while(temp!=NULL){
        printf("%d <- ",temp->data);
        temp=temp->prev;
    }
    
    printf("NULL");
    
}

void traverse(struct Node* ptr){
    while(ptr!=NULL){
        printf("%d -> ",ptr->data);
        ptr=ptr->next;
    }
    printf("NULL");
}

struct Node* insert_end(int val , struct Node* ptr){
    struct Node* newnode=malloc(sizeof(struct Node));
    
    newnode->data=val;
    newnode->next=NULL;
    
    struct Node* temp=ptr;
    
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp;
    
    return ptr;
    
}

struct Node* insert_beg(int val, struct Node* ptr){
    struct Node* newnode=malloc(sizeof(struct Node));
    
    newnode->next=ptr;
    ptr->prev=newnode;
    newnode->prev=NULL;
    newnode->data=val;
    
    return newnode;
}

struct Node* insert_point(int point , int val , struct Node* ptr){
    struct Node* newnode =malloc(sizeof(struct Node));
    newnode->data=val;
    
    struct Node* temp=ptr;
    
    while(temp->data!=point){
        temp=temp->next;
    }
    
    newnode->next=temp->next;
    newnode->prev=temp;
    temp->next=newnode;
    
    
    return ptr;
}

struct Node* delete_first(struct Node* ptr){
    struct Node* temp=ptr;
    ptr=ptr->next;
    ptr->prev=NULL;
    
    free(temp);
    
    return ptr;
}

struct Node* delete_last(struct Node* ptr){
    struct Node* temp=ptr;
    
    while(ptr->next->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=NULL;
    
    return temp;
}

struct Node* delete_point(int point , struct Node* ptr){
    struct Node* temp=ptr;
    
    while(ptr->data!=point && ptr!=NULL){
        ptr=ptr->next;
    }
   struct Node* tempo =ptr;
   ptr->prev->next=ptr->next;
   ptr->next->prev=ptr->prev;
//   ptr->next=ptr->next->next;
//   ptr->next->prev=ptr;
   
   free(tempo);
   return temp;
}


int main() {
    struct Node* head=malloc(sizeof(struct Node));
    struct Node* first=malloc(sizeof(struct Node));
    struct Node* second=malloc(sizeof(struct Node));
    
    head->data=40;
    head->prev=NULL;
    head->next=first;
    
    first->prev=head;
    first->data=50;
    first->next=NULL;
    
    traverse(head);
    printf("\n");
    head=insert_end(60,head);
    head=insert_end(70,head);
    head=insert_end(80,head);
    head=insert_end(90,head);
    head=insert_beg(30,head);
    head=insert_beg(20,head);
    head=insert_beg(10,head);
    printf("\n");
    traverse(head);
    printf("\n");
    head=insert_point(40,45,head);
    head=insert_point(50,55,head);
    head=delete_first(head);
    head=delete_last(head);
    head=delete_last(head);
    head=delete_last(head);
    head=delete_point(55,head);
    head=delete_point(45,head);
    // rev_traverse(head);
    // printf("\n");
    traverse(head);
    
    
    
}
