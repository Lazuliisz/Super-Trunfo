#include <stdio.h>
#include <string.h>

#define MAX 50

// Estrutura da cidade
typedef struct {
    char estado[MAX];
    int codigo;
    char nome[MAX];
    long populacao;
    double pib;
    double area;
    int pontosTuristicos;

    // calculados
    double densidade;
    double pibPerCapita;
    double superPoder;
} Cidade;

// Função para ler dados de uma cidade
void lerCidade(Cidade *c) {
    printf("Digite o estado: ");
    scanf(" %[^\n]", c->estado);

    printf("Digite o codigo da cidade: ");
    scanf("%d", &c->codigo);

    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", c->nome);

    printf("Digite a populacao: ");
    scanf("%ld", &c->populacao);

    printf("Digite o PIB (em milhoes): ");
    scanf("%lf", &c->pib);

    printf("Digite a area (km²): ");
    scanf("%lf", &c->area);

    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &c->pontosTuristicos);

    // Cálculos
    c->densidade = (c->area > 0) ? ((double)c->populacao / c->area) : 0;
    c->pibPerCapita = (c->populacao > 0) ? (c->pib * 1000000.0 / c->populacao) : 0; 
    c->superPoder = c->populacao + c->pib + c->area + c->pontosTuristicos 
                  + c->pibPerCapita + c->densidade;
}


// Função para comparar duas cidades com base em dois atributos
void comparar(Cidade c1, Cidade c2, int escolha1, int escolha2) {
    printf("\n--- Comparando %s e %s ---\n", c1.nome, c2.nome);

    float pontuacaoC1 = 0, pontuacaoC2 = 0;

    // PRIMEIRA ESCOLHA
    switch (escolha1) {
        case 1:
            if (c1.populacao > c2.populacao)
                pontuacaoC1++;
            else if (c1.populacao < c2.populacao)
                pontuacaoC2++;
            break;
        case 2:
            if (c1.pib > c2.pib)
                pontuacaoC1++;
            else if (c1.pib < c2.pib)
                pontuacaoC2++;
            break;
        case 3:
            if (c1.area > c2.area)
                pontuacaoC1++;
            else if (c1.area < c2.area)
                pontuacaoC2++;
            break;
        case 4:
            if (c1.pontosTuristicos > c2.pontosTuristicos)
                pontuacaoC1++;
            else if (c1.pontosTuristicos < c2.pontosTuristicos)
                pontuacaoC2++;
            break;
        case 5:
            if (c1.pibPerCapita > c2.pibPerCapita)
                pontuacaoC1++;
            else if (c1.pibPerCapita < c2.pibPerCapita)
                pontuacaoC2++;
            break;
        case 6:
            if (c1.densidade < c2.densidade)
                pontuacaoC1++;
            else if (c1.densidade > c2.densidade)
                pontuacaoC2++;
            break;
        case 7:
            if (c1.superPoder > c2.superPoder)
                pontuacaoC1++;
            else if (c1.superPoder < c2.superPoder)
                pontuacaoC2++;
            break;
        default:
            printf("Opcao 1 invalida!\n");
    }

    // SEGUNDA ESCOLHA
    switch (escolha2) {
        case 1:
            if (c1.populacao > c2.populacao)
                pontuacaoC1++;
            else if (c1.populacao < c2.populacao)
                pontuacaoC2++;
            break;
        case 2:
            if (c1.pib > c2.pib)
                pontuacaoC1++;
            else if (c1.pib < c2.pib)
                pontuacaoC2++;
            break;
        case 3:
            if (c1.area > c2.area)
                pontuacaoC1++;
            else if (c1.area < c2.area)
                pontuacaoC2++;
            break;
        case 4:
            if (c1.pontosTuristicos > c2.pontosTuristicos)
                pontuacaoC1++;
            else if (c1.pontosTuristicos < c2.pontosTuristicos)
                pontuacaoC2++;
            break;
        case 5:
            if (c1.pibPerCapita > c2.pibPerCapita)
                pontuacaoC1++;
            else if (c1.pibPerCapita < c2.pibPerCapita)
                pontuacaoC2++;
            break;
        case 6:
            if (c1.densidade < c2.densidade)
                pontuacaoC1++;
            else if (c1.densidade > c2.densidade)
                pontuacaoC2++;
            break;
        case 7:
            if (c1.superPoder > c2.superPoder)
                pontuacaoC1++;
            else if (c1.superPoder < c2.superPoder)
                pontuacaoC2++;
            break;
        default:
            printf("Opcao 2 invalida!\n");
    }

    // RESULTADO FINAL
    printf("\n--- Resultado Final ---\n");
    if (pontuacaoC1 > pontuacaoC2) {
        printf("%s venceu com %.0f pontos!\n", c1.nome, pontuacaoC1);
    } else if (pontuacaoC2 > pontuacaoC1) {
        printf("%s venceu com %.0f pontos!\n", c2.nome, pontuacaoC2);
    } else {
        printf("Empate! Ambas as cidades obtiveram %.0f pontos!\n", pontuacaoC1);
    }
}



int main() {
    Cidade c1, c2;
    int escolha;

    printf("=== Cadastro da Cidade 1 ===\n");
    lerCidade(&c1);

    printf("\n=== Cadastro da Cidade 2 ===\n");
    lerCidade(&c2);

    printf("\nEscolha o atributo para comparar:\n");
    printf("1 - Populacao\n");
    printf("2 - PIB\n");
    printf("3 - Area\n");
    printf("4 - Pontos Turisticos\n");
    printf("5 - PIB per capita\n");
    printf("6 - Densidade populacional (vence a menor)\n");
    printf("7 - Super poder\n");
    printf("Opcao: ");
    scanf("%d", &escolha);

    comparar(c1, c2, escolha);

    return 0;
}
