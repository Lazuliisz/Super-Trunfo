#include <stdio.h>

#define TAM 8

int main() {
    int x, y; // posição inicial (linha e coluna)
    int i, j;

    printf("Tabuleiro 8x8 (posições de 1 a 8)\n");
    printf("Digite a linha inicial da peça (1-8): ");
    scanf("%d", &x);
    printf("Digite a coluna inicial da peça (1-8): ");
    scanf("%d", &y);

    if (x < 1 || x > 8 || y < 1 || y > 8) {
        printf("Posição inválida!\n");
        return 0;
    }

    printf("\n=== Movimentos da TORRE (usando do...while) ===\n");
    i = 1;
    do {
        if (i != x) printf("(%d, %d)\n", i, y); // mesma coluna
        i++;
    } while (i <= TAM);

    i = 1;
    do {
        if (i != y) printf("(%d, %d)\n", x, i); // mesma linha
        i++;
    } while (i <= TAM);

    printf("\n=== Movimentos do BISPO (usando while) ===\n");
    int dx, dy;

    // Diagonal superior-esquerda
    dx = x - 1;
    dy = y - 1;
    while (dx >= 1 && dy >= 1) {
        printf("(%d, %d)\n", dx, dy);
        dx--; dy--;
    }

    // Diagonal superior-direita
    dx = x - 1;
    dy = y + 1;
    while (dx >= 1 && dy <= TAM) {
        printf("(%d, %d)\n", dx, dy);
        dx--; dy++;
    }

    // Diagonal inferior-esquerda
    dx = x + 1;
    dy = y - 1;
    while (dx <= TAM && dy >= 1) {
        printf("(%d, %d)\n", dx, dy);
        dx++; dy--;
    }

    // Diagonal inferior-direita
    dx = x + 1;
    dy = y + 1;
    while (dx <= TAM && dy <= TAM) {
        printf("(%d, %d)\n", dx, dy);
        dx++; dy++;
    }

    printf("\n=== Movimentos da RAINHA (usando for) ===\n");
    for (i = 1; i <= TAM; i++) {
        for (j = 1; j <= TAM; j++) {
            // A rainha combina torre + bispo
            if ((i == x || j == y || (i - j == x - y) || (i + j == x + y)) &&
                !(i == x && j == y)) {
                printf("(%d, %d)\n", i, j);
            }
        }
    }

    return 0;
}
