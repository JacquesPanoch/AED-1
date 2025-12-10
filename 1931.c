#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INF 1000000000
#define MAX 10010

typedef struct {
    int v, custo, prox;
} Aresta;

Aresta arestas[100010];
int adj[MAX];
int dist[MAX][2];
int heap[MAX * 4][3];
int tam_heap;

void insere(int cidade, int par, int custo) {
    int i = tam_heap++;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (heap[p][2] <= custo) break;
        heap[i][0] = heap[p][0];
        heap[i][1] = heap[p][1];
        heap[i][2] = heap[p][2];
        i = p;
    }
    heap[i][0] = cidade;
    heap[i][1] = par;
    heap[i][2] = custo;
}

void remove_min(int *cidade, int *par, int *custo) {
    *cidade = heap[0][0];
    *par = heap[0][1];
    *custo = heap[0][2];
    int ult_cidade = heap[--tam_heap][0];
    int ult_par = heap[tam_heap][1];
    int ult_custo = heap[tam_heap][2];
    int i = 0;
    while (2 * i + 1 < tam_heap) {
        int filho = 2 * i + 1;
        if (filho + 1 < tam_heap && heap[filho + 1][2] < heap[filho][2]) filho++;
        if (ult_custo <= heap[filho][2]) break;
        heap[i][0] = heap[filho][0];
        heap[i][1] = heap[filho][1];
        heap[i][2] = heap[filho][2];
        i = filho;
    }
    heap[i][0] = ult_cidade;
    heap[i][1] = ult_par;
    heap[i][2] = ult_custo;
}

int main() {
    int C, V;
    scanf("%d %d", &C, &V);
    
    for (int i = 1; i <= C; i++) adj[i] = -1;
    
    int idx = 0;
    for (int i = 0; i < V; i++) {
        int c1, c2, g;
        scanf("%d %d %d", &c1, &c2, &g);
        arestas[idx].v = c2;
        arestas[idx].custo = g;
        arestas[idx].prox = adj[c1];
        adj[c1] = idx++;
        arestas[idx].v = c1;
        arestas[idx].custo = g;
        arestas[idx].prox = adj[c2];
        adj[c2] = idx++;
    }
    
    for (int i = 1; i <= C; i++) {
        dist[i][0] = INF;
        dist[i][1] = INF;
    }
    
    tam_heap = 0;
    dist[1][0] = 0;
    insere(1, 0, 0);
    
    while (tam_heap > 0) {
        int cidade, par, custo;
        remove_min(&cidade, &par, &custo);
        if (custo != dist[cidade][par]) continue;
        
        for (int e = adj[cidade]; e != -1; e = arestas[e].prox) {
            int viz = arestas[e].v;
            int novo_custo = custo + arestas[e].custo;
            int nova_par = 1 - par;
            
            if (novo_custo < dist[viz][nova_par]) {
                dist[viz][nova_par] = novo_custo;
                insere(viz, nova_par, novo_custo);
            }
        }
    }
    
    int resposta = dist[C][0];
    if (resposta == INF) printf("-1\n");
    else printf("%d\n", resposta);
    
    return 0;
}
