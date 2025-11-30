#include <stdio.h>

void copiar(int destino[], int origem[], int n) {
    for (int i = 0; i < n; i++) {
        destino[i] = origem[i];
    }
}

void ordenarDecrescente(int v[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (v[j] < v[j + 1]) {
                temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}

int contarIguais(int original[], int ordenado[], int n) {
    int c = 0;
    for (int i = 0; i < n; i++) {
        if (original[i] == ordenado[i]) c++;
    }
    return c;
}

int main() {
    int T;
    int M;
    int original[1000], ordenado[1000];

    scanf("%d", &T);

    while (T--) {
        scanf("%d", &M);

        for (int i = 0; i < M; i++) {
            scanf("%d", &original[i]);
        }

        copiar(ordenado, original, M);
        ordenarDecrescente(ordenado, M);

        printf("%d\n", contarIguais(original, ordenado, M));
    }

    return 0;
}
