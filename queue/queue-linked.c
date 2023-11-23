#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* front =NULL;
struct Node* rear=NULL;


int isEmpty(){
    return (front==NULL);
}

void enqueue(int data){
    struct Node* newNode=malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    if(isEmpty()){
        front=rear=newNode;
        printf("%d is enqueued .\n",newNode->data);
        return;
    }
    rear->next=newNode;
    rear=newNode;
    printf("%d is enqueued .\n",rear->data);
}

void dequeue(){
    if(isEmpty()){
        printf("queue is empty.");
        return;
    }
    // struct Node* temp=front;
    printf("%d is dequeued.\n",front->data);
    if(front==rear){
        front=rear=NULL;
    }
    else{
        front=front->next;
    }
}


int main(){
    enqueue(7);
    enqueue(17);
    enqueue(72);
    dequeue();
    dequeue();
}

