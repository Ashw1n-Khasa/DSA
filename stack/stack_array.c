#include <stdio.h>
#define MAX_SIZE 10
int stack[MAX_SIZE];
int top=-1;

char isEmpty(){
    if(top==-1){
        return 'e';
    }
    
}

char isFull(){
    if(top==MAX_SIZE-1){
        return 'f';
    }
    
}

void push(int data){
    if(isFull()=='f'){
        printf("Stack Overflow\n");
    }
    stack[++top]=data;
    printf("%d pushed into stack \n",data);
}

int pop(){
    if(isEmpty()=='e'){
        printf("Stack underflow!\n");
        return;
    }
    
    printf("%d is poped .\n",stack[top--]);
    
}

int peek(){
    if(isEmpty()=='e'){
        printf("Stack is empty\n");
        return;
    }
    printf("%d is on top of stack \n",stack[top]);
}


int main(){
    // push(3);
    // push(7);
    // push(1);
    // push(2);
    
    peek();

    
    
    
}
