#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1001

typedef struct {
    char itens[MAX];
    int topo;
} Pilha;

void inicializar(Pilha *p) {
    p->topo = -1;
}

int vazia(Pilha *p) {
    return (p->topo == -1);
}

void push(Pilha *p, char c) {
    if (p->topo < MAX - 1) {
        p->itens[++(p->topo)] = c;
    }
}

char pop(Pilha *p) {
    if (!vazia(p)) {
        return p->itens[(p->topo)--];
    }
    return '\0';
}

int main() {
    int N;
    scanf("%d", &N);
    getchar(); 

    for (int t = 0; t < N; t++) {
        char linha[MAX];
        fgets(linha, MAX, stdin);

        linha[strcspn(linha, "\n")] = '\0';

        Pilha pilha;
        inicializar(&pilha);

        int diamantes = 0;
        for (int i = 0; linha[i] != '\0'; i++) {
            if (linha[i] == '<') {
                push(&pilha, '<');
            } else if (linha[i] == '>') {
                if (!vazia(&pilha)) {
                    pop(&pilha);
                    diamantes++;
                }
            }
        }
        printf("%d\n", diamantes);
    }

    return 0;
}
