#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no* esq;
    struct no* dir;
} No;

No* criar_no(int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

No* inserir(No* raiz, int valor) {
    if (raiz == NULL) return criar_no(valor);
    if (valor < raiz->valor) raiz->esq = inserir(raiz->esq, valor);
    else raiz->dir = inserir(raiz->dir, valor);
    return raiz;
}

void percurso_nivel(No* raiz, int N) {
    if (raiz == NULL) return;
    
    No* fila[505];
    int inicio = 0, fim = 0;
    fila[fim++] = raiz;
    
    int impresso = 0;
    while (inicio < fim) {
        No* atual = fila[inicio++];
        if (impresso++) printf(" ");
        printf("%d", atual->valor);
        
        if (atual->esq != NULL) fila[fim++] = atual->esq;
        if (atual->dir != NULL) fila[fim++] = atual->dir;
    }
    printf("\n");
}

void liberar_arvore(No* raiz) {
    if (raiz == NULL) return;
    liberar_arvore(raiz->esq);
    liberar_arvore(raiz->dir);
    free(raiz);
}

int main() {
    int C;
    scanf("%d", &C);
    
    for (int caso = 1; caso <= C; caso++) {
        int N;
        scanf("%d", &N);
        
        No* raiz = NULL;
        for (int i = 0; i < N; i++) {
            int valor;
            scanf("%d", &valor);
            raiz = inserir(raiz, valor);
        }
        
        printf("Case %d:\n", caso);
        percurso_nivel(raiz, N);
        printf("\n");
        
        liberar_arvore(raiz);
    }
    
    return 0;
}
