#include <stdio.h>

#define INF 1000000000

int n, e;
int grafo[501][501];
int dist[501];
int usado[501];

void iniciar_grafo() {
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            grafo[i][j] = -1;
        }
    }
}

void dijkstra(int origem) {
    int i, j;

    for (i = 1; i <= n; i++) {
        dist[i] = INF;
        usado[i] = 0;
    }
    dist[origem] = 0;

    for (i = 1; i <= n; i++) {
        int u = -1;
        int menor = INF;

        for (j = 1; j <= n; j++) {
            if (!usado[j] && dist[j] < menor) {
                menor = dist[j];
                u = j;
            }
        }

        if (u == -1) return;

        usado[u] = 1;

        for (j = 1; j <= n; j++) {
            if (grafo[u][j] != -1) {
                int novo = dist[u] + grafo[u][j];
                if (novo < dist[j]) dist[j] = novo;
            }
        }
    }
}

int main() {
    while (1) {
        int i, j, x, y, h, k, o, d;

        if (scanf("%d %d", &n, &e) != 2)
            return 0;

        if (n == 0 && e == 0)
            break;

        iniciar_grafo();

        for (i = 0; i < e; i++) {
            scanf("%d %d %d", &x, &y, &h);
            grafo[x][y] = h;
        }

        for (x = 1; x <= n; x++) {
            for (y = 1; y <= n; y++) {
                if (grafo[x][y] != -1 && grafo[y][x] != -1) {
                    grafo[x][y] = 0;
                    grafo[y][x] = 0;
                }
            }
        }

        scanf("%d", &k);

        for (i = 0; i < k; i++) {
            scanf("%d %d", &o, &d);
            dijkstra(o);

            if (dist[d] >= INF)
                printf("Nao e possivel entregar a carta\n");
            else
                printf("%d\n", dist[d]);
        }

        printf("\n");
    }

    return 0;
}
