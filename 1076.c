#include <stdio.h>

int adj[1000][1000];
int vis[1000];
int V;

void dfs(int u){
    int v;
    vis[u]=1;
    for(v=0; v<V; v++){
        if(adj[u][v] && !vis[v]) dfs(v);
    }
}

int main(){
    int T;
    if(scanf("%d",&T)!=1) return 0;
    while(T--){
        int N,A;
        scanf("%d",&N);
        scanf("%d %d",&V,&A);
        int i;
        for(i=0;i<V;i++){
            int j;
            for(j=0;j<V;j++) adj[i][j]=0;
            vis[i]=0;
        }
        for(i=0;i<A;i++){
            int x,y;
            scanf("%d %d",&x,&y);
            if(x>=0 && x<V && y>=0 && y<V) adj[x][y]=adj[y][x]=1;
        }
        dfs(N);
        int soma_graus=0;
        for(i=0;i<V;i++) if(vis[i]){
            int j;
            for(j=0;j<V;j++) if(adj[i][j]) soma_graus++;
        }
        int arestas = soma_graus/2;
        printf("%d\n", arestas*2);
    }
    return 0;
}
