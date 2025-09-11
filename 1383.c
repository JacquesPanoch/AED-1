#include <stdio.h>

void ler_matriz(int matriz[9][9]){
    for(int i = 0; i < 9; i++)
        for(int j = 0; j < 9; j++)
            scanf("%d", &matriz[i][j]);
}

int valida_linha(int matriz[9][9]){
    for(int i = 0; i < 9; i++){
        int freq[10] = {0};
        for(int j = 0; j < 9; j++){
            int v = matriz[i][j];
            if(v < 1 || v > 9) return 0;
            freq[v]++;
        }
        for(int k = 1; k <= 9; k++)
            if(freq[k] != 1) return 0;
    }
    return 1;
}

int valida_coluna(int matriz[9][9]){
    for(int j = 0; j < 9; j++){
        int freq[10] = {0};
        for(int i = 0; i < 9; i++){
            int v = matriz[i][j];
            if(v < 1 || v > 9) return 0;
            freq[v]++;
        }
        for(int k = 1; k <= 9; k++)
            if(freq[k] != 1) return 0;
    }
    return 1;
}

int valida_quadrado(int matriz[9][9]){
    for(int l = 0; l < 9; l += 3)
        for(int c = 0; c < 9; c += 3){
            int freq[10] = {0};
            for(int i = l; i < l+3; i++)
                for(int j = c; j < c+3; j++){
                    int v = matriz[i][j];
                    if(v < 1 || v > 9) return 0;
                    freq[v]++;
                }
            for(int k = 1; k <= 9; k++)
                if(freq[k] != 1) return 0;
        }
    return 1;
}

int main(){
    int n, matriz[9][9];
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        if(i > 1) printf("\n");
        ler_matriz(matriz);
        printf("Instancia %d\n", i);
        if(valida_linha(matriz) && valida_coluna(matriz) && valida_quadrado(matriz)){
            printf("SIM\n");
        }else{
            printf("NAO\n");
        }
        if(i==n){
            printf("\n");
        }
    }
    return 0;
}
