#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <time.h>

#define MAX_TENTATIVAS 6
#define TAMANHO_PALAVRA 20

int numeroAleatorio, tentativa, tentativasRestantes = 5;
int escolhaUsuario, escolhaComputador;
int escolha,obterEscolha;

void escolhaDeJogo(int op){

    switch(op){

        case 1:
            jogo1();
            redirecionadorDeRetorno();
            break;

        case 2:
            system("cls");
            jogo2();
            break;

        case 3:
            jogo3();
            redirecionadorDeRetorno();
            break;

        case 0:
            redirecionadorDeEncerramento();
            break;

        default:
            system("cls");
            redirecionadorDeInvalido();
            break;
    }
}


void jogo1() {
    int numeroAleatorio, tentativa, tentativasRestantes = 5;

    do {
            //Inicializando o gerador de numeros aleatorios com base no tempo atual
            srand(time(NULL));
            // Gerando um numero aleatorio entre 1 e 100
            numeroAleatorio = rand() % 100 + 1;
            system("cls");
            printf("===============================\n");
            printf("Bem-vindo ao jogo de adivinhacao!\n");
            printf("Tente adivinhar o numero secreto entre 1 e 100.\n");
            printf("===============================\n");
            // Loop do jogo
            do {
            printf("Voce tem %d tentativas restantes.\n", tentativasRestantes);
            printf("Digite seu palpite: ");
            scanf("%d", &tentativa);
            // Verificando o palpite do jogador
            if (tentativa > numeroAleatorio) {
                printf("Tente um numero menor.\n");
            } else if (tentativa < numeroAleatorio) {
                printf("Tente um numero maior.\n");
            } else {
                system("cls");
                printf("====================================================\n");
                printf("Parabens! Voce adivinhou o numero secreto %d!\n", numeroAleatorio);
                printf("====================================================\n");
                break; // Sai do loop do jogo
            }

        tentativasRestantes--;
    } while (tentativasRestantes > 0);

    // Se o jogador esgotar todas as tentativas sem adivinhar o numero
    if (tentativasRestantes == 0) {
            system("cls");
        printf("====================================================\n");
        printf("Suas tentativas acabaram. O numero secreto era %d.\n", numeroAleatorio);
        printf("====================================================\n");
    }

        // Pergunta se o jogador deseja jogar novamente
        printf("\nDeseja jogar novamente? (1 = Sim, 0 = Nao): ");
        scanf("%d", &escolhaUsuario);
         tentativasRestantes=5;;
        } while (escolhaUsuario == 1);

        //pergunta se deseja voltar ao menu principal
        system("cls");
    redirecionadorDeRetorno();
}


void imprimirForca(int tentativasRestantes) {
    system("cls");
    printf("\n");
    printf("  +---+\n");
    printf("  |   |\n");

    if (tentativasRestantes < MAX_TENTATIVAS)
        printf("  |   O\n");
    else
        printf("  |\n");

    if (tentativasRestantes < MAX_TENTATIVAS - 1)
        printf("  |   |\n");
    else if (tentativasRestantes < MAX_TENTATIVAS)
        printf("  |  /|\n");
    else
        printf("  |\n");

    if (tentativasRestantes < MAX_TENTATIVAS - 3)
        printf("  |  / ");
    else if (tentativasRestantes < MAX_TENTATIVAS - 2)
        printf("  |  /|");
    else if (tentativasRestantes < MAX_TENTATIVAS - 1)
        printf("  |  /|\\");
    else if (tentativasRestantes < MAX_TENTATIVAS)
        printf("  |  /|\\");
    else
        printf("  |\n");

    printf("  |\n");
    printf("======\n\n");
}

// Função para verificar se uma letra está presente na palavra
int verificarLetra(char letra, char palavra[], char palavraEscondida[]) {
    int i, encontrou = 0;
    for (i = 0; i < strlen(palavra); i++) {
        if (tolower(letra) == tolower(palavra[i])) {
            palavraEscondida[i] = palavra[i];
            encontrou = 1;
        }
    }
    return encontrou;
}

