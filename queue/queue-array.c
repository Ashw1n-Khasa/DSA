// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>

#define size 10
int queue[size];
int front=-1;
int rear=-1;

int isEmpty(){
    return front==-1&&rear==-1;
}
int isFull(){
    return rear==size-1;
}

void enqueue(int data){
    if(isFull()){
        printf("queue is full\n");
    }
    else{
        if(isEmpty()){
            
            front=rear=0;
        }
        
    }
    queue[rear++]=data;
    printf("%d is queued \n",data);
    
}

void dequeue(){
    if(isEmpty()){
        printf("cant dequeue , queue is empyt\n");
    }
    
    else{
        printf("%d is dequeued \n",queue[front]);
        if(front==rear){
            front=rear=-1;
        }
        else{
            front++;
        }
    }
}


int main() {
    enqueue(7);
    enqueue(9);
    enqueue(2);
    enqueue(19);
    dequeue();

    return 0;
}
