#include <stdio.h>
 
int main() {
 
    int n, i, menor, posicao = 0;
    do{
        scanf("%d", &n);
    }while(n<0 || n>1000);

    int x[n];

    for(i=0;i<n;i++){
        scanf("%d", &x[i]);
        if(i==0) menor = x[i];
        if (menor > x[i]){
            menor = x[i];
            posicao = i;
        }
    }
    printf("Menor valor: %d\n", menor);
    printf("Posicao: %d\n", posicao);
 
    return 0;
}
