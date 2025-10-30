#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int main() {
    int n;
    
    while (scanf("%d", &n) != EOF) {
        int operacoes[MAX][2];
        int pilha[MAX], topo = -1;
        int fila[MAX], inicio = 0, fim = 0;
        int fila_prioridade[MAX], tamanho_fp = 0;
        
        int eh_pilha = 1, eh_fila = 1, eh_fila_prioridade = 1;
        
        for (int i = 0; i < n; i++) {
            scanf("%d", &operacoes[i][0]);
            if (operacoes[i][0] == 1) {
                scanf("%d", &operacoes[i][1]);
            } else {
                scanf("%d", &operacoes[i][1]);
            }
        }
        
        for (int i = 0; i < n; i++) {
            int op = operacoes[i][0];
            int x = operacoes[i][1];
            
            if (op == 1) {
                if (eh_pilha) {
                    pilha[++topo] = x;
                }
                if (eh_fila) {
                    fila[fim++] = x;
                }
                if (eh_fila_prioridade) {
                    int j = tamanho_fp;
                    fila_prioridade[tamanho_fp++] = x;
                    while (j > 0 && fila_prioridade[j] > fila_prioridade[(j-1)/2]) {
                        int temp = fila_prioridade[j];
                        fila_prioridade[j] = fila_prioridade[(j-1)/2];
                        fila_prioridade[(j-1)/2] = temp;
                        j = (j-1)/2;
                    }
                }
            } else { 
                if (eh_pilha) {
                    if (topo >= 0 && pilha[topo] == x) {
                        topo--;
                    } else {
                        eh_pilha = 0;
                    }
                }
                
                if (eh_fila) {
                    if (inicio < fim && fila[inicio] == x) {
                        inicio++;
                    } else {
                        eh_fila = 0;
                    }
                }
                
                if (eh_fila_prioridade) {
                    if (tamanho_fp > 0 && fila_prioridade[0] == x) {
                        fila_prioridade[0] = fila_prioridade[--tamanho_fp];
                        int j = 0;
                        while (2*j + 1 < tamanho_fp) {
                            int filho = 2*j + 1;
                            if (filho + 1 < tamanho_fp && fila_prioridade[filho + 1] > fila_prioridade[filho]) {
                                filho++;
                            }
                            if (fila_prioridade[j] >= fila_prioridade[filho]) {
                                break;
                            }
                            int temp = fila_prioridade[j];
                            fila_prioridade[j] = fila_prioridade[filho];
                            fila_prioridade[filho] = temp;
                            j = filho;
                        }
                    } else {
                        eh_fila_prioridade = 0;
                    }
                }
            }
        }
        
        int contador = eh_pilha + eh_fila + eh_fila_prioridade;
        
        if (contador == 0) {
            printf("impossible\n");
        } else if (contador > 1) {
            printf("not sure\n");
        } else {
            if (eh_pilha) {
                printf("stack\n");
            } else if (eh_fila) {
                printf("queue\n");
            } else {
                printf("priority queue\n");
            }
        }
    }
    
    return 0;
}
