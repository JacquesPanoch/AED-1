#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char val;
    struct No *esq, *dir;
} No;

No* novoNo(char val) {
    No* no = (No*) malloc(sizeof(No));
    no->val = val;
    no->esq = no->dir = NULL;
    return no;
}

No* inserir(No* raiz, char val) {
    if (raiz == NULL) return novoNo(val);
    if (val < raiz->val)
        raiz->esq = inserir(raiz->esq, val);
    else if (val > raiz->val)
        raiz->dir = inserir(raiz->dir, val);
    return raiz;
}

void infixa(No* raiz, int *primeiro) {
    if (raiz != NULL) {
        infixa(raiz->esq, primeiro);
        if (!*primeiro) printf(" ");
        printf("%c", raiz->val);
        *primeiro = 0;
        infixa(raiz->dir, primeiro);
    }
}

void prefixa(No* raiz, int *primeiro) {
    if (raiz != NULL) {
        if (!*primeiro) printf(" ");
        printf("%c", raiz->val);
        *primeiro = 0;
        prefixa(raiz->esq, primeiro);
        prefixa(raiz->dir, primeiro);
    }
}

void posfixa(No* raiz, int *primeiro) {
    if (raiz != NULL) {
        posfixa(raiz->esq, primeiro);
        posfixa(raiz->dir, primeiro);
        if (!*primeiro) printf(" ");
        printf("%c", raiz->val);
        *primeiro = 0;
    }
}

int busca(No* raiz, char val) {
    if (raiz == NULL) return 0;
    if (raiz->val == val) return 1;
    if (val < raiz->val) return busca(raiz->esq, val);
    else return busca(raiz->dir, val);
}

int main() {
    No* raiz = NULL;
    char comando[10];
    char val;

    while (scanf("%s", comando) != EOF) {
        if (strcmp(comando, "I") == 0) {
            scanf(" %c", &val);
            raiz = inserir(raiz, val);
        }
        else if (strcmp(comando, "INFIXA") == 0) {
            int primeiro = 1;
            infixa(raiz, &primeiro);
            printf("\n");
        }
        else if (strcmp(comando, "PREFIXA") == 0) {
            int primeiro = 1;
            prefixa(raiz, &primeiro);
            printf("\n");
        }
        else if (strcmp(comando, "POSFIXA") == 0) {
            int primeiro = 1;
            posfixa(raiz, &primeiro);
            printf("\n");
        }
        else if (strcmp(comando, "P") == 0) {
            scanf(" %c", &val);
            if (busca(raiz, val))
                printf("%c existe\n", val);
            else
                printf("%c nao existe\n", val);
        }
    }
    return 0;
}
