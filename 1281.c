#include <stdio.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);
    
    for (int caso = 0; caso < N; caso++) {
        int M;
        scanf("%d", &M);
        
        char produtos[100][55];
        double precos[100];
        
        for (int i = 0; i < M; i++) {
            scanf("%s %lf", produtos[i], &precos[i]);
        }
        
        int P;
        scanf("%d", &P);
        
        double total = 0.0;
        for (int i = 0; i < P; i++) {
            char nome[55];
            int qtd;
            scanf("%s %d", nome, &qtd);
            
            for (int j = 0; j < M; j++) {
                if (strcmp(nome, produtos[j]) == 0) {
                    total += precos[j] * qtd;
                    break;
                }
            }
        }
        
        printf("R$ %.2lf\n", total);
    }
    
    return 0;
}
