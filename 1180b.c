#include <stdio.h>

int main() {
    int n, i, menor, posicao = 0;

    do {
        scanf("%d", &n);
    } while (n < 0 || n > 1000);

    int x[n];   
    int *p = x; 

    for (i = 0; i < n; i++) {
        scanf("%d", (p + i)); 

        if (i == 0) menor = *(p + i);
        if (menor > *(p + i)) {
            menor = *(p + i);
            posicao = i;
        }
    }
    printf("Menor valor: %d\n", menor);
    printf("Posicao: %d\n", posicao);

    return 0;
}
