#include <stdio.h>
#include <string.h>

// Definicao da estrutura de carta
typedef struct {
    char estado[30];
    char codigo[10];
    char cidade[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
} Carta;

// Funcao para calcular a densidade populacional
void calcular_densidade_populacional(Carta* carta) {
    carta->densidade_populacional = carta->populacao / carta->area;
}

// Funcao para calcular o PIB per capita
void calcular_pib_per_capita(Carta* carta) {
    carta->pib_per_capita = carta->pib / carta->populacao;
}

// Funcao principal
int main() {
    Carta carta1 = {"SP", "001", "Sao Paulo", 12300000, 1500.6, 650000, 100, 0.0, 0.0};
    Carta carta2 = {"RJ", "002", "Rio de Janeiro", 6000000, 1200.5, 450000, 80, 0.0, 0.0};

    // Calcular Densidade Populacional e PIB per Capita
    calcular_densidade_populacional(&carta1);
    calcular_densidade_populacional(&carta2);
    calcular_pib_per_capita(&carta1);
    calcular_pib_per_capita(&carta2);

    int opcao;

    // Menu de comparacao
    printf("\nEscolha o atributo para comparar:\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Densidade Populacional\n");
    printf("5 - PIB per Capita\n");
    printf("Opcao: ");
    scanf("%d", &opcao);

    // Comparacao baseada no atributo escolhido
    switch(opcao) {
        case 1:
            printf("\nComparacao de Cartas (Populacao)\n");
            printf("Carta 1 - %s: %d habitantes\n", carta1.cidade, carta1.populacao);
            printf("Carta 2 - %s: %d habitantes\n", carta2.cidade, carta2.populacao);
            if (carta1.populacao > carta2.populacao) {
                printf("Resultado: Carta 1 (%s) venceu!\n", carta1.cidade);
            } else if (carta2.populacao > carta1.populacao) {
                printf("Resultado: Carta 2 (%s) venceu!\n", carta2.cidade);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 2:
            printf("\nComparacao de Cartas (Area)\n");
            printf("Carta 1 - %s: %.2f km²\n", carta1.cidade, carta1.area);
            printf("Carta 2 - %s: %.2f km²\n", carta2.cidade, carta2.area);
            if (carta1.area > carta2.area) {
                printf("Resultado: Carta 1 (%s) venceu!\n", carta1.cidade);
            } else if (carta2.area > carta1.area) {
                printf("Resultado: Carta 2 (%s) venceu!\n", carta2.cidade);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 3:
            printf("\nComparacao de Cartas (PIB)\n");
            printf("Carta 1 - %s: %.2f milhoes\n", carta1.cidade, carta1.pib);
            printf("Carta 2 - %s: %.2f milhoes\n", carta2.cidade, carta2.pib);
            if (carta1.pib > carta2.pib) {
                printf("Resultado: Carta 1 (%s) venceu!\n", carta1.cidade);
            } else if (carta2.pib > carta1.pib) {
                printf("Resultado: Carta 2 (%s) venceu!\n", carta2.cidade);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 4:
            printf("\nComparacao de Cartas (Densidade Populacional)\n");
            printf("Carta 1 - %s: %.2f habitantes por km²\n", carta1.cidade, carta1.densidade_populacional);
            printf("Carta 2 - %s: %.2f habitantes por km²\n", carta2.cidade, carta2.densidade_populacional);
            if (carta1.densidade_populacional < carta2.densidade_populacional) {
                printf("Resultado: Carta 1 (%s) venceu!\n", carta1.cidade);
            } else if (carta2.densidade_populacional < carta1.densidade_populacional) {
                printf("Resultado: Carta 2 (%s) venceu!\n", carta2.cidade);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        case 5:
            printf("\nComparacao de Cartas (PIB per Capita)\n");
            printf("Carta 1 - %s: %.2f\n", carta1.cidade, carta1.pib_per_capita);
            printf("Carta 2 - %s: %.2f\n", carta2.cidade, carta2.pib_per_capita);
            if (carta1.pib_per_capita > carta2.pib_per_capita) {
                printf("Resultado: Carta 1 (%s) venceu!\n", carta1.cidade);
            } else if (carta2.pib_per_capita > carta1.pib_per_capita) {
                printf("Resultado: Carta 2 (%s) venceu!\n", carta2.cidade);
            } else {
                printf("Resultado: Empate!\n");
            }
            break;

        default:
            printf("Opcao invalida!\n");
    }

    return 0;
}