void jogo2() {
    char palavra[TAMANHO_PALAVRA];
    char palavraEscondida[TAMANHO_PALAVRA];
    char letra;
    int tentativasRestantes = MAX_TENTATIVAS;
    int palavraRevelada = 0;

    // Solicita ao jogador a palavra a ser adivinhada
    printf("Digite a palavra para o jogo da forca (sem espacos, com no maximo %d caracteres): ", TAMANHO_PALAVRA - 1);
    scanf("%s", palavra);
    system("cls");
    // Inicializa a palavra escondida com "-"
    memset(palavraEscondida, '-', strlen(palavra));
    palavraEscondida[strlen(palavra)] = '\0';

    // Loop principal do jogo
    while (tentativasRestantes > 0 && !palavraRevelada) {
        printf("\nPalavra: %s\n", palavraEscondida);
        printf("Tentativas restantes: %d\n", tentativasRestantes);

        printf("Digite uma letra: ");
        scanf(" %c", &letra);

        // Verifica se a letra já foi tentada
        if (strchr(palavraEscondida, tolower(letra)) != NULL) {
            printf("Você já tentou esta letra. Tente outra.\n");
            continue;
        }

        // Verifica se a letra está presente na palavra
        if (verificarLetra(letra, palavra, palavraEscondida)) {
            printf("Letra correta!\n");

            // Verifica se todas as letras foram adivinhadas
            if (strcmp(palavra, palavraEscondida) == 0) {
                palavraRevelada = 1;
            }
        } else {
            printf("Letra incorreta.\n");
            tentativasRestantes--;
        }

        // Imprime a forca
        imprimirForca(tentativasRestantes);
    }

    // Verifica se o jogador venceu ou perdeu
    if (palavraRevelada) {
        printf("\nParabens! Voce adivinhou a palavra \"%s\"!\n", palavra);
    } else {
        printf("\nVoce perdeu! A palavra era \"%s\".\n", palavra);
    }
}



int obterEscolhaJokenpo() {
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

void jogo3() {

    int escolhaUsuario, escolhaComputador;

    printf("Bem-vindo ao jogo Pedra, Papel e Tesoura!\n");

    // Inicializa o gerador de n�meros aleat�rios com base no tempo atual
    srand(time(NULL));

    // Loop principal do jogo
    do {
        escolhaUsuario = obterEscolhaJokenpo();

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
}


void redirecionadorDeRetorno() {
    int Retur;
    printf("============================================\n");
    printf("Deseja retornar ao menu principal?\n");
    printf("1 - Sim\n");
    printf("2 - Nao\n");
    printf("Escolha um numero:");
    scanf("%d", &Retur);
    if (Retur == 1) {
        system("cls");
        main();
    } else if (Retur == 2) {
        system("cls");
        printf("=============================\n");
        printf("Programa encerrado.\n");
        printf("=============================\n");
        exit(0);
    } else {
        system("cls");
        redirecionadorDeInvalido();
    }
}

void redirecionadorDeInvalido(){
    int inval;
    printf("============================================\n");
    printf("Sua opcao foi invalida\n");
    printf("deseja retornar para o menu principal?\n");
    printf("1 - Sim\n");
    printf("2 - Nao\n");
    printf("Escolha um numero:");
    scanf("%d", &inval);
        if (inval == 1) {
        system("cls");
        return main();
    } else if (inval == 2) {
        system("cls");
        printf("===============================\n");
        printf("Programa encerrado.\n");
        printf("===============================\n");
        exit(0);
    } else {
        system("cls");
        redirecionadorDeInvalido();
    }
}

void redirecionadorDeEncerramento() {
    int Retur;
    system("cls");
    printf("============================================\n");
    printf("Deseja encerrar o programa?\n");
    printf("1 - Sim\n");
    printf("2 - Nao\n");
    printf("Escolha um numero:");
    scanf("%d", &Retur);
    if (Retur == 1) {system("cls");
        printf("=============================\n");
        printf("Programa encerrado.\n");
        printf("=============================\n");
        exit(0);

    } else if (Retur == 2) {
        system("cls");
        main();
    } else {
        system("cls");
        redirecionadorDeInvalido();
    }
}

int main(){
    int op;
    printf("            SEJA BEM VINDO\n");
    printf("=========================================\n");
    printf("Qual dos jogos deseja jogar?\n");
    printf("\n");
    printf("1-AdvinhaNumero 2-forca 3-Jokenpo 0-Sair do programa\n");
    printf("escolha um numero: ");
    scanf("%d", &op);
    escolhaDeJogo(op);
    return 0;
}
