#include <stdio.h>

int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    int N;
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++) {
        int F1, F2;
        scanf("%d %d", &F1, &F2);
        printf("%d\n", gcd(F1, F2));
    }
    
    return 0;
}
