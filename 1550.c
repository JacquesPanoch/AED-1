#include <stdio.h>
#include <stdlib.h>

#define INF 1000000000
#define MAX 10000

int fila[MAX * 2];
int dist[MAX];
int visitado[MAX];

int inverte(int x) {
    int inv = 0;
    while (x > 0) {
        inv = inv * 10 + (x % 10);
        x /= 10;
    }
    return inv;
}

int main() {
    int T;
    scanf("%d", &T);
    
    while (T--) {
        int A, B;
        scanf("%d %d", &A, &B);
        
        for (int i = 0; i < MAX; i++) {
            dist[i] = INF;
            visitado[i] = 0;
        }
        
        int ini = 0, fim = 0;
        fila[fim++] = A;
        dist[A] = 0;
        
        while (ini < fim) {
            int atual = fila[ini++];
            
            if (atual == B) break;
            
            int prox1 = atual + 1;
            if (prox1 < MAX && dist[atual] + 1 < dist[prox1]) {
                dist[prox1] = dist[atual] + 1;
                fila[fim++] = prox1;
            }
            
            int prox2 = inverte(atual);
            if (prox2 < MAX && dist[atual] + 1 < dist[prox2]) {
                dist[prox2] = dist[atual] + 1;
                fila[fim++] = prox2;
            }
        }
        
        printf("%d\n", dist[B]);
    }
    
    return 0;
}
