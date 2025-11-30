#include <stdio.h>

int pilha[1000];
int topo;

void iniciarPilha() {
    topo = 0;
}

void empilhar(int x) {
    pilha[topo++] = x;
}

int desempilhar() {
    return pilha[--topo];
}

int vazia() {
    return topo == 0;
}

int topoPilha() {
    return pilha[topo - 1];
}

int verificar(int n, int ordem[]) {
    iniciarPilha();

    int proximo = 1;
    int i = 0;

    while (i < n) {
        if (!vazia() && topoPilha() == ordem[i]) {
            desempilhar();
            i++;
        } else if (proximo <= n) {
            empilhar(proximo);
            proximo++;
        } else {
            return 0;
        }
    }

    return 1;
}

int main() {
    int n;
    int ordem[1000];

    while (1) {
        scanf("%d", &n);
        if (n == 0) break;

        while (1) {
            scanf("%d", &ordem[0]);
            if (ordem[0] == 0) {
                printf("\n");
                break;
            }

            for (int i = 1; i < n; i++) {
                scanf("%d", &ordem[i]);
            }

            if (verificar(n, ordem))
                printf("Yes\n");
            else
                printf("No\n");
        }
    }

    return 0;
}
