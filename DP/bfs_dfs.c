// Online C compiler to run C program online
#include <stdio.h>
#define K 4
void bfs(int adj[K][K],int start , int n )
{
    int queue[K];
    int front , rear;
    front=rear=-1;
    
    int visited[K]={0};
    queue[++rear]=start;
    visited[start]=1;
    
    printf("BFS :- ");
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

void dfs(int adj[K][K], int start, int n, int visited[]) {
    printf("%d ", start);
    visited[start] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[start][i] == 1 && !visited[i]) {
            dfs(adj, i, n, visited);
        }
    }
}

int main() {
    int n ;
    printf("Enter nodes :- ");
    scanf("%d",&n);
    
    int adj[n][n];
    int vis[K]={0};
    printf("ENter values of adj matix :- \n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
        scanf("%d",&adj[i][j]);
        }
    }
    bfs(adj,0,n);
    printf("\n");
    dfs(adj,0,n,vis);
    // bfs fucntion
    
    
    

    return 0;
}
