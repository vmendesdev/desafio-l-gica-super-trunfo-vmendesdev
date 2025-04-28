#include <stdio.h>

// Definição da estrutura para a carta
typedef struct {
    char estado[50];
    char codigo[10];
    char cidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
} Carta;

int main() {
    Carta carta1, carta2;

    // Cadastro da carta 1
    printf("Cadastro da Carta 1\n");
    printf("Estado: ");
    fgets(carta1.estado, sizeof(carta1.estado), stdin);
    printf("Codigo da Carta: ");
    fgets(carta1.codigo, sizeof(carta1.codigo), stdin);
    printf("Nome da Cidade: ");
    fgets(carta1.cidade, sizeof(carta1.cidade), stdin);
    printf("Populacao: ");
    scanf("%d", &carta1.populacao);
    printf("Área (em km quadrados): ");
    scanf("%f", &carta1.area);
    printf("PIB (em milhoes R$): ");
    scanf("%f", &carta1.pib);
    printf("Numero de Pontos Turisticos: ");
    scanf("%d", &carta1.pontosTuristicos);
    
    // Cálculo dos indicadores
    carta1.densidadePopulacional = carta1.populacao / carta1.area;
    carta1.pibPerCapita = carta1.pib / carta1.populacao;

    getchar(); // Limpar buffer

    // Cadastro da carta 2
    printf("\nCadastro da Carta 2\n");
    printf("Estado: ");
    fgets(carta2.estado, sizeof(carta2.estado), stdin);
    printf("Código da Carta: ");
    fgets(carta2.codigo, sizeof(carta2.codigo), stdin);
    printf("Nome da Cidade: ");
    fgets(carta2.cidade, sizeof(carta2.cidade), stdin);
    printf("População: ");
    scanf("%d", &carta2.populacao);
    printf("Área (em km²): ");
    scanf("%f", &carta2.area);
    printf("PIB (em milhões R$): ");
    scanf("%f", &carta2.pib);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &carta2.pontosTuristicos);

    // Cálculo dos indicadores
    carta2.densidadePopulacional = carta2.populacao / carta2.area;
    carta2.pibPerCapita = carta2.pib / carta2.populacao;

    // Comparação (exemplo usando População)
    printf("\nComparação de Cartas (Atributo: População)\n");
    printf("Carta 1 - %s: %d habitantes\n", carta1.cidade, carta1.populacao);
    printf("Carta 2 - %s: %d habitantes\n", carta2.cidade, carta2.populacao);

    if (carta1.populacao > carta2.populacao) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.cidade);
    } else if (carta2.populacao > carta1.populacao) {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.cidade);
    } else {
        printf("Resultado: Empate!\n");
    }

    return 0;
}
