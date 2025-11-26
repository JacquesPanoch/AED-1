#include <stdio.h>

void lerFila(int fila[], int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &fila[i]);
    }
}

void lerSaidas(int sairam[], int m) {
    for (int i = 0; i < m; i++) {
        scanf("%d", &sairam[i]);
    }
}

void removerSaidas(int fila[], int *n, int sairam[], int m) {
    int novaFila[50000];
    int tam = 0;

    for (int i = 0; i < *n; i++) {
        int id = fila[i];
        int saiu = 0;

        for (int j = 0; j < m; j++) {
            if (id == sairam[j]) {
                saiu = 1;
                break;
            }
        }

        if (!saiu) {
            novaFila[tam++] = id;
        }
    }

    for (int i = 0; i < tam; i++) {
        fila[i] = novaFila[i];
    }

    *n = tam;
}

void imprimirFila(int fila[], int n) {
    for (int i = 0; i < n; i++) {
        if (i > 0) printf(" ");
        printf("%d", fila[i]);
    }
    printf("\n");
}

int main() {
    int n, m;
    int fila[50000], sairam[50000];

    scanf("%d", &n);
    lerFila(fila, n);

    scanf("%d", &m);
    lerSaidas(sairam, m);

    removerSaidas(fila, &n, sairam, m);
    imprimirFila(fila, n);

    return 0;
}
