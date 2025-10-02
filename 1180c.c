#include <stdio.h>
#include <stdlib.h> 

int main() {
    int n, i, menor, posicao = 0;

    do {
        scanf("%d", &n);
    } while (n < 0 || n > 1000);

    int *x = (int*) malloc(n * sizeof(int));
    if (x == NULL) {
        printf("Erro de alocacao!\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        scanf("%d", (x + i));

        if (i == 0) menor = *(x + i);
        if (menor > *(x + i)) {
            menor = *(x + i);
            posicao = i;
        }
    }

    printf("Menor valor: %d\n", menor);
    printf("Posicao: %d\n", posicao);

    free(x); 

    return 0;
}
