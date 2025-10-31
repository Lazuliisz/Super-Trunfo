#include <stdio.h>

#define TAM 8

// ======= Funções recursivas =======

// Torre: percorre a linha e a coluna (sem diagonais)
void movimentosTorre(int x, int y, int i) {
    if (i > TAM) return;
    if (i != x) printf("(%d, %d)\n", i, y);
    movimentosTorre(x, y, i + 1);
}

// Bispo: percorre as diagonais usando recursividade
void movimentosBispo(int x, int y, int dx, int dy) {
    int novoX = x + dx;
    int novoY = y + dy;
    if (novoX < 1 || novoX > TAM || novoY < 1 || novoY > TAM) return;
    printf("(%d, %d)\n", novoX, novoY);
    movimentosBispo(novoX, novoY, dx, dy);
}

// Rainha: combina torre e bispo com recursividade
void movimentosRainha(int x, int y) {
    int i;

    // Torre (vertical e horizontal)
    for (i = 1; i <= TAM; i++) {
        if (i != x) printf("(%d, %d)\n", i, y);
        if (i != y) printf("(%d, %d)\n", x, i);
    }

    // Bispo (recursivo nas 4 diagonais)
    movimentosBispo(x, y, 1, 1);
    movimentosBispo(x, y, 1, -1);
    movimentosBispo(x, y, -1, 1);
    movimentosBispo(x, y, -1, -1);
}

// ======= Função com loops complexos (Cavalo) =======

void movimentosCavalo(int x, int y) {
    printf("\n=== Movimentos do CAVALO (loops complexos) ===\n");

    // Usando dois loops com múltiplas variáveis e condições
    for (int i = -2, j = -1; i <= 2; i++) {
        for (int k = -2, l = 1; k <= 2; k++, l--) {
            // Condição composta: movimento em L (2 em um eixo, 1 em outro)
            if ((i * i + k * k == 5) && (i != 0 && k != 0)) {
                int novoX = x + i;
                int novoY = y + k;
                if (novoX >= 1 && novoX <= TAM && novoY >= 1 && novoY <= TAM) {
                    printf("(%d, %d)\n", novoX, novoY);
                }
            }
        }
    }
}

// ======= Função principal =======

int main() {
    int x, y;

    printf("Tabuleiro 8x8 (posições de 1 a 8)\n");
    printf("Digite a linha inicial da peça: ");
    scanf("%d", &x);
    printf("Digite a coluna inicial da peça: ");
    scanf("%d", &y);

    if (x < 1 || x > 8 || y < 1 || y > 8) {
        printf("Posição inválida!\n");
        return 0;
    }

    printf("\n=== MOVIMENTOS DA TORRE (recursivo) ===\n");
    movimentosTorre(x, y, 1);

    printf("\n=== MOVIMENTOS DO BISPO (recursivo e com dois eixos) ===\n");
    movimentosBispo(x, y, 1, 1);
    movimentosBispo(x, y, 1, -1);
    movimentosBispo(x, y, -1, 1);
    movimentosBispo(x, y, -1, -1);

    printf("\n=== MOVIMENTOS DA RAINHA (recursivo + loops) ===\n");
    movimentosRainha(x, y);

    movimentosCavalo(x, y);

    return 0;
}
