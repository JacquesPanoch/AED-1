#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char strings[100000][101];
int total = 0;

int comparar(const void *a, const void *b) {
    return strcmp((char*)a, (char*)b);
}

int main() {
    while (scanf("%s", strings[total]) != EOF) {
        total++;
    }
    
    qsort(strings, total, 101, comparar);
    
    int distintas = 0;
    if (total > 0) distintas = 1;
    for (int i = 1; i < total; i++) {
        if (strcmp(strings[i], strings[i-1]) != 0) {
            distintas++;
        }
    }
    
    printf("%d\n", distintas);
    
    return 0;
}
