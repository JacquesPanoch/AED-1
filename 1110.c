#include <stdio.h>

#define MAX 100 

int main() {
    int n;
    
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        
        int fila[MAX];
        int inicio = 0, fim = 0;
        int primeiro = 1; 
        
        for (int i = 1; i <= n; i++) {
            fila[fim] = i;
            fim = (fim + 1) % MAX;
        }
        
        printf("Discarded cards: ");
        
        while ((fim - inicio + MAX) % MAX > 1) {
            int carta_descartada = fila[inicio];
            inicio = (inicio + 1) % MAX;
            
            if (primeiro) {
                printf("%d", carta_descartada);
                primeiro = 0;
            } else {
                printf(", %d", carta_descartada);
            }
            
            if ((fim - inicio + MAX) % MAX > 0) {
                int carta_mover = fila[inicio];
                inicio = (inicio + 1) % MAX;
                fila[fim] = carta_mover;
                fim = (fim + 1) % MAX;
            }
        }
        
        printf("\n");
        printf("Remaining card: %d\n", fila[inicio]);
    }
    
    return 0;
}
