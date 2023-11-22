#include <stdio.h>
#include<string.h>
#define MAX_SIZE 10
char stack[MAX_SIZE];
int top=-1;
char postfix[MAX_SIZE];

int prec(char c){
     if(c=='^'){
         return 3;
     }
     else if(c=='/'|| c=='*'){
         return 2;
     }
     else if(c=='+'|| c=='-'){
         return 1;
     }
     else return - 1;
 }

void push(char data){
        stack[++top]=data;
}

char pop(){
    return stack[top--];
}

void post2inf(char infix[]){
    int length=strlen(infix);
    int j=0;
     for(int i=0;i<length;i++){
         char current=infix[i];
         
         if(current>='a'&& current<='z'){
             postfix[j++]=current;
         }
         else if(current=='('){
             push(current);
         }
         else if(current==')'){
             while(top!=-1 &&stack[top] !='('){
                 postfix[j++]=pop();
             }
             if(top!=-1 && stack[top]=='('){
                 pop();
             }
         }
         else{
             while(top!=-1 &&prec(current)<=prec(stack[top])){
                 postfix[j]=pop();
                 j++;
             }
             push(current);
         }
     }
     while (top != -1) {
        char c = pop();
        if (c != '(' && c != ')') {
            postfix[j++] = c;
    }
    
}

     postfix[j]='\0';
     j++;
 }


int main(){
    char infix[]="(a-b/c)*(a/k-l)";
    post2inf(infix);
    printf("%s ",postfix);
    
    return 0;
}
