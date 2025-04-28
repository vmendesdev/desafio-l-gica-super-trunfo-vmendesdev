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

// Função para calcular a densidade populacional
void calcular_densidade_populacional(Carta* carta) {
    carta->densidade_populacional = carta->populacao / carta->area;
}

// Função para calcular o PIB per capita
void calcular_pib_per_capita(Carta* carta) {
    carta->pib_per_capita = carta->pib / carta->populacao;
}

// Função para comparar as cartas
void comparar_cartas(Carta carta1, Carta carta2, int opcao) {
    switch(opcao) {
        case 1: {
            printf("\nComparacao de Cartas (Populacao)\n");
            printf("Carta 1 - %s: %d habitantes\n", carta1.cidade, carta1.populacao);
            printf("Carta 2 - %s: %d habitantes\n", carta2.cidade, carta2.populacao);
            printf("Resultado: %s\n", (carta1.populacao > carta2.populacao) ? carta1.cidade : (carta2.populacao > carta1.populacao) ? carta2.cidade : "Empate");
            break;
        }

        case 2: {
            printf("\nComparacao de Cartas (Area)\n");
            printf("Carta 1 - %s: %.2f km²\n", carta1.cidade, carta1.area);
            printf("Carta 2 - %s: %.2f km²\n", carta2.cidade, carta2.area);
            printf("Resultado: %s\n", (carta1.area > carta2.area) ? carta1.cidade : (carta2.area > carta1.area) ? carta2.cidade : "Empate");
            break;
        }

        case 3: {
            printf("\nComparacao de Cartas (PIB)\n");
            printf("Carta 1 - %s: %.2f milhoes\n", carta1.cidade, carta1.pib);
            printf("Carta 2 - %s: %.2f milhoes\n", carta2.cidade, carta2.pib);
            printf("Resultado: %s\n", (carta1.pib > carta2.pib) ? carta1.cidade : (carta2.pib > carta1.pib) ? carta2.cidade : "Empate");
            break;
        }

        case 4: {
            printf("\nComparacao de Cartas (Densidade Populacional)\n");
            printf("Carta 1 - %s: %.2f habitantes por km²\n", carta1.cidade, carta1.densidade_populacional);
            printf("Carta 2 - %s: %.2f habitantes por km²\n", carta2.cidade, carta2.densidade_populacional);
            printf("Resultado: %s\n", (carta1.densidade_populacional < carta2.densidade_populacional) ? carta1.cidade : (carta2.densidade_populacional < carta1.densidade_populacional) ? carta2.cidade : "Empate");
            break;
        }

        case 5: {
            printf("\nComparacao de Cartas (PIB per Capita)\n");
            printf("Carta 1 - %s: %.2f\n", carta1.cidade, carta1.pib_per_capita);
            printf("Carta 2 - %s: %.2f\n", carta2.cidade, carta2.pib_per_capita);
            printf("Resultado: %s\n", (carta1.pib_per_capita > carta2.pib_per_capita) ? carta1.cidade : (carta2.pib_per_capita > carta1.pib_per_capita) ? carta2.cidade : "Empate");
            break;
        }

        default:
            printf("Opcao invalida!\n");
    }
}

// Função principal
int main() {
    // Definindo as cartas
    Carta carta1 = {"SP", "001", "Sao Paulo", 12300000, 1500.6, 650000, 100, 0.0, 0.0};
    Carta carta2 = {"RJ", "002", "Rio de Janeiro", 6000000, 1200.5, 450000, 80, 0.0, 0.0};

    // Calculando densidade populacional e PIB per capita
    calcular_densidade_populacional(&carta1);
    calcular_densidade_populacional(&carta2);
    calcular_pib_per_capita(&carta1);
    calcular_pib_per_capita(&carta2);

    int opcao;

    // Menu de comparação
    printf("\nEscolha o atributo para comparar:\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Densidade Populacional\n");
    printf("5 - PIB per Capita\n");
    printf("Opcao: ");
    scanf("%d", &opcao);

    // Chamando a função para comparar as cartas com base no atributo escolhido
    comparar_cartas(carta1, carta2, opcao);

    return 0;
}
