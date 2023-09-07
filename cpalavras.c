#include <stdio.h>

int main() {
    int linhas, colunas;

    printf("Digite o número de linhas da matriz: ");
    scanf("%d", &linhas);
    printf("Digite o número de colunas da matriz: ");
    scanf("%d", &colunas);

    if (linhas <= 0 || colunas <= 0) {
        printf("Número inválido de linhas ou colunas.\n");
    }
    else {
        char matriz[linhas][colunas];

        char letra = 'A';

        for (int i = 0; i < linhas; i++) {
            for (int j = 0; j < colunas; j++) {
                matriz[i][j] = letra;
            }
        }

        printf("Matriz gerada:\n");
        
        for (int i = 0; i < linhas; i++) {
            for (int j = 0; j < colunas; j++) {
                printf("%c ", matriz[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
