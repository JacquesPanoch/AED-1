#include <stdio.h>

char mapa[1025][1025];
int visitado[1025][1025];
int filax[1048576], filay[1048576];

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    
    for (int i = 0; i < N; i++) {
        scanf("%s", mapa[i]);
    }
    
    int resposta = 0;
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (mapa[i][j] == '.' && !visitado[i][j]) {
                resposta++;
                int ini = 0, fim = 0;
                filax[fim] = i;
                filay[fim] = j;
                fim++;
                visitado[i][j] = 1;
                
                while (ini < fim) {
                    int x = filax[ini];
                    int y = filay[ini];
                    ini++;
                    
                    for (int d = 0; d < 4; d++) {
                        int nx = x + dx[d];
                        int ny = y + dy[d];
                        
                        if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                            if (mapa[nx][ny] == '.' && !visitado[nx][ny]) {
                                visitado[nx][ny] = 1;
                                filax[fim] = nx;
                                filay[fim] = ny;
                                fim++;
                            }
                        }
                    }
                }
            }
        }
    }
    
    printf("%d\n", resposta);
    return 0;
}
