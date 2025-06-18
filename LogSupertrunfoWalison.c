/* Walison Gouvêa de Almeida */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct {
    char estado[3];
    char codigo[10];
    char cidade[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade;
    float pib_per_capita;
} Carta;

void calcular_metricas(Carta *carta) {
    carta->densidade = carta->populacao / carta->area;
    carta->pib_per_capita = carta->pib / carta->populacao;
}

void imprimir_carta(Carta carta) {
    printf("\nCarta: %s (%s)\n", carta.cidade, carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("População: %d habitantes\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f milhões\n", carta.pib);
    printf("Pontos turísticos: %d\n", carta.pontos_turisticos);
    printf("Densidade populacional: %.2f hab/km²\n", carta.densidade);
    printf("PIB per capita: %.2f\n", carta.pib_per_capita);
}

void exibir_menu(int atributos_disponiveis[]) {
    printf("\n=== MENU SUPER TRUNFO ===\n");
    printf("Escolha um atributo para comparação:\n");
    if (atributos_disponiveis[0]) printf("1 - População\n");
    if (atributos_disponiveis[1]) printf("2 - Área\n");
    if (atributos_disponiveis[2]) printf("3 - PIB\n");
    if (atributos_disponiveis[3]) printf("4 - Pontos Turísticos\n");
    if (atributos_disponiveis[4]) printf("5 - Densidade Populacional\n");
    if (atributos_disponiveis[5]) printf("6 - PIB per capita\n");
    printf("0 - Cancelar\n");
    printf("Opção: ");
}

float obter_valor_atributo(Carta carta, int atributo) {
    switch(atributo) {
        case 1: return carta.populacao;
        case 2: return carta.area;
        case 3: return carta.pib;
        case 4: return carta.pontos_turisticos;
        case 5: return carta.densidade;
        case 6: return carta.pib_per_capita;
        default: return 0;
    }
}

char* obter_nome_atributo(int atributo) {
    switch(atributo) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Populacional";
        case 6: return "PIB per capita";
        default: return "Desconhecido";
    }
}

void comparar_com_multiplos_atributos(Carta c1, Carta c2, int atributo1, int atributo2) {
    float valor1_a1 = obter_valor_atributo(c1, atributo1);
    float valor2_a1 = obter_valor_atributo(c2, atributo1);
    float valor1_a2 = obter_valor_atributo(c1, atributo2);
    float valor2_a2 = obter_valor_atributo(c2, atributo2);
    
    // Regras de comparação (densidade é inverso)
    int pontos_c1 = 0, pontos_c2 = 0;
    
    // Comparação do primeiro atributo
    printf("\nComparação 1: %s\n", obter_nome_atributo(atributo1));
    printf("%s: %.2f vs %s: %.2f\n", c1.cidade, valor1_a1, c2.cidade, valor2_a1);
    
    if (atributo1 == 5) { // Densidade (menor vence)
        if (valor1_a1 < valor2_a1) pontos_c1++;
        else if (valor2_a1 < valor1_a1) pontos_c2++;
    } else { // Demais atributos (maior vence)
        if (valor1_a1 > valor2_a1) pontos_c1++;
        else if (valor2_a1 > valor1_a1) pontos_c2++;
    }
    
    // Comparação do segundo atributo
    printf("\nComparação 2: %s\n", obter_nome_atributo(atributo2));
    printf("%s: %.2f vs %s: %.2f\n", c1.cidade, valor1_a2, c2.cidade, valor2_a2);
    
    if (atributo2 == 5) { // Densidade (menor vence)
        if (valor1_a2 < valor2_a2) pontos_c1++;
        else if (valor2_a2 < valor1_a2) pontos_c2++;
    } else { // Demais atributos (maior vence)
        if (valor1_a2 > valor2_a2) pontos_c1++;
        else if (valor2_a2 > valor1_a2) pontos_c2++;
    }
    
    // Soma dos valores para desempate
    float soma_c1 = valor1_a1 + valor1_a2;
    float soma_c2 = valor2_a1 + valor2_a2;
    
    printf("\n=== RESULTADO FINAL ===\n");
    printf("Pontos %s: %d\n", c1.cidade, pontos_c1);
    printf("Pontos %s: %d\n", c2.cidade, pontos_c2);
    printf("Soma dos atributos %s: %.2f\n", c1.cidade, soma_c1);
    printf("Soma dos atributos %s: %.2f\n", c2.cidade, soma_c2);
    
    if (pontos_c1 > pontos_c2) {
        printf("Vencedor: %s (%s)\n", c1.cidade, c1.codigo);
    } else if (pontos_c2 > pontos_c1) {
        printf("Vencedor: %s (%s)\n", c2.cidade, c2.codigo);
    } else {
        if (soma_c1 > soma_c2) {
            printf("Empate! %s vence por soma maior de atributos\n", c1.cidade);
        } else if (soma_c2 > soma_c1) {
            printf("Empate! %s vence por soma maior de atributos\n", c2.cidade);
        } else {
            printf("Empate total! As cartas são equivalentes\n");
        }
    }
}

int main() {
    Carta carta1 = {
        .estado = "SP",
        .codigo = "SP01",
        .cidade = "São Paulo",
        .populacao = 12300000,
        .area = 1521.11,
        .pib = 678.9,
        .pontos_turisticos = 15
    };
    
    Carta carta2 = {
        .estado = "RJ",
        .codigo = "RJ01",
        .cidade = "Rio de Janeiro",
        .populacao = 6776000,
        .area = 1200.27,
        .pib = 345.6,
        .pontos_turisticos = 20
    };
    
    calcular_metricas(&carta1);
    calcular_metricas(&carta2);
    
    printf("=== SUPER TRUNFO - NÍVEL MESTRE ===\n");
    printf("=== Cartas do Jogo ===\n");
    imprimir_carta(carta1);
    imprimir_carta(carta2);
    
    int atributo1 = 0, atributo2 = 0;
    int atributos_disponiveis[6] = {1, 1, 1, 1, 1, 1}; // Todos disponíveis inicialmente
    
    // Escolha do primeiro atributo
    while (atributo1 < 1 || atributo1 > 6) {
        exibir_menu(atributos_disponiveis);
        scanf("%d", &atributo1);
        
        if (atributo1 == 0) {
            printf("Jogo cancelado.\n");
            return 0;
        }
        
        if (atributo1 < 1 || atributo1 > 6 || !atributos_disponiveis[atributo1-1]) {
            printf("Opção inválida ou já selecionada! Tente novamente.\n");
            atributo1 = 0;
        }
    }
    
    atributos_disponiveis[atributo1-1] = 0; // Marca como indisponível
    
    // Escolha do segundo atributo
    while (atributo2 < 1 || atributo2 > 6) {
        printf("\nEscolha o segundo atributo (diferente do primeiro):\n");
        exibir_menu(atributos_disponiveis);
        scanf("%d", &atributo2);
        
        if (atributo2 == 0) {
            printf("Jogo cancelado.\n");
            return 0;
        }
        
        if (atributo2 < 1 || atributo2 > 6 || !atributos_disponiveis[atributo2-1]) {
            printf("Opção inválida ou já selecionada! Tente novamente.\n");
            atributo2 = 0;
        }
    }
    
    printf("\nAtributos selecionados:\n");
    printf("1. %s\n", obter_nome_atributo(atributo1));
    printf("2. %s\n", obter_nome_atributo(atributo2));
    
    comparar_com_multiplos_atributos(carta1, carta2, atributo1, atributo2);
    
    return 0;
}
