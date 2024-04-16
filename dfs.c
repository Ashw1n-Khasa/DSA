// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct Node{
    int value;
    struct Node* next;
};

struct Node* createNode(int v){
    struct Node* temp=malloc(sizeof(struct Node));
    temp->value=v;
    temp->next=NULL;
    
    return temp;
}

struct Node* addEdg(struct Node* head,int v){
    struct Node* newnode=createNode(v);
    newnode->next=head;
    return newnode;
}

void dfs(struct Node* adjList[],int v,bool visited[]){
    visited[v]=true;
    printf("%d ",v);
    
    struct Node* temp=adjList[v];
    while(temp!=NULL){
        int value=temp->value;
        if(visited[value]==false){
            dfs(adjList,value,visited);
        }
        
        temp=temp->next;
    }
}

int main() {
    struct Node* adj[5]={NULL};
    adj[0]=addEdg(adj[0],1);
    adj[0]=addEdg(adj[0],2);
    adj[0]=addEdg(adj[0],3);
    adj[1]=addEdg(adj[1],4);
    
    bool visited[5]={false};
    printf("DFS: ");
    dfs(adj,0,visited);
    

    return 0;
}