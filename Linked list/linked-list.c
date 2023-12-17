// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void traversal(struct Node* ptr){
    while(ptr!=NULL){
        printf("%d -> ",ptr->data);
        ptr=ptr->next;
    }
    printf("NULL");
}

struct Node* beginning(int val , struct Node * ptr){
    
    struct Node* newnode=malloc(sizeof(struct Node));
    
    newnode->data=val;
    newnode->next=ptr;
    
    return newnode;
    
}

struct Node* insert_end(int val , struct Node* ptr){
    struct Node* temp=ptr;
    
    struct Node* newnode=malloc(sizeof(struct Node));
    while(temp->next!=NULL){
        temp=temp->next;
    }
    newnode->data=val;
    newnode->next=NULL;
    
    temp->next=newnode;
    
    return ptr;
    
    
}

struct Node* insert_at_point(int point ,int val ,struct Node* ptr){
    struct Node* newnode=malloc(sizeof(struct Node));
    newnode->data=val;
    printf("\n%d is inserted after %d\n",val,point);
    struct Node* temp=ptr;
    while(temp->data!=point && temp!=NULL){
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
    
    return ptr;
}

struct Node* delete_point(int val , struct Node* ptr){
    struct Node* temp=ptr;
    while(temp->next->data!=val && temp!=NULL){
        temp=temp->next;
    }
    
    printf("\n%d is deleted \n",ptr->next->data);
    temp->next=temp->next->next;
    
    return ptr;
}

struct Node* delete_beginning(struct Node* ptr){
    struct Node* temp=ptr;
    ptr=ptr->next;
    printf("\n%d deleted \n",ptr->data);
    free(temp);
    return ptr;
}


struct Node* delete_end(struct Node* temp){
    struct Node* ptr=temp;
    while(ptr->next->next!=NULL && ptr!=NULL){
        ptr=ptr->next;
    }
    printf("\n%d is deleted\n",ptr->next->data);
    ptr->next=NULL;
    return temp;
}


int main() {
    struct Node* head=malloc(sizeof(struct Node));
    struct Node* first=malloc(sizeof(struct Node));
    
    head->data=10;
    head->next=first;
    
    first->data=20;
    first->next=NULL;
    
    head=beginning(30,head);
    
    traversal(head);
    printf("\n");
    head=beginning(40,head);
    traversal(head);
    printf("\n");
    // head=insert_end(70,head);
    // traversal(head);
    printf("\n");
    // head=delete_beginning(head);
    // head=delete_beginning(head);
    // traversal(head);
    printf("\n");
    // head=delete_beginning(head);
    
    // head=delete_end(head);
    traversal(head);
    // head=delete_point(30,head);
    // traversal(head);
    
    // head=delete_point(10,head);
    // traversal(head);
    head=insert_at_point(30,5,head);
    traversal(head);
    
    head=insert_at_point(5,15,head);
    traversal(head);
    

    return 0;
}
