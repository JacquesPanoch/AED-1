#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, peso;
} Aresta;

Aresta arestas[50010];
int pai[40010];

int compara(const void *a, const void *b) {
    return ((Aresta*)a)->peso - ((Aresta*)b)->peso;
}

int find(int x) {
    if (pai[x] != x) pai[x] = find(pai[x]);
    return pai[x];
}

int union_find(int a, int b) {
    int ra = find(a);
    int rb = find(b);
    if (ra == rb) return 0;
    pai[rb] = ra;
    return 1;
}

int main() {
    int M, N;
    while (1) {
        scanf("%d %d", &M, &N);
        if (M == 0 && N == 0) break;
        
        for (int i = 0; i < N; i++) {
            scanf("%d %d %d", &arestas[i].u, &arestas[i].v, &arestas[i].peso);
        }
        
        qsort(arestas, N, sizeof(Aresta), compara);
        
        for (int i = 0; i < M; i++) pai[i] = i;
        
        int soma = 0;
        int selecionadas = 0;
        
        for (int i = 0; i < N && selecionadas < M - 1; i++) {
            if (union_find(arestas[i].u, arestas[i].v)) {
                soma += arestas[i].peso;
                selecionadas++;
            }
        }
        
        printf("%d\n", soma);
    }
    
    return 0;
}
