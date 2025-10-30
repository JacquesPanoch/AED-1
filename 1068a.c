#include <stdio.h>
#include <string.h>

#define MAX 1001

int main() {
    char expressao[MAX];
    char pilha[MAX];
    int topo;
    int i, correto;
    
    while (scanf("%s", expressao) != EOF) {
        topo = -1;
        correto = 1;
        
        for (i = 0; expressao[i] != '\0'; i++) {
            if (expressao[i] == '(') {
                topo++;
                pilha[topo] = '(';
            } 
            else if (expressao[i] == ')') {
                if (topo >= 0 && pilha[topo] == '(') {
                    topo--; 
                } else {
                    correto = 0;
                    break;
                }
            }
        }
        
        if (topo == -1 && correto == 1) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
    }
    
    return 0;
}
