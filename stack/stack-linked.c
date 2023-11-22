#include <stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};

struct Node* top=NULL;

char isEmpty(){
    if(top==NULL){
        return 'e';
    }
} 

void push(int data){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=top;
    top=newNode;
    printf("%d pushed to stack \n",data);
}

void pop(){
    if(isEmpty()=='e'){
        printf("Stack is empty\n ");
        return;
    }
    struct Node* temp=top;
    printf("%d is poped \n",temp->data);
    top=top->next;
    free(temp);
}

void peek(){
    if(isEmpty()=='e'){
        printf("Stack is empty");
        return;
    }
    
    printf("%d is on top \n",top->data);
}

int main(){
    push(13);
    push(70);
    push(92);
    push(12);
    push(17);
    // pop();
    // pop();
    // pop();
    // pop();
    peek();
}














