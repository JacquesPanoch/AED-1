#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int NC;
    scanf("%d", &NC);

    while (NC--) {
        int N;
        scanf("%d", &N);
        int *v = malloc(N * sizeof(int));

        for (int i = 0; i < N; i++)
            scanf("%d", &v[i]);

        qsort(v, N, sizeof(int), cmp);

        for (int i = 0; i < N; i++) {
            if (i) printf(" ");
            printf("%d", v[i]);
        }
        printf("\n");

        free(v);
    }
    return 0;
}
