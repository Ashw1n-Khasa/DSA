#include <stdio.h>
#define size 10
struct graph{
    int total_vertex;
    int adj_mat[size][size];
};

void make_empty_graph(struct graph* gp,int vertex){
    gp->total_vertex=vertex;
    for(int i=0;i<vertex;i++){
        for(int j =0 ; j<vertex ;j++){
            gp->adj_mat[i][j]=0;
        }
    }
}

void add_to_mat(struct graph* gp,int from,int to){
    gp->adj_mat[from][to]=1;
    gp->adj_mat[to][from]=1;
}

void bfs(struct graph* gp,int start){
    int visited[size]={0};
    int queue[size];
    int front=0;
    int rear=-1;
    queue[++rear]=start;
    visited[start]=1;
    
    while(rear>=front){
        int curr_vert=queue[front++];
        printf("%d ",curr_vert); 
        
        for (int i = 0; i<gp->total_vertex;i++){
            if (gp->adj_mat[curr_vert][i] && visited[i]==0){
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}
    

int main(){
    struct graph gp;
    make_empty_graph(&gp,5);
    
    add_to_mat(&gp,0,1);
    add_to_mat(&gp,0,3);
    add_to_mat(&gp,1,2);
    add_to_mat(&gp,1,4);
    add_to_mat(&gp,2,3);
    add_to_mat(&gp,3,0);
    add_to_mat(&gp,3,4);
    
    bfs(&gp,0);
    return 0;
}