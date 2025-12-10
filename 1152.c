#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, peso;
} Aresta;

Aresta arestas[200010];
int pai[200010];
int tam[200010];

int compara(const void *a, const void *b) {
    return ((Aresta*)a)->peso - ((Aresta*)b)->peso;
}

int find(int x) {
    while (pai[x] != x) {
        pai[x] = pai[pai[x]];
        x = pai[x];
    }
    return x;
}

int union_find(int a, int b) {
    int ra = find(a);
    int rb = find(b);
    if (ra == rb) return 0;
    if (tam[ra] < tam[rb]) {
        pai[ra] = rb;
        tam[rb] += tam[ra];
    } else {
        pai[rb] = ra;
        tam[ra] += tam[rb];
    }
    return 1;
}

int main() {
    int m, n;
    while (1) {
        scanf("%d %d", &m, &n);
        if (m == 0 && n == 0) break;
        
        int total = 0;
        for (int i = 0; i < n; i++) {
            int x, y, z;
            scanf("%d %d %d", &x, &y, &z);
            arestas[i].u = x;
            arestas[i].v = y;
            arestas[i].peso = z;
            total += z;
        }
        
        qsort(arestas, n, sizeof(Aresta), compara);
        
        for (int i = 0; i < m; i++) {
            pai[i] = i;
            tam[i] = 1;
        }
        
        int mst = 0;
        int selecionadas = 0;
        
        for (int i = 0; i < n && selecionadas < m - 1; i++) {
            if (union_find(arestas[i].u, arestas[i].v)) {
                mst += arestas[i].peso;
                selecionadas++;
            }
        }
        
        printf("%d\n", total - mst);
    }
    
    return 0;
}
