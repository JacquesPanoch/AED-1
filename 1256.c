#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    for (int caso = 0; caso < N; caso++) {
        int M, C;
        scanf("%d %d", &M, &C);

        int tabela[101][201];
        int tam[101];
        for (int i = 0; i < M; i++) tam[i] = 0;

        for (int i = 0; i < C; i++) {
            int x;
            scanf("%d", &x);
            int h = x % M;
            tabela[h][tam[h]++] = x;
        }

        for (int i = 0; i < M; i++) {
            printf("%d ->", i);
            for (int j = 0; j < tam[i]; j++)
                printf(" %d ->", tabela[i][j]);
            printf(" \\\n");
        }

        if (caso < N - 1) printf("\n");
    }
    return 0;
}
