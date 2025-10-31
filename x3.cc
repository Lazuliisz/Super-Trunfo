#include <stdio.h>

#define TAM 8

int main() {
    int x, y; // posição inicial
    int i, j;

    printf("Tabuleiro 8x8 (posições de 1 a 8)\n");
    printf("Digite a linha inicial do cavalo (1-8): ");
    scanf("%d", &x);
    printf("Digite a coluna inicial do cavalo (1-8): ");
    scanf("%d", &y);

    if (x < 1 || x > 8 || y < 1 || y > 8) {
        printf("Posição inválida!\n");
        return 0;
    }

    printf("\n=== Movimentos do CAVALO (usando for e do...while aninhados) ===\n");

    int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
    int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

    // Loop externo com FOR
    for (i = 0; i < 8; i++) {
        j = 0;
        // Loop interno com DO...WHILE
        do {
            int novoX = x + dx[i];
            int novoY = y + dy[i];
            if (novoX >= 1 && novoX <= TAM && novoY >= 1 && novoY <= TAM) {
                printf("(%d, %d)\n", novoX, novoY);
            }
            j++; // só para demonstrar o uso do do...while (1 repetição por iteração)
        } while (j < 1);
    }

    return 0;
}
