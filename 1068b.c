#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char dado;
    struct No* proximo;
} No;

typedef struct {
    No* topo;
} Pilha;

Pilha* criarPilha() {
    Pilha* p = (Pilha*)malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

void empilhar(Pilha* p, char valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->dado = valor;
    novo->proximo = p->topo;
    p->topo = novo;
}

char desempilhar(Pilha* p) {
    if (p->topo == NULL) {
        return '\0'; 
    }
    No* temp = p->topo;
    char valor = temp->dado;
    p->topo = temp->proximo;
    free(temp);
    return valor;
}

int pilhaVazia(Pilha* p) {
    return (p->topo == NULL);
}

void liberarPilha(Pilha* p) {
    while (!pilhaVazia(p)) {
        desempilhar(p);
    }
    free(p);
}

int verificarParenteses(char expressao[]) {
    Pilha* p = criarPilha();
    int i;
    
    for (i = 0; expressao[i] != '\0'; i++) {
        if (expressao[i] == '(') {
            empilhar(p, '(');
        } 
        else if (expressao[i] == ')') {
            if (!pilhaVazia(p)) {
                desempilhar(p);
            } else {
                liberarPilha(p);
                return 0; 
            }
        }
    }
    
    int resultado = pilhaVazia(p);
    liberarPilha(p);
    return resultado;
}

int main() {
    char expressao[1001];
    
    while (scanf("%s", expressao) != EOF) {
        if (verificarParenteses(expressao)) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
    }
    
    return 0;
}
