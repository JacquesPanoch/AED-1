#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char palavras[5005][205];
int total = 0;

void insere(char *pal) {
    for (int i = 0; i < total; i++) {
        if (strcmp(pal, palavras[i]) == 0) return;
    }
    strcpy(palavras[total], pal);
    total++;
}

int comparar(const void *a, const void *b) {
    return strcmp((char*)a, (char*)b);
}

int main() {
    char linha[205];
    while (fgets(linha, 205, stdin) != NULL) {
        int i = 0;
        while (linha[i] != '\0') {
            if (isalpha(linha[i])) {
                char palavra[205];
                int j = 0;
                while (isalpha(linha[i])) {
                    palavra[j++] = tolower(linha[i]);
                    i++;
                }
                palavra[j] = '\0';
                insere(palavra);
            } else {
                i++;
            }
        }
    }
    qsort(palavras, total, 205, comparar);
    for (int i = 0; i < total; i++) {
        printf("%s\n", palavras[i]);
    }
    return 0;
}
