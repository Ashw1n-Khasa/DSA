// Online C compiler to run C program online
#include <stdio.h>
#define node 4

void bfs(int adj[node][node] ,int n ,int start){
    
    int visited[node]={0};
    int queue[node];
    int rear;
    int front = rear=-1;
    
    visited[start]=1;
    queue[++rear]=start;
    
    while(front!=rear){
        int currNode=queue[++front];
        printf("%d ",currNode);
        
        for(int i=0;i<n;i++){
            
            if(adj[currNode][i]==1 && !visited[i]){
                visited[i]=1;
                queue[++rear]=i;
            }
        }
    }
    
}

int main() {
    int n;
    printf("Enter nodes :- ");
    scanf("%d",&n);
    
    printf("Enter adj matrix:-\n");
    
    int adj[n][n];
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&adj[i][j]);
        }
    }
    
    printf("BFS :- ");
    bfs(adj,n,0);
    
    // printf("Try programiz.pro");

    return 0;
}
