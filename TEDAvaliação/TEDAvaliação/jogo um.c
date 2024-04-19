#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Funcao para obter a escolha do usuario
int obterEscolha() {
    int escolha;
    printf("\nEscolha:\n");
    printf("1. Pedra\n");
    printf("2. Papel\n");
    printf("3. Tesoura\n");
    printf("Digite o numero correspondente a sua escolha: ");
    scanf("%d", &escolha);
    return escolha;
}

// Funcao para determinar o vencedor
void determinarVencedor(int escolhaUsuario, int escolhaComputador) {
    if (escolhaUsuario == escolhaComputador) {
        printf("Empate!\n");
    } else if ((escolhaUsuario == 1 && escolhaComputador == 3) ||
               (escolhaUsuario == 2 && escolhaComputador == 1) ||
               (escolhaUsuario == 3 && escolhaComputador == 2)) {
        printf("Voce venceu!\n");
    } else {
        printf("Voce perdeu!\n");
    }
}

int main() {
    int escolhaUsuario, escolhaComputador;

    printf("Bem-vindo ao jogo Pedra, Papel e Tesoura!\n");

    // Inicializa o gerador de n�meros aleat�rios com base no tempo atual
    srand(time(NULL));

    // Loop principal do jogo
    do {
        escolhaUsuario = obterEscolha();

        // Gera a escolha do computador (n�mero aleat�rio entre 1 e 3)
        escolhaComputador = rand() % 3 + 1;

        // Imprime a escolha do computador
        switch (escolhaComputador) {
            case 1:
                printf("O computador escolheu Pedra.\n");
                break;
            case 2:
                printf("O computador escolheu Papel.\n");
                break;
            case 3:
                printf("O computador escolheu Tesoura.\n");
                break;
        }

        // Determina o vencedor
        determinarVencedor(escolhaUsuario, escolhaComputador);

        // Pergunta se o jogador deseja jogar novamente
        printf("\nDeseja jogar novamente? (1 = Sim, 0 = Nao): ");
        scanf("%d", &escolhaUsuario);
    } while (escolhaUsuario == 1);

    printf("Obrigado por jogar!\n");

    return 0;
}
