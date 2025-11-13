#include <stdio.h>
#include <stdlib.h>

int ciclo;
int *estado;
int **grafo;
int *tamanho;

void dfs(int v) {
    estado[v] = 1;
    for (int i = 0; i < tamanho[v]; i++) {
        int viz = grafo[v][i];
        if (estado[viz] == 0) dfs(viz);
        else if (estado[viz] == 1) ciclo = 1;
        if (ciclo) return;
    }
    estado[v] = 2;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int N, M;
        scanf("%d %d", &N, &M);

        grafo = (int **)malloc((N + 1) * sizeof(int *));
        tamanho = (int *)calloc(N + 1, sizeof(int));
        for (int i = 1; i <= N; i++) grafo[i] = NULL;

        for (int i = 0; i < M; i++) {
            int A, B;
            scanf("%d %d", &A, &B);
            tamanho[A]++;
            grafo[A] = (int *)realloc(grafo[A], tamanho[A] * sizeof(int));
            grafo[A][tamanho[A] - 1] = B;
        }

        estado = (int *)calloc(N + 1, sizeof(int));
        ciclo = 0;

        for (int i = 1; i <= N && !ciclo; i++)
            if (estado[i] == 0) dfs(i);

        printf(ciclo ? "SIM\n" : "NAO\n");

        for (int i = 1; i <= N; i++) free(grafo[i]);
        free(grafo);
        free(tamanho);
        free(estado);
    }
    return 0;
}
