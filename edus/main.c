#include <stdio.h>
#include <stdlib.h>

int main() {

    int matriz[5][5];
    int contador = 1;
    int maior;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matriz[i][j] = contador;
            contador++;
        }
    }

    maior = matriz[0][0];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (matriz[i][j] > maior) {
                maior = matriz[i][j];
            }
        }
    }

    printf("===================================================");
    printf("\nMatriz 2D 5x5 com numeros sequenciais:\n"); //essa função imprime o array
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }

    printf("===================================================");
    printf("\nSoma de cada linha:\n");
    for (int i = 0; i < 5; i++) {
        int soma = 0;
        for (int j = 0; j < 5; j++) {
            soma += matriz[i][j];
        }
        printf("Linha %d: %d\n", i+1, soma);
    }
    printf("===================================================");
    printf("\nO maior numero na matriz e: %d\n", maior); //essa linha conversa com as de cima e mostra o maior numero do array

    return 0;
}
