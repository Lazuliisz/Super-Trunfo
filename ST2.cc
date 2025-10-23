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

    c->densidade = (c->area > 0) ? ((double)c->populacao / c->area) : 0;
    c->pibPerCapita = (c->populacao > 0) ? (c->pib * 1000000.0 / c->populacao) : 0;
    c->superPoder = c->populacao + c->pib + c->area + c->pontosTuristicos
                  + c->pibPerCapita + c->densidade;
}

// Função para comparar duas cidades com base em um atributo
void comparar(Cidade c1, Cidade c2, int escolha) {
    printf("\n--- Comparando %s e %s ---\n", c1.nome, c2.nome);

    if (escolha == 1) {
        if (c1.populacao > c2.populacao) {
            printf("População: %s venceu!\n", c1.nome);
        } else {
            if (c1.populacao < c2.populacao) {
                printf("População: %s venceu!\n", c2.nome);
            } else {
                printf("População: empate!\n");
            }
        }
    } else {
        if (escolha == 2) {
            if (c1.pib > c2.pib) {
                printf("PIB: %s venceu!\n", c1.nome);
            } else {
                if (c1.pib < c2.pib) {
                    printf("PIB: %s venceu!\n", c2.nome);
                } else {
                    printf("PIB: empate!\n");
                }
            }
        } else {
            if (escolha == 3) {
                if (c1.area > c2.area) {
                    printf("Área: %s venceu!\n", c1.nome);
                } else {
                    if (c1.area < c2.area) {
                        printf("Área: %s venceu!\n", c2.nome);
                    } else {
                        printf("Área: empate!\n");
                    }
                }
            } else {
                if (escolha == 4) {
                    if (c1.pontosTuristicos > c2.pontosTuristicos) {
                        printf("Pontos Turísticos: %s venceu!\n", c1.nome);
                    } else {
                        if (c1.pontosTuristicos < c2.pontosTuristicos) {
                            printf("Pontos Turísticos: %s venceu!\n", c2.nome);
                        } else {
                            printf("Pontos Turísticos: empate!\n");
                        }
                    }
                } else {
                    if (escolha == 5) {
                        if (c1.pibPerCapita > c2.pibPerCapita) {
                            printf("PIB per capita: %s venceu!\n", c1.nome);
                        } else {
                            if (c1.pibPerCapita < c2.pibPerCapita) {
                                printf("PIB per capita: %s venceu!\n", c2.nome);
                            } else {
                                printf("PIB per capita: empate!\n");
                            }
                        }
                    } else {
                        if (escolha == 6) {
                            if (c1.densidade < c2.densidade) {
                                printf("Densidade populacional: %s venceu!\n", c1.nome);
                            } else {
                                if (c1.densidade > c2.densidade) {
                                    printf("Densidade populacional: %s venceu!\n", c2.nome);
                                } else {
                                    printf("Densidade populacional: empate!\n");
                                }
                            }
                        } else {
                            if (escolha == 7) {
                                if (c1.superPoder > c2.superPoder) {
                                    printf("Super poder: %s venceu!\n", c1.nome);
                                } else {
                                    if (c1.superPoder < c2.superPoder) {
                                        printf("Super poder: %s venceu!\n", c2.nome);
                                    } else {
                                        printf("Super poder: empate!\n");
                                    }
                                }
                            } else {
                                printf("Opção inválida!\n");
                            }
                        }
                    }
                }
            }
        }
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
