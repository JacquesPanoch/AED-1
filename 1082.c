#include <stdio.h>
#include <stdlib.h>

char grafo[26][26];
int visitado[26];

void dfs(int v, int V, char componente[]) {
    visitado[v] = 1;
    int len = 0;
    while (componente[len] != 0) len++;
    componente[len] = 'a' + v;
    componente[len + 1] = 0;
    
    for (int u = 0; u < V; u++) {
        if (grafo[v][u] == 1 && !visitado[u]) {
            dfs(u, V, componente);
        }
    }
}

int cmp(const void *a, const void *b) {
    return (*(char*)a - *(char*)b);
}

int main() {
    int N;
    scanf("%d", &N);
    
    for (int caso = 1; caso <= N; caso++) {
        int V, E;
        scanf("%d %d", &V, &E);
        
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                grafo[i][j] = 0;
            }
            visitado[i] = 0;
        }
        
        for (int i = 0; i < E; i++) {
            char v1, v2;
            scanf(" %c %c", &v1, &v2);
            int a = v1 - 'a';
            int b = v2 - 'a';
            grafo[a][b] = 1;
            grafo[b][a] = 1;
        }
        
        printf("Case #%d:\n", caso);
        
        int componentes = 0;
        for (int i = 0; i < V; i++) {
            if (!visitado[i]) {
                char componente[27] = {0};
                dfs(i, V, componente);
                qsort(componente, strlen(componente), sizeof(char), cmp);
                
                for (int j = 0; j < strlen(componente); j++) {
                    printf("%c,", componente[j]);
                }
                printf("\n");
                componentes++;
            }
        }
        
        printf("%d connected components\n\n", componentes);
    }
    
    return 0;
}
