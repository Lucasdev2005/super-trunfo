#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Estrutura da carta
typedef struct {
    char name[30];
    int strength;
    int speed;
    int intelligence;
    int defense;
} Card;

// Função para exibir uma carta
void showCard(Card card) {
    printf("\n===== %s =====\n", card.name);
    printf("Força: %d\n", card.strength);
    printf("Velocidade: %d\n", card.speed);
    printf("Inteligência: %d\n", card.intelligence);
    printf("Defesa: %d\n", card.defense);
}

// Função para comparar atributos
int compareCards(Card player, Card computer, int attribute) {
    switch (attribute) {
        case 1: return player.strength - computer.strength;
        case 2: return player.speed - computer.speed;
        case 3: return player.intelligence - computer.intelligence;
        case 4: return player.defense - computer.defense;
        default: return 0;
    }
}

int main() {
    srand(time(NULL));

    // Criação do baralho
    Card deck[] = {
        {"Dragão Vermelho", 95, 60, 40, 90},
        {"Cavaleiro Negro", 80, 70, 65, 75},
        {"Elfo da Floresta", 60, 90, 85, 50},
        {"Gigante de Pedra", 85, 30, 25, 100},
        {"Feiticeiro Ancião", 50, 40, 95, 60},
        {"Orc Selvagem", 88, 55, 35, 70},
        {"Grifo Dourado", 78, 85, 55, 80},
        {"Fênix Flamejante", 90, 95, 80, 70}
    };
    int totalCards = sizeof(deck) / sizeof(deck[0]);

    // Sorteia cartas para o jogador e o computador
    int playerIndex = rand() % totalCards;
    int computerIndex;
    do {
        computerIndex = rand() % totalCards;
    } while (computerIndex == playerIndex);

    Card playerCard = deck[playerIndex];
    Card computerCard = deck[computerIndex];

    printf("=== SUPER TRUNFO ===\n");
    printf("Sua carta:");
    showCard(playerCard);

    // Escolha do atributo
    int attribute;
    printf("\nEscolha o atributo para competir:\n");
    printf("1 - Força\n");
    printf("2 - Velocidade\n");
    printf("3 - Inteligência\n");
    printf("4 - Defesa\n");
    printf("Opção: ");
    scanf("%d", &attribute);

    // Exibe a carta do computador
    printf("\nCarta do computador:");
    showCard(computerCard);

    // Compara e exibe o resultado
    int result = compareCards(playerCard, computerCard, attribute);
    if (result > 0) {
        printf("\n✅ Você venceu esta rodada!\n");
    } else if (result < 0) {
        printf("\n❌ Você perdeu esta rodada!\n");
    } else {
        printf("\n🤝 Empate!\n");
    }

    printf("\nFim de jogo!\n");
    return 0;
}
