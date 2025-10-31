#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define TAM 8

// Inicializa o tabuleiro
void inicializarTabuleiro(char tabuleiro[TAM][TAM]) {
    char pecasIniciais[8] = {'T', 'C', 'B', 'Q', 'K', 'B', 'C', 'T'};
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (i == 0) tabuleiro[i][j] = pecasIniciais[j];          // Pretas
            else if (i == 1) tabuleiro[i][j] = 'P';                  // Peões pretos
            else if (i == 6) tabuleiro[i][j] = 'p';                  // Peões brancos
            else if (i == 7) tabuleiro[i][j] = pecasIniciais[j] + 32; // Brancas (minúsculas)
            else tabuleiro[i][j] = '.';                              // Espaço vazio
        }
    }
}

// Imprime o tabuleiro
void imprimirTabuleiro(char tabuleiro[TAM][TAM]) {
    printf("\n    A B C D E F G H\n");
    printf("   -----------------\n");
    for (int i = 0; i < TAM; i++) {
        printf("%d | ", 8 - i);
        for (int j = 0; j < TAM; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("|\n");
    }
    printf("   -----------------\n");
}

// Converte letra A-H em índice
int colunaLetraParaIndice(char c) {
    if (c >= 'A' && c <= 'H') return c - 'A';
    if (c >= 'a' && c <= 'h') return c - 'a';
    return -1;
}

// Verifica se o caminho está livre (para torre, bispo e rainha)
int caminhoLivre(char tabuleiro[TAM][TAM], int oL, int oC, int dL, int dC) {
    int passoL = (dL > oL) ? 1 : (dL < oL ? -1 : 0);
    int passoC = (dC > oC) ? 1 : (dC < oC ? -1 : 0);

    int l = oL + passoL;
    int c = oC + passoC;

    while (l != dL || c != dC) {
        if (tabuleiro[l][c] != '.') return 0;
        l += passoL;
        c += passoC;
    }
    return 1;
}

// Verifica se o movimento é válido
int movimentoValido(char tabuleiro[TAM][TAM], int oL, int oC, int dL, int dC) {
    char peca = tabuleiro[oL][oC];
    char destino = tabuleiro[dL][dC];

    // Impede capturar peça da mesma cor
    if ((isupper(peca) && isupper(destino)) || (islower(peca) && islower(destino))) return 0;

    // === PEÃO ===
    if (peca == 'p') { // branco
        if (dC == oC && destino == '.') {
            if (dL == oL - 1) return 1;
            if (oL == 6 && dL == oL - 2 && tabuleiro[oL - 1][oC] == '.') return 1;
        }
        if (abs(dC - oC) == 1 && dL == oL - 1 && destino != '.') return 1;
    }
    else if (peca == 'P') { // preto
        if (dC == oC && destino == '.') {
            if (dL == oL + 1) return 1;
            if (oL == 1 && dL == oL + 2 && tabuleiro[oL + 1][oC] == '.') return 1;
        }
        if (abs(dC - oC) == 1 && dL == oL + 1 && destino != '.') return 1;
    }

    // === TORRE ===
    else if (tolower(peca) == 't') {
        if (oL == dL || oC == dC)
            if (caminhoLivre(tabuleiro, oL, oC, dL, dC)) return 1;
    }

    // === BISPO ===
    else if (tolower(peca) == 'b') {
        if (abs(dL - oL) == abs(dC - oC))
            if (caminhoLivre(tabuleiro, oL, oC, dL, dC)) return 1;
    }

    // === RAINHA ===
    else if (tolower(peca) == 'q') {
        if (oL == dL || oC == dC || abs(dL - oL) == abs(dC - oC))
            if (caminhoLivre(tabuleiro, oL, oC, dL, dC)) return 1;
    }

    // === CAVALO ===
    else if (tolower(peca) == 'c') {
        int deltaL = abs(dL - oL);
        int deltaC = abs(dC - oC);
        if ((deltaL == 2 && deltaC == 1) || (deltaL == 1 && deltaC == 2)) return 1;
    }

    // === REI ===
    else if (tolower(peca) == 'k') {
        if (abs(dL - oL) <= 1 && abs(dC - oC) <= 1) return 1;
    }

    return 0;
}

int main() {
    char tabuleiro[TAM][TAM];
    inicializarTabuleiro(tabuleiro);

    int origemLinha, destinoLinha;
    char origemColuna, destinoColuna;
    int jogadas = 0;
    char continuar;

    printf("=== JOGO DE XADREZ SIMPLIFICADO ===\n");
    printf("Peças válidas: Peão, Torre, Bispo, Rainha, Cavalo e Rei.\n");
    printf("(Maiúsculas = Pretas | Minúsculas = Brancas)\n");

    do {
        imprimirTabuleiro(tabuleiro);
        printf("\nJogada %d\n", ++jogadas);

        printf("De (ex: E2): ");
        scanf(" %c%d", &origemColuna, &origemLinha);
        printf("Para (ex: E4): ");
        scanf(" %c%d", &destinoColuna, &destinoLinha);

        int oL = 8 - origemLinha;
        int oC = colunaLetraParaIndice(origemColuna);
        int dL = 8 - destinoLinha;
        int dC = colunaLetraParaIndice(destinoColuna);

        if (oL < 0 || oL >= TAM || oC < 0 || oC >= TAM || dL < 0 || dL >= TAM || dC < 0 || dC >= TAM) {
            printf("Posição inválida!\n");
        } 
        else if (tabuleiro[oL][oC] == '.') {
            printf("Não há peça nessa posição!\n");
        } 
        else if (!movimentoValido(tabuleiro, oL, oC, dL, dC)) {
            printf("Movimento inválido para essa peça!\n");
        } 
        else {
            printf("Movimento válido! Peça movida.\n");
            tabuleiro[dL][dC] = tabuleiro[oL][oC];
            tabuleiro[oL][oC] = '.';
        }

        printf("\nDeseja continuar (s/n)? ");
        scanf(" %c", &continuar);

    } while (continuar == 's' || continuar == 'S');

    printf("\nJogo encerrado após %d jogadas.\n", jogadas);
    imprimirTabuleiro(tabuleiro);

    return 0;
}
